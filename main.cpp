#include <iostream>
#include <string>
#include "Character.h"
#include "Doctor.h"
#include "Knight.h"
#include "Mage.h"
#include <fstream>

//using namespace std;
void displayMenu();
void saveFile(Character *chars);
void createCharacter(Character *chars);
void viewCharacters(Character *chars);
void deleteCharacter(Character *chars);
void train(Character *chars);
void battle(Character *chars);
void loadFile(Character *chars);
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
                        Doctor doctor;
                        int healedHealth = doctor.Heal();
                        characters[i].setHealth(healedHealth);
                        std::cout << name << " has been healed! New health: " << characters[i].getHealth() << std::endl;
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
    std::cout << "Enter the index of the character to delete (1-" << MAX << "): ";
    int index;
    std::cin >> index;
    if (index < 1 || index > MAX)
    {
        std::cout << "Invalid index. Please try again." << std::endl;
        return;
    }
    if (chars[index - 1].getName().empty())
    {
        std::cout << "No character found at this index." << std::endl;
        return;
    }
    chars[index - 1] = Character(); // Reset the character at the specified index
    std::cout << "Character deleted successfully." << std::endl;
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
            if (!chars[i].getName().empty())
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
    bool found = false;
    for (int i = 0; i < MAX; i++)
    {
        if (chars[i].getName() == name)
        {
            found = true;
            std::cout << name << " trained!" << std::endl;
            int currentLevel = chars[i].getLevel();
            chars[i].setLevel(currentLevel + 1);
            std::cout << name << " is now level " << chars[i].getLevel() << std::endl;
            int currentHealth = chars[i].getHealth();
            chars[i].setHealth(currentHealth + 10);
            std::cout << name << "'s health increased to " << chars[i].getHealth() << std::endl;
            int currentAttackPower = chars[i].getAttackPower();
            chars[i].setAttackPower(currentAttackPower + 5);
            std::cout << name << "'s attack power increased to " << chars[i].getAttackPower() << std::endl;
            int currentDefense = chars[i].getDefense();
            chars[i].setDefense(currentDefense + 3);
            std::cout << name << "'s defense increased to " << chars[i].getDefense() << std::endl;
            break;
        }
    }
    if (!found)
    {
        std::cout << "Character not found." << std::endl;
    }
}

void battle(Character *chars)
{
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
                    // Implement battle logic here
                    chars[i].specialSkill(chars[j]); // Call the special skill of the player's character
                    chars[j].specialSkill(chars[i]); // Call the special skill of the opponent's character
                    break;
                }
            }
            // Implement battle logic here
            break;
        }
    }
    if (!found)
    {
        std::cout << "Character not found." << std::endl;
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