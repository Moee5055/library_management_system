#pragma once

//Header Section
#include <iostream>
#include <fstream>
#include <string>

//Books Definiton
class Books {
private:
    int bookId;
    std::string title;
    std::string author;
    int publicationYear;

public:
    Books();
    int getBookId();
    std::string getTitle();
    std::string getAuthor();
    int getPublicationYear();
};

//Books Implementation Section
Books::Books() {   //default constructor
    try
    {
        std::ifstream MyReadFile("./files/welcome.txt");
        
        if (!MyReadFile.is_open()) {
            throw std::runtime_error("Unable to open file");
        }
        
        while (getline(MyReadFile, this->author))
        {
            std::cout << this->author << std::endl;
        }
        MyReadFile.close();
    }
    catch (const std::exception& e)
    {
        std::cerr << "Caught Exception: " << e.what() << std::endl;
    }
}

int Books::getBookId() { //get book id
    return bookId;
}

std::string Books::getAuthor() {  //get author name
    return author;
}

std::string Books::getTitle() { //return title of book
    return title;
}

int Books::getPublicationYear() {  //return publication year of the book
    return publicationYear;
}


