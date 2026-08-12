#include <iostream>
#include <string>
#include "Character.h"
#include "Doctor.h"
#include "Knight.h"
#include "Mage.h"
#include <fstream>

//using namespace std;
bool findCharacter(Character *chars, const std::string &name);
void displayMenu();
void saveFile(Character *chars);
void createCharacter(Character *chars);
void viewCharacters(Character *chars);
void deleteCharacter(Character *chars);
void train(Character *chars);
void battle(Character *chars);
void loadFile(Character *chars);
int levelUp(Character *chars, int index);
int calculateDamage(Character *player1, Character *player2);
void sortCharactersByLevel(Character *chars, int size);
const int MAX = 10;

int main()
{
    Character* characters = new Character[MAX]; // Pointer to hold the created character
    int option;
    //int i = 0;
    displayMenu();
    std::cin >> option;
    while (option != 9)
    {
        switch(option)
        {
            case 1: 
            {
                createCharacter(characters);
                break; 
            }
            case 2: 
            {
                // View Characters
                viewCharacters(characters);
                break; 
            }
            case 3:
            {
                // Train Character
                train(characters);
                break; 
            }
            case 4:
            {
                // Battle Simulation
                battle(characters);
                break; 
            }
            case 5:
            {
                //Heal Character
                std::cout << "Choose your character to heal (Enter Character name): ";
                std::string name;
                std::cin.ignore(); // Clear the input buffer
                std::getline(std::cin, name);
                bool found = false;
                for (int i = 0; i < MAX; i++)
                {
                    if (characters[i].getName() == name)
                    {
                        found = true;
                        Doctor *doctor = dynamic_cast<Doctor*>(&characters[i]); // Cast the character to Doctor
                        if (doctor != nullptr)
                        {
                            int healedHealth = doctor->Heal();
                            characters[i].setHealth(healedHealth);
                            std::cout << name << " has been healed! New health: " << characters[i].getHealth() << std::endl;
                        }
                        else
                        {
                            std::cout << name << " is not a Doctor and cannot heal." << std::endl;
                        }
                        
                        break;
                    }
                }
                if (!found)
                {
                    std::cout << "Character not found." << std::endl;
                }   
                break;
            }
            case 6:
            {
                //Delete character
                deleteCharacter(characters);
                break;
            }
            case 7:
            {
                //Save game
                saveFile(characters);
                break;
            }
            case 8:
            {
                //Load game
                loadFile(characters);
                break;
            }
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

void viewCharacters(Character *chars)
{
    std::cout << "List of Characters: " << std::endl;
    for (int i = 0; i < MAX; i++)
    {
        if (!chars[i].getName().empty())
        {
            std::cout << "Character " << i + 1 << ": " << chars[i].getName() << std::endl;
            std::cout << "Level: " << chars[i].getLevel() << std::endl;
        }
    }
}

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

void saveFile(Character *chars)
{
    // Implement save game logic here
    // Example: Save character data to a file
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
                outFile << chars[i].getLevel() << std::endl;
                outFile << chars[i].getHealth() << std::endl;
                outFile << chars[i].getAttackPower() << std::endl;
                outFile << chars[i].getDefense() << std::endl;
                outFile << chars[i].getExperiencePoints() << std::endl;
                outFile << chars[i].getStatus() << std::endl;
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
                int newLevel = levelUp(chars, i);
                if (newLevel == chars[i].getLevel())
                {
                    std::cout << name << " does not have enough experience points to level up." << std::endl;
                }
                else
                {
                    std::cout << name << " has leveled up! New level: " << newLevel << std::endl;
                }
                break;
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
        for (int i = 0; i < MAX; i++)
        {
            std::string name;
            int level, health, attackPower, defense, experiencePoints;
            std::string status;
            if (std::getline(inFile, name))
            {
                inFile >> level >> health >> attackPower >> defense >> experiencePoints;
                inFile.ignore(); // Ignore the newline character after reading integers
                std::getline(inFile, status);
                chars[i].setName(name);
                chars[i].setLevel(level);
                chars[i].setHealth(health);
                chars[i].setAttackPower(attackPower);
                chars[i].setDefense(defense);
                chars[i].setExperiencePoints(experiencePoints);
                chars[i].setStatus(status);
            }
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

int levelUp(Character *chars, int index)
{
    if (index < 0 || index >= MAX)
    {
        std::cout << "Invalid character index." << std::endl;
        return -1; // Return an error code for invalid index
    }
    //We want to level up with experience points for the character at the given index
    int currentLevel = chars[index].getLevel();
    int currentXP = chars[index].getExperiencePoints();
    // Assuming that the experience points required for leveling up is 100 * currentLevel
    int xpRequired = 100 * currentLevel;
    if (currentXP >= xpRequired)
    {
        chars[index].setLevel(currentLevel + 1);
        chars[index].setExperiencePoints(currentXP - xpRequired); // Deduct the used experience
        std::cout << chars[index].getName() << " has leveled up! Newlevel: " << chars[index].getLevel() << std::endl;
    }
    else
    {
        std::cout << chars[index].getName() << " does not have enough experience points to level up." << std::endl;
    }

    return chars[index].getLevel(); // Return the new level
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