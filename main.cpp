#include <iostream>
#include <string>
#include "Character.h"
#include "Doctor.h"
#include "Knight.h"
#include "Mage.h"
#include <fstream>

//Member functions
const int MAX = 10;
void displayMenu();
int findCharacter(Character *chars[], int count, const std::string &name);
void saveFile(Character *chars[], int count);
void createCharacter(Character *chars[], int &count);
void viewCharacters(Character *chars[], int count);
void deleteCharacter(Character *chars[], int &count);
void train(Character *chars[], int count);
void battle(Character *chars[], int count);
void loadFile(Character *chars[], int &count);
void levelUp(Character *chars[], int index);
int calculateDamage(Character *player1, Character *player2);
void sortCharactersByLevel(Character *chars[], int size);
void heal(Character *chars[], int count);



//Main function
int main()
{
    //Pointer array for storing characters
    Character* characters[MAX] = {nullptr}; // Pointer to hold the created character
    //this varaible is initialized for input from the user to choose the option from the menu
    int charCount = 0;
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
                createCharacter(characters, charCount);
                break; 
            }
            //If the user chooses 2, viewCharacters function is called
            case 2: 
            {
                // View Characters
                viewCharacters(characters, charCount);
                break; 
            }
            //If the user chooses 3, trainCharacter function is called
            case 3:
            {
                // Train Character
                train(characters, charCount);
                break; 
            }
            //If the user chooses 4, battle function is called
            case 4:
            {
                // Battle Simulation
                battle(characters, charCount);
                break; 
            }
            //if the user chooses 5, healCharacter function is called
            case 5:
            {
                //Heal Character
                heal(characters, charCount);
                break;
            }
            //If the user chooses 6, deleteCharacter function is called
            case 6:
            {
                //Delete character
                deleteCharacter(characters, charCount);
                break;
            }
            //if the user chooses 7, saveFile function is called
            case 7:
            {
                //Save game
                saveFile(characters, charCount);
                break;
            }
            //if the user chooses 8, loadFile function is called
            case 8:
            {
                //Load game
                loadFile(characters, charCount);
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
    for (int i = 0; i < charCount; i++)
    {
        delete characters[i]; // Free the allocated memory for characters
    }
    
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
    std::cout << "5. Heal Character" << std::endl;
    std::cout << "6. Delete Character" << std::endl;
    std::cout << "7. Save Game" << std::endl;
    std::cout << "8. Load Game" << std::endl;
    std::cout << "9. Exit" << std::endl << std::endl;
    std::cout << "Enter your choice: ";
}

int findCharacter(Character *chars[], int count, const std::string &name)
{
    //bool found = false;
    for (int i = 0; i < count; i++)
    {
        if (chars[i] != nullptr && chars[i]->getName() == name)
        {
            //std::cout << "Character found: " << chars[i].getName() << std::endl;
            return i;
        }
    }
   // std::cout << "Character not found." << std::endl;
    return -1;
}

//This function creates a new character based on the user's choice of character type (Knight, Mage, or Doctor). It prompts the user to enter a name for the character and initializes the character's attributes accordingly. The created character is stored in the provided array of characters.
void createCharacter(Character *chars[], int &count)
{
   // static int index = 0;
    if (count >= MAX)
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
            //Character *knight = new Knight();
            //knight->setName(name);
            chars[count] = new Knight();
        }
        else if (charOption == 2)
        {
            //Character *mage = new Mage();
            //mage->setName(name);
            chars[count] = new Mage();
        }
        else if (charOption == 3)
        {
            //Character *doctor = new Doctor();
            //doctor->setName(name);
            chars[count] = new Doctor();
        }
        else
        {
            std::cout << "Invalid option. Please try again." << std:: endl;
            return;
        }
        chars[count]->setName(name);
        count++;
    }

}

//This function displays the list of characters stored in the provided array. It sorts the characters by their level and prints their names, types, and levels to the console.  
void viewCharacters(Character *chars[], int count)
{
    sortCharactersByLevel(chars, count);
    std::cout << "List of Characters: " << std::endl;
    for (int i = 0; i < count; i++)
    {
        if (chars[i] != nullptr && !chars[i]->getName().empty())
        {
            std::cout << "Character " << i + 1 << ": " << chars[i]->getName() << std::endl;
            std::cout << "Type: " << chars[i]->getCharacterType() << std::endl;
            std::cout << "Level: " << chars[i]->getLevel() << std::endl;
        }
        else 
            continue;
    }
}

//This function deletes a character from the provided array based on the user's input. It prompts the user to enter the name of the character to delete, searches for the character in the array, and resets its attributes to default values if found. If the character is not found, it displays an appropriate message.
void deleteCharacter(Character *chars[], int &count)
{
    std::cout << "Enter the name of the character to delete: ";
    std::string name;
    std::cin.ignore(); // Clear the input buffer
    std::getline(std::cin, name);
    int charIndex = findCharacter(chars, count, name);
    if (charIndex != -1)
    {
        delete chars[charIndex];

        for (int i = charIndex; i < count - 1; i++)
        {
            chars[i] = chars[i+1];
        }
        chars[count - 1] = nullptr;
        count--;
        std::cout << "Character deleted successfully.\n";
    }
    else
    {
        std::cout << "Character not found. Deletion failed." << std::endl;
        return;
    }

}

//This function saves the current state of the game by writing character data to a file named "characters.txt". It sorts the characters by level and writes their attributes (name, type, level, health, attack power, defense, experience points, and status) to the file. If the file cannot be opened for writing, it displays an error message.
void saveFile(Character *chars[], int count)
{
    // Implement save game logic here
    // Example: Save character data to a file
    sortCharactersByLevel(chars, count);
    std::ofstream outFile("characters.txt");
    if (!outFile)
    {
        std::cout << "Error opening file for writing." << std::endl;
        return;
    }
    else
    {
        for (int i = 0; i < count; i++)
        {
            if (chars[i] != nullptr)
            {
                outFile << chars[i]->getName() << std::endl;
                outFile << chars[i]->getCharacterType() << std::endl;
                outFile << chars[i]->getLevel() << std::endl;
                outFile << chars[i]->getHealth() << std::endl;
                outFile << chars[i]->getAttackPower() << std::endl;
                outFile << chars[i]->getDefense() << std::endl;
                outFile << chars[i]->getExperiencePoints() << std::endl;
                outFile << chars[i]->getStatus() << std::endl;
                outFile << std::endl; // Add a blank line between characters for readability
            }
            else
            {
                continue;
            }
        }
        std::cout << "Game saved successfully." << std::endl;
        outFile.close();
    }
    
}

void train(Character *chars[], int count)
{
    std::cout << "Choose your character to train (Enter Character name): ";
    std::string name;
    std::cin.ignore(); // Clear the input buffer
    std::getline(std::cin, name);
    int charIndex = findCharacter(chars, count, name);
    if (charIndex != -1)
    {
        //levelUp(chars, charIndex);
        Character *c = chars[charIndex];
        std::cout << name << " has trained successfully." << std::endl;
        c->setLevel(c->getLevel() + 1);
        c->setAttackPower(c->getAttackPower() + 3);
        c->setDefense(c->getDefense() + 2);

        std::cout << "Level +1\n";
        std::cout << "Attack +3\n";
        std::cout << "Defense +2\n";
    }
    else
    {
        std::cout << "Character not found. Training failed." << std::endl;
    }
}

void battle(Character *chars[], int count)
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
    int index1 = findCharacter(chars, count, name);
    int index2 = findCharacter(chars, count, opponentName);
    bool player1turn = true;
    if (index1 != -1 && index2 != -1)
    {
        p1 = chars[index1];
        p2 = chars[index2];
        while (p1->getHealth() > 0 && p2->getHealth() > 0)
        {
            Character *attacker, *defender;
            if (player1turn)
            {
                attacker = p1;
                defender = p2;
            }
            else 
            {
                attacker = p2;
                defender = p1;
            }

            std::cout << attacker->getName() << " turn to choose ability:" << std::endl;
            std::cout << "1. Normal Attack\n";
            std::cout << "2. Special Skill\n";
            std::cout << "Choice: ";
            int choice;
            std::cin >> choice;
            std::cin.ignore();
            if (choice == 2)
            {
                attacker->specialSkill(*defender);
            }
            else
            {
                int damage1 = calculateDamage(attacker, defender);
                defender->setHealth(defender->getHealth() - damage1);
                std::cout << attacker->getName() << " attacks " << defender->getName() << " for " << damage1 << " damage!\n";
            }
            std::cout << p1->getName() << " HP: " << p1->getHealth() << "\n";
            std::cout << p2->getName() << " HP: " << p2->getHealth() << "\n";

            player1turn = !player1turn;   // switch turns
        }

        if (p2->getHealth() <= 0)
        {
            std::cout << p1->getName() << " has won the battle!\n";
            p1->setExperiencePoints(p1->getExperiencePoints() + 50);
            //p1->setStatus("Alive");
            p2->setStatus("Defeated");

            levelUp(chars, index1);
        }

        else if (p1->getHealth() <= 0)
        {
            std::cout << p2->getName() << " has won the battle!\n";
            p2->setExperiencePoints(p2->getExperiencePoints() + 50);
            //p2->setStatus("Alive");
            p1->setStatus("Defeated");

            levelUp(chars, index2);
        }

    }
    else if (index1 == -1)
    {
        std::cout << "Player 1 not found!\n";
        return;
    }
    else if (index2 == -1)
    {
        std::cout << "Player 2 not found!\n";
        return;
    }

    
}

void loadFile(Character *chars[], int &count)
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
        for (int i = 0; i < count; i++) 
        {
            delete chars[i];
            chars[i] = nullptr;
        }
        std::string name, classType;
        int level, health, attackPower, defense, experiencePoints;
        std::string status;
        count = 0;
        while (count < MAX && std::getline(inFile, name))
        {
            if (name.empty())
                continue;
            
            std::getline(inFile, classType);
            inFile >> level >> health >> attackPower >> defense >> experiencePoints;
            inFile.ignore(); // Ignore the newline character after reading integers
            std::getline(inFile, status);
            if (classType == "Knight")
            {
                chars[count] = new Knight();
            }
            else if (classType == "Mage")
            {
                chars[count] = new Mage();
            }
            else if (classType == "Doctor")
            {
                chars[count] = new Doctor();
            }
            else
            {
                std::cout << "Unknown character type in file: " << classType << std::endl;
                continue; // Skip to the next iteration if the character type is unknown
            }
            chars[count]->setName(name);
            chars[count]->setCharacterType(classType);
            chars[count]->setLevel(level);
            chars[count]->setHealth(health);
            chars[count]->setAttackPower(attackPower);
            chars[count]->setDefense(defense);
            chars[count]->setExperiencePoints(experiencePoints);
            chars[count]->setStatus(status);
            count++;
        }
        std::cout << "Game loaded successfully." << std::endl;
        inFile.close();
    }
}

void levelUp(Character *chars[], int index)
{
    if (index < 0 || index >= MAX)
    {
        std::cout << "Invalid character index." << std::endl;
        return; // Return an error code for invalid index
    }
    //We want to level up with experience points for the character at the given index
    int currentLevel = chars[index]->getLevel();
    int currentXP = chars[index]->getExperiencePoints();
    int currentAttackPowwer = chars[index]->getAttackPower();
    int currentDefense = chars[index]->getDefense();

    // Assuming that the experience points required for leveling up is 100 * currentLevel
    int xpRequired = 100 * currentLevel;
    if (currentXP >= xpRequired)
    {
        chars[index]->setLevel(currentLevel + 1);
        chars[index]->setExperiencePoints(currentXP - xpRequired); // Deduct the used experience
        chars[index]->setAttackPower(currentAttackPowwer + 3);
        chars[index]->setDefense(currentDefense + 2);
        std::cout << chars[index]->getName() << " has leveled up! Newlevel: " << chars[index]->getLevel() << std::endl;
        std::cout << "New Attack Power: " << chars[index]->getAttackPower();
        std::cout << "New Defense: " << chars[index]->getDefense();
    }
    else
    {
        std::cout << chars[index]->getName() << " does not have enough experience points to level up." << std::endl;
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
void sortCharactersByLevel(Character *chars[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (chars[j] == nullptr || chars[j+1] == nullptr)
                continue;
            if (chars[j]->getLevel() < chars[j + 1]->getLevel())
            {
                // Swap characters
                Character* temp = chars[j];
                chars[j] = chars[j + 1];
                chars[j + 1] = temp;
            }
        }
    }
}

void heal(Character *chars[], int count)
{
    std::cin.ignore();
    std::cout << "Choose doctor: ";
    std::string name;
    std::getline(std::cin, name);
    std::cin.ignore(); // Clear the input buffer
    std::cout << "Choose patient: ";
    std::string patientName;
    std::getline(std::cin, patientName);
    int doctorIndex = findCharacter(chars, MAX, name);
    int patientIndex = findCharacter(chars, MAX, patientName);

    if (doctorIndex != -1 && patientIndex != -1)
    {
        if (chars[doctorIndex]->getCharacterType() != "Doctor") 
        {
            std::cout << "That character is not a Doctor.\n";
            return;
        }

        Doctor* doc = static_cast<Doctor*>(chars[doctorIndex]);
        doc->Heal(*chars[patientIndex]);   // or whatever signature you gave Heal
        std::cout << patientName << " has been healed by " << name << "!" << std::endl;
    }
    if (doctorIndex == -1)
    {
        std::cout << "Doctor not found!" << std::endl;
        return;
    }
    if (patientIndex == -1)
    {
        std::cout << "Patient not found!" << std::endl;
        return;
    }
}