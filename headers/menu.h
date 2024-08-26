#pragma once

#include <iostream>
#include "./libraryFunction.h"

//Menu Definition
class Menu {
    private:
        int choice;
        void promptChoice();
        void handleChoice();
        LibraryFunctions libraryFunction;
    public:
        void displayMenu(std::string *arr, int num);
};

void Menu::promptChoice() {
    std::cout << "\nChoose your option: ";
    std::cin >> choice;
}

void Menu::handleChoice() {
    switch(choice) {
        case 1:
            libraryFunction.addNewBooks();
            break;
        case 2:
            libraryFunction.addNewMembers();
            break;
        case 3:
            libraryFunction.borrowBook();
            break;
        case 4:
            libraryFunction.returnBook();
            break;
        case 5:
        libraryFunction.viewMemberBorrowingHistory();
            break;
        case 6:
            std::cout << endl << "Exiting Program....";
            exit(1);
        default:
            std::cout << "\nInvalid choice";
            exit(1);
    }
}

void Menu::displayMenu(std::string *arr, int num) {
    cout << "\t\t\t\tWelcome to One Piece Library" << endl << endl;
    cout << "Read carefully and Select the operation : " << endl << endl;
    for (int i = 0; i < num; i++) {
        std::cout << (i + 1) << ". " << arr[i] << std::endl; 
    }
    promptChoice();
    handleChoice();
}
