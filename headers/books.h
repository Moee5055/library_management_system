#pragma once

//Header Section
#include <iostream>
#include <fstream>
#include <string>

//Books Definiton
class Books {
private:
    std::string title, bookId, author, publicationYear;
    bool isBorrowed;

public:
    std::string getBookId();
    std::string getBookTitle();
    std::string getBookAuthor();
    std::string getPublicationYear();
    bool isBookBorrowed();
    void setBookId(std::string bookId);
    void setBookTitle(std::string title);
    void setBookAuthor(std::string author);
    void setPublicationYear(std::string year);
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

bool Books::isBookBorrowed() {
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

