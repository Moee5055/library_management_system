#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "books.h"
using namespace std;

class LibraryFunctions {
    private:
    string memberId, bookId;
    void promptUser();
    public:
        // LibraryFunctions();
        void addNewBooks();
        void addNewMembers();
        void borrowBook();
};

// LibraryFunctions::LibraryFunctions() {
//      try
//     {
//         ifstream MyReadFile("./files/books.txt");
        
//         if (!MyReadFile.is_open()) {
//             throw runtime_error("Unable to open file");
//         }
        
//         while(getline(MyReadFile, text)) {
//             cout << text << endl;
//         }

//         MyReadFile.close();
//     }
//     catch (const exception& e)
//     {
//         cerr << "Caught Exception: " << e.what() << std::endl;
//     }
// }

void LibraryFunctions::addNewBooks() {
    string author, title, year, id;
    cout << "Book Id : ";
    cin >> id;
    cin.ignore();
    cout << "Book Author : ";
    getline(cin, author);
    cout << "Book Title : ";
    getline(cin, title);
    cout << "Published Year : ";
    cin >> year;

    try {
        ofstream MyFile;
        MyFile.open("./files/books.txt", ios::app);
        if(!MyFile.is_open()) {
            throw runtime_error("Failed to open file");
        }
        MyFile << "{bookId:" << id << ", title: " << title << ", author: " << author << ", published year: " << year << ", isBorrowed: " << "false" <<"}" << endl;
        MyFile.close();
    } catch(const exception& e) {
        cerr << "An error occurred: " << e.what() << endl;
    }
}

void LibraryFunctions::addNewMembers() {
    string name, contact, id;
    cout << "Member Id : ";
    cin >> id;
    cin.ignore();
    cout << "Member Name : ";
    getline(cin, name);
    cout << "Contact Information : ";
    cin >> contact;
    try {
        ofstream MyFile;
        MyFile.open("./files/members.txt", ios::app);
        if(!MyFile.is_open()) {
            throw runtime_error("Failed to open file");
        }
        MyFile << "{memberId:" << id << ", memberName: " << name << ", Contact Information: " << contact << "}" << endl;
        MyFile.close();
    }catch(const exception& e) {
        cerr << "An error occurred: " << e.what() << endl;
    }
}

void LibraryFunctions::promptUser() {
    cout << "Your Member Id ? : ";
    cin >> this->memberId;
    cout << "Book Id ? : ";
    cin >> this->bookId;
}

void LibraryFunctions::borrowBook() {
    string text;
    promptUser();
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
                cout << "user exits";
            } else {
                cout << this->memberId << memberId;
            }
        }

    } catch(int errNum) {
        switch (errNum) {
            case 0:
                cout << "An error occurred : Unable to open file";
                break;
            default:
                cout << "An Unknow Error occurred";
                break;
        }
    }
}
