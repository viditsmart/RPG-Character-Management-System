#include <iostream>
#include <string>
#include "Character.h"
#include "Doctor.h"
#include "Knight.h"
#include "Mage.h"
#include <fstream>

//using namespace std;
void displayMenu();
void saveGame(Character *chars);
void createCharacter(Character *chars);
void viewCharacters(Character *chars);
void deleteCharacter(Character *chars);
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
                break; 
            }
            case 4:
            {
                // Battle Simulation
                break; 
            }
            case 5:
            {
                //Heal Character
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
                saveGame(characters);
                break;
            }
            case 8:
            {
                //Load game
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

void saveGame(Character *chars)
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
    }
    outFile.close();
    std::cout << "Game saved successfully." << std::endl;
}