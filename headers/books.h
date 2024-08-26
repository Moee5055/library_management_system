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
    bool isBorrowed;

public:
    int getBookId();
    std::string getBookTitle();
    std::string getBookAuthor();
    int getPublicationYear();
    void setBookId(int bookId);
    void setBookTitle(std::string title);
    void setBookAuthor(std::string author);
    void setPublicationYear(int year);
};

//Books Implementation Section

int Books::getBookId() { //get book id
    return bookId;
}

std::string Books::getBookAuthor() {  //get author name
    return author;
}

std::string Books::getBookTitle() { //return title of book
    return title;
}

int Books::getPublicationYear() {  //return publication year of the book
    return publicationYear;
}

//set Implementation of Books
void Books::setBookId(int bookId) {
    this->bookId = bookId;
}

void Books::setBookTitle(std::string title) {
    this->title = title;
}

void Books::setBookAuthor(std::string author) {
    this->author = author;
}

void Books::setPublicationYear(int year) {
    this->publicationYear = year;
}

