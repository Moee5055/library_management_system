#pragma once

//Header Section
#include <iostream>
#include <fstream>
#include <string>

//Books Definiton
class Books {
private:
    std::string title, bookId, author, publicationYear;
    std::string isBorrowed;
public:
    std::string getBookId();
    std::string getBookTitle();
    std::string getBookAuthor();
    std::string getPublicationYear();
    std::string getIsBookBorrowed();
    void setBookId(std::string bookId);
    void setBookTitle(std::string title);
    void setBookAuthor(std::string author);
    void setPublicationYear(std::string year);
    void setIsBookBorrowed(std::string isBorrowed);
};

//Books Implementation Section

std::string Books::getBookId() { //get book id
    return bookId;
}

std::string Books::getBookAuthor() {  //get author name
    return author;
}

std::string Books::getBookTitle() { //return title of book
    return title;
}

std::string Books::getPublicationYear() {  //return publication year of the book
    return publicationYear;
}

std::string Books::getIsBookBorrowed() {
    return this->isBorrowed;
}

//set Implementation of Books
void Books::setBookId(std::string bookId) {
    this->bookId = bookId;
}

void Books::setBookTitle(std::string title) {
    this->title = title;
}

void Books::setBookAuthor(std::string author) {
    this->author = author;
}

void Books::setPublicationYear(std::string year) {
    this->publicationYear = year;
}

void Books::setIsBookBorrowed(std::string isBorrowed) { 
    this->isBorrowed = isBorrowed;
}

