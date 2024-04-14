#include "SchoolManagementSystem.h"

int main() {
    PA3::SchoolManagementSystem system;

    int choice;
    std::cout << "Main Menu\n";
    do {
        system.displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        system.executeChoice(choice);
    } while (choice != 0);

    return 0;
}

