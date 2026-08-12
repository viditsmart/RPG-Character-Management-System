#include <iostream>
#include <string>
#include "Character.h"
#include "Doctor.h"
#include "Knight.h"
#include "Mage.h"
#include <fstream>

//Member functions
bool findCharacter(Character *chars, const std::string &name);
void displayMenu();
void saveFile(Character *chars);
void createCharacter(Character *chars);
void viewCharacters(Character *chars);
void deleteCharacter(Character *chars);
void train(Character *chars);
void battle(Character *chars);
void loadFile(Character *chars);
void levelUp(Character *chars, int index);
int calculateDamage(Character *player1, Character *player2);
void sortCharactersByLevel(Character *chars, int size);
void heal(Character *chars);
const int MAX = 10;

//Main function
int main()
{
    //Pointer array for storing characters
    Character* characters = new Character[MAX]; // Pointer to hold the created character
    //this varaible is initialized for input from the user to choose the option from the menu
    int option;
    //displayMenu option called
    displayMenu();
    //input from the user for the option
    std::cin >> option;
    //loop until the user chooses 9 to exit the program
    while (option != 9)
    {
        //switch case for the option chosen by the user
        switch(option)
        {
            //If the user chooses 1, createCharacter function is called
            case 1: 
            {
                createCharacter(characters);
                break; 
            }
            //If the user chooses 2, viewCharacters function is called
            case 2: 
            {
                // View Characters
                viewCharacters(characters);
                break; 
            }
            //If the user chooses 3, trainCharacter function is called
            case 3:
            {
                // Train Character
                train(characters);
                break; 
            }
            //If the user chooses 4, battle function is called
            case 4:
            {
                // Battle Simulation
                battle(characters);
                break; 
            }
            //if the user chooses 5, healCharacter function is called
            case 5:
            {
                //Heal Character
                heal(characters);
                break;
            }
            //If the user chooses 6, deleteCharacter function is called
            case 6:
            {
                //Delete character
                deleteCharacter(characters);
                break;
            }
            //if the user chooses 7, saveFile function is called
            case 7:
            {
                //Save game
                saveFile(characters);
                break;
            }
            //if the user chooses 8, loadFile function is called
            case 8:
            {
                //Load game
                loadFile(characters);
                break;
            }
            //if the user chooses an invalid option, display this message
            default:
            {
                std::cout << "Invalid option. Please try again." << std::endl;
                break;
            }

        }
        displayMenu();
        std::cin >> option;
    }
    delete[] characters; // Free the allocated memory for characters
    std::cout << "Exiting the program." << std::endl;

    return 0;
}

//This function displays the game menu to the user and prompts them to choose an option. It provides options for creating characters, viewing characters, training characters, simulating battles, healing characters, deleting characters, saving the game, loading the game, and exiting the program.
void displayMenu()
{
    std::cout << "=========================" << std::endl;
    std::cout << "RPG CHARACTER MANAGER" << std::endl;
    std::cout << "=========================" << std::endl << std::endl;

    std::cout << "1. Create Character" << std::endl;
    std::cout << "2. View Characters" << std::endl;
    std::cout << "3. Train Character" << std::endl;
    std::cout << "4. Battle Simulation" << std::endl;
    std::cout << "5. Heal Character" << std::endl << std::endl;
    std::cout << "6. Delete Character" << std::endl;
    std::cout << "7. Save Game" << std::endl;
    std::cout << "8. Load Game" << std::endl;
    std::cout << "9. Exit" << std::endl << std::endl;
    std::cout << "Enter your choice: ";
}

//This function creates a new character based on the user's choice of character type (Knight, Mage, or Doctor). It prompts the user to enter a name for the character and initializes the character's attributes accordingly. The created character is stored in the provided array of characters.
void createCharacter(Character *chars)
{
    static int index = 0;
    if (index >= MAX)
    {
        std::cout << "Maximum number of characters reached." << std::endl;

    }
    else
    {
        int charOption;
        std::cout << "Choose the type of character to create: " << std::endl;
        std::cout << "1. Knight" << std::endl;
        std::cout << "2. Mage" << std::endl;
        std::cout << "3. Doctor" << std::endl;
        std::cin >> charOption;
        std::cin.ignore();
        std::string name;
        std::cout << "Enter character name: ";
        getline(std::cin, name);
        if (charOption == 1)
        {
            Character *knight = new Knight();
            knight->setName(name);
            chars[index] = *knight;
            index++;
        }
        else if (charOption == 2)
        {
            Character *mage = new Mage();
            mage->setName(name);
            chars[index] = *mage;
            index++;
        }
        else if (charOption == 3)
        {
            Character *doctor = new Doctor();
            doctor->setName(name);
            chars[index] = *doctor;
            index++;
        }
        else
        {
            std::cout << "Invalid option. Please try again." << std:: endl;
        }
    }

}

//This function displays the list of characters stored in the provided array. It sorts the characters by their level and prints their names, types, and levels to the console.  
void viewCharacters(Character *chars)
{
    sortCharactersByLevel(chars, MAX);
    std::cout << "List of Characters: " << std::endl;
    for (int i = 0; i < MAX; i++)
    {
        if (!chars[i].getName().empty())
        {
            std::cout << "Character " << i + 1 << ": " << chars[i].getName() << std::endl;
            std::cout << "Type: " << chars[i].getCharacterType() << std::endl;
            std::cout << "Level: " << chars[i].getLevel() << std::endl;
        }
    }
}

//This function deletes a character from the provided array based on the user's input. It prompts the user to enter the name of the character to delete, searches for the character in the array, and resets its attributes to default values if found. If the character is not found, it displays an appropriate message.
void deleteCharacter(Character *chars)
{
    std::cout << "Enter the name of the character to delete: ";
    std::string name;
    std::cin.ignore(); // Clear the input buffer
    std::getline(std::cin, name);
    findCharacter(chars, name);
    if (findCharacter(chars, name))
    {
        for (int i = 0; i < MAX; i++)
        {
            if (chars[i].getName() == name)
            {
                chars[i] = Character(); // Reset the character to default values
                std::cout << "Character " << name << " deleted successfully." << std::endl;
                break;
            }
        }
    }
    else
    {
        std::cout << "Character not found. Deletion failed." << std::endl;
    }

}

//This function saves the current state of the game by writing character data to a file named "characters.txt". It sorts the characters by level and writes their attributes (name, type, level, health, attack power, defense, experience points, and status) to the file. If the file cannot be opened for writing, it displays an error message.
void saveFile(Character *chars)
{
    // Implement save game logic here
    // Example: Save character data to a file
    sortCharactersByLevel(chars, MAX);
    std::ofstream outFile("characters.txt");
    if (!outFile)
    {
        std::cout << "Error opening file for writing." << std::endl;
        return;
    }
    else
    {
        for (int i = 0; i < MAX; i++)
        {
            if (chars != nullptr && !chars[i].getName().empty())
            {
                outFile << chars[i].getName() << std::endl;
                outFile << chars[i].getCharacterType() << std::endl;
                outFile << chars[i].getLevel() << std::endl;
                outFile << chars[i].getHealth() << std::endl;
                outFile << chars[i].getAttackPower() << std::endl;
                outFile << chars[i].getDefense() << std::endl;
                outFile << chars[i].getExperiencePoints() << std::endl;
                outFile << chars[i].getStatus() << std::endl;
                outFile << std::endl; // Add a blank line between characters for readability
            }
        }
        std::cout << "Game saved successfully." << std::endl;
        outFile.close();
    }
    
}

void train(Character *chars)
{
    std::cout << "Choose your character to train (Enter Character name): ";
    std::string name;
    std::cin.ignore(); // Clear the input buffer
    std::getline(std::cin, name);
    findCharacter(chars, name);
    if (findCharacter(chars, name))
    {
        for (int i = 0; i < MAX; i++)
        {
            if (chars[i].getName() == name)
            {
                
                std::cout << name << " trained." << std::endl;
                chars[i].setExperiencePoints(chars[i].getExperiencePoints() + 25);
                levelUp(chars, i);
            }
        }
    }
    else
    {
        std::cout << "Character not found. Training failed." << std::endl;
    }
}

void battle(Character *chars)
{
    Character *p1 = nullptr;
    Character *p2 = nullptr;
    std::cout << "Choose your character for battle (Enter Character name): ";
    std::string name;
    std::cin.ignore(); // Clear the input buffer
    std::getline(std::cin, name);
    std::cout << "Choose your opponent for battle (Enter Character name): ";
    std::string opponentName;
    std::getline(std::cin, opponentName);
    bool found = false;
    for (int i = 0; i < MAX; i++)
    {
        if (chars[i].getName() == name )
        {
            found = true;
            std::cout << name << " is ready for battle!" << std::endl;

            for (int j = 0; j < MAX; j++)
            {
                if (chars[j].getName() == opponentName)
                {
                    found = true;
                    std::cout << opponentName << " is ready for battle!" << std::endl;
                    p1 = &chars[i];
                    p2 = &chars[j];
                    while(p1->getHealth() > 0 && p2->getHealth() > 0)
                    {
                        std::cout << "Battle between " << name << " and " << opponentName << "!" << std::endl;
                        std::cout << name << "'s Health: " << p1->getHealth() << std::endl;
                        std::cout << opponentName << "'s Health: " << p2->getHealth() << std::endl;
                        std::cout << "------------------------" << std::endl;
                        // Implement battle logic here
                        // For example, you can call the specialSkill method of each character
                        int damageToP2 = calculateDamage(p1, p2);
                        p2->setHealth(p2->getHealth() - damageToP2);
                        std::cout << name << " attacks " << opponentName << " for " << damageToP2 << " damage!" << std::endl;
                        std::cout << opponentName << " has " << p2->getHealth() << " health remaining." << std::endl;
                        if (p2->getHealth() <= 0)
                        {
                            break;
                        }
                        int damageToP1 = calculateDamage(p2, p1);
                        p1->setHealth(p1->getHealth() - damageToP1);
                        std::cout << opponentName << " attacks " << name << " for " << damageToP1 << " damage!" << std::endl;
                        std::cout << name << " has " << p1->getHealth() << " health remaining." << std::endl;
                    }
                    
                    // Implement battle logic here
                    
                    break;
                }
            }
            break;
        }
    }
    if (!found)
    {   
        std::cout << "Character not found." << std::endl;
    }
    else if (p1->getHealth() <= 0)
    {
        std::cout << opponentName << " has won the battle!" << std::endl;
        p2->setExperiencePoints(p2->getExperiencePoints() + 50); // Award experience points to the winner
        p1->setStatus("Defeated");
        std::cout << name << " has been defeated!" << std::endl;
    }
    else if (p2->getHealth() <= 0)
    {
        std::cout << name << " has won the battle!" << std::endl;
        p1->setExperiencePoints(p1->getExperiencePoints() + 50); // Award experience points to the winner
        p2->setStatus("Defeated");
        std::cout << opponentName << " has been defeated!" << std::endl;
        
    }
}

void loadFile(Character *chars)
{
    // Implement load game logic here
    // Example: Load character data from a file
    std::ifstream inFile("characters.txt");
    if (!inFile)
    {
        std::cout << "Error opening file for reading." << std::endl;
        return;
    }
    else
    {
        std::string name, classType;
        int level, health, attackPower, defense, experiencePoints;
        std::string status;
        int i = 0;
        while (i < MAX && std::getline(inFile, classType))
        {
            std::getline(inFile, name);
            inFile >> level >> health >> attackPower >> defense >> experiencePoints;
            inFile.ignore(); // Ignore the newline character after reading integers
            std::getline(inFile, status);
            if (classType == "Knight")
            {
                chars[i] = Knight();
            }
            else if (classType == "Mage")
            {
                chars[i] = Mage();
            }
            else if (classType == "Doctor")
            {
                chars[i] = Doctor();
            }
            else
            {
                std::cout << "Unknown character type in file: " << classType << std::endl;
                continue; // Skip to the next iteration if the character type is unknown
            }
            chars[i].setName(name);
            chars[i].setCharacterType(classType);
            chars[i].setLevel(level);
            chars[i].setHealth(health);
            chars[i].setAttackPower(attackPower);
            chars[i].setDefense(defense);
            chars[i].setExperiencePoints(experiencePoints);
            chars[i].setStatus(status);
            i++;
        }
        std::cout << "Game loaded successfully." << std::endl;
        inFile.close();
    }
}


bool findCharacter(Character *chars, const std::string &name)
{
    //bool found = false;
    for (int i = 0; i < MAX; i++)
    {
        if (chars[i].getName() == name)
        {
            std::cout << "Character found: " << chars[i].getName() << std::endl;
            return true;
        }
    }
    std::cout << "Character not found." << std::endl;
    return false;
}

void levelUp(Character *chars, int index)
{
    if (index < 0 || index >= MAX)
    {
        std::cout << "Invalid character index." << std::endl;
        return; // Return an error code for invalid index
    }
    //We want to level up with experience points for the character at the given index
    int currentLevel = chars[index].getLevel();
    int currentXP = chars[index].getExperiencePoints();
    int currentAttackPowwer = chars[index].getAttackPower();
    int currentDefense = chars[index].getDefense();

    // Assuming that the experience points required for leveling up is 100 * currentLevel
    int xpRequired = 100 * currentLevel;
    if (currentXP >= xpRequired)
    {
        chars[index].setLevel(currentLevel + 1);
        chars[index].setExperiencePoints(currentXP - xpRequired); // Deduct the used experience
        chars[index].setAttackPower(currentAttackPowwer + 3);
        chars[index].setDefense(currentDefense + 2);

        std::cout << chars[index].getName() << " has leveled up! Newlevel: " << chars[index].getLevel() << std::endl;
        std::cout << "New Attack Power: " << chars[index].getAttackPower();
        std::cout << "New Defense: " << chars[index].getDefense();
    }
    else
    {
        std::cout << chars[index].getName() << " does not have enough experience points to level up." << std::endl;
    }

    //return chars[index].getLevel(); // Return the new level
}

int calculateDamage(Character *player1, Character *player2)
{
    if (player1 == nullptr || player2 == nullptr)
    {
        std::cout << "Invalid character pointers." << std::endl;
        return 0; // Return 0 damage for invalid characters
    }
    int attackPower = player1->getAttackPower();
    int defense = player2->getDefense();
    int damage = attackPower - (defense/2);
    if (damage < 0)
    {
        damage = 0; // Ensure that damage is not negative
    }
    return damage;
}

//This function sorts the characters in the provided array based on their level in descending order. It uses a simple bubble sort algorithm to compare the levels of characters and swap them if necessary. The sorted array allows for easier viewing and management of characters based on their levels.
void sortCharactersByLevel(Character *chars, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (chars[j].getLevel() < chars[j + 1].getLevel())
            {
                // Swap characters
                Character temp = chars[j];
                chars[j] = chars[j + 1];
                chars[j + 1] = temp;
            }
        }
    }
}

void heal(Character *chars)
{
    std::cout << "Choose doctor: ";
    std::string name;
    std::getline(std::cin, name);
    std::cin.ignore(); // Clear the input buffer
    std::cout << "Choose patient: ";
    std::string patientName;
    std::getline(std::cin, patientName);
    bool found = false;
    if (findCharacter(chars, name) && findCharacter(chars, patientName))
    {
        for (int i = 0; i < MAX; i++)
        {
            if (chars[i].getName() == name && chars[i].getCharacterType() == "Doctor")
            {
                found = true;
                for (int j = 0; j < MAX; j++)
                {
                    if (chars[j].getName() == patientName)
                    {
                        int newHealth = static_cast<Doctor*>(&chars[i])->Heal(chars[j]);
                        chars[j].setHealth(newHealth);
                        std::cout << patientName << " has been healed by " << name << "!" << std::endl;
                        break;
                    }
                }
                break;
            }
        }
    }
    if (!found)
    {
        std::cout << "Character not found." << std::endl;
    }  
}