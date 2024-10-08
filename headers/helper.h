/**
 * @file helper.h
 * @brief Utility functions for the Library Management System
 *
 * This class provides helper functions for various operations such as
 * user input, member validation, and file updates.
 */
#pragma once

//Header Section
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>
#include "./books.h"
#include "members.h"
using namespace std;

class HelperFunctions {
    private:
    string memberId, bookId;
    public:
        void promptUser();
        void checkMember();
        string getMemberId() {
            return memberId;
        }
        string getBookId() {
            return bookId;
        } 
        void updateFile(Books *books, int booksFileSize);
        void updateTranscationRecord(Books book, string type);
};

// HelperFunctions Implementation
void HelperFunctions::promptUser() {
    cout << endl << "Member Id ?: ";
    cin >> this->memberId;
    cout << "Book Id ?: ";
    cin >> this->bookId;
}

void HelperFunctions::checkMember() {
    string text;
    bool foundUser= false;
     try {
        ifstream ReadFile("./files/members.txt");
        if(!ReadFile.is_open()) {
            throw 0;
        }
        while(getline(ReadFile, text)) {     
            istringstream iss(text); 
            string token, memberId;
            getline(iss, token, ':');
            getline(iss, memberId , ',');
            if(this->memberId == memberId) {
                foundUser = true;   
            }
        }
        if(!foundUser) {
            throw 1;
        }
        ReadFile.close();    
    } catch(int errNum) {
        switch (errNum) {
            case 0:
                cout << "An error occurred : Unable to open file";
                break;
            case 1:
                cout << "user with member id " << this->memberId << " doesn't exits";
                break;
            default:
                cout << "An Unknow Error occurred";
                break;
        }
    }
}

void HelperFunctions::updateFile(Books *books, int booksFileSize) {
    try {
        ofstream File("./files/books.txt");
        if(!File.is_open()) {
            throw 0;
        }
        for(int i = 0; i < booksFileSize; i++) {
             File << "{bookId:" << books[i].getBookId() << ", title:" << books[i].getBookTitle() << ", author:" << books[i].getBookAuthor() << ", published year:" << books[i].getPublicationYear() << ", isBorrowed:" << books[i].getIsBookBorrowed() << ",}" << endl;
        }
        File.close();
        cout << "File name books.txt Updated Successfully" << endl;
    } catch(int errNum) {
        switch(errNum) {
            case 0:
                cout << "Error: Unable to open file.";
                break;
        }
    }
}

void HelperFunctions::updateTranscationRecord(Books book, string type) {
    time_t timestamp;
    time(&timestamp);

    try {
        ofstream File("./files/history.txt", ios::app);
        if(!File.is_open()) {
            throw 0;
        }

        // Convert timestamp to string and remove newline character
        string timeStr = ctime(&timestamp);
        timeStr.pop_back();  // Remove the newline character at the end

        File << "memberId:" << memberId 
             << ", bookId:" << book.getBookId() 
             << ", bookTitle:" << book.getBookTitle() 
             << ", transcation_type:" << type 
             << ", date:" << timeStr << "," << endl;

        File.close();
        cout << "Transaction added to history." << endl;
    } catch(...) {
        cout << "Error: Unable to open file." << endl;
    }
}
