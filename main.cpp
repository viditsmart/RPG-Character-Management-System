#include <iostream>

//using namespace std;
void displayMenu();

int main()
{
    int option;
    displayMenu();
    std::cin >> option;


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