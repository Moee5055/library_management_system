#pragma once

#include <iostream>
#include "./libraryFunction.h"

//Menu Definition
class Menu {
    private:
        int choice;
        void promptChoice();
        void handleChoice();
    public:
        void displayMenu(std::string *arr, int num);
};

void Menu::promptChoice() {
    std::cout << "Choose your option: ";
    std::cin >> choice;
}

void Menu::handleChoice() {
    switch(choice) {
        case 1:
            //do something;
            break;
        case 2:
            //do something;
            break;
        case 3:
            //do something;
            break;
        case 4:
            //do something;
            break;
        case 5:
            break;
        case 6:
            break;
        default:
            std::cout << "Invalid choice";
            break;
    }
}

void Menu::displayMenu(std::string *arr, int num) {
    for (int i = 0; i < num; i++) {
        std::cout << (i + 1) << ". " << arr[i] << std::endl; 
    }
    promptChoice();
    handleChoice();
}
