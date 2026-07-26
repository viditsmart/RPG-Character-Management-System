#include <iostream>
#include <string>

//using namespace std;
void displayMenu();
void createCharacter();

int main()
{
    int option;
    displayMenu();
    std::cin >> option;
    switch(option)
    {
        case 1: 
        {

        }
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

void createCharacter()
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

}