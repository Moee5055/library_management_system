#include <iostream>
#include "./headers/menu.h"

int main() {
    std::string arr[6] = {"Add a new book to the library", "Add a new member to the library", "Borrow a book", "Return an book", "View member's book history", "Exit the program"};
    Menu m1;
    m1.displayMenu(arr, 6);
    return 0;
}
