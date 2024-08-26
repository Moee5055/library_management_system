#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "./books.h"
#include "./helper.h"
#include "./members.h"
using namespace std;

class LibraryFunctions
{
    HelperFunctions helper;
    Books *books;
    Members *members;
    int booksFilesize;
    int membersFilesize;
public:
    LibraryFunctions();
    void LoadBooks();
    void LoadMembers();
    void addNewBooks();
    void addNewMembers();
    void borrowBook();
    void returnBook();
};

LibraryFunctions::LibraryFunctions()
{
    LoadBooks();
    LoadMembers();
}

void LibraryFunctions::LoadBooks()
{
    try
    {
        ifstream MyReadFile("./files/books.txt");

        if (!MyReadFile.is_open())
        {
            throw runtime_error("Unable to open file");
        }

        string text;
        while (getline(MyReadFile, text))
        {
            booksFilesize++;
        }

        MyReadFile.clear();  // Clear the EOF flag
        MyReadFile.seekg(0, ios::beg);  // Move the file pointer to the beginning

        books = new Books[booksFilesize];
        int index = 0;
        while (getline(MyReadFile, text))
        {
            Books book;
            if(text.size() > 0) {
                text = text.substr(1, text.length() - 2);
            }
            istringstream iss(text);
            string token, bookId, title, author, year, isBookBorrowed;
            getline(iss, token, ':');
            getline(iss, bookId, ',');
            book.setBookId(bookId);
            getline(iss, token, ':');
            getline(iss, title, ',');
            book.setBookTitle(title);
            getline(iss, token, ':');
            getline(iss, author, ',');
            book.setBookAuthor(author);
            getline(iss, token, ':');
            getline(iss, year, ',');
            book.setPublicationYear(year);
            getline(iss, isBookBorrowed, ':');
            getline(iss, isBookBorrowed, ',');
            book.setIsBookBorrowed(isBookBorrowed);
            books[index] = book;
            index++;
        }

        MyReadFile.close();
    }
    catch (const exception &e)
    {
        cerr << "Caught Exception: " << e.what() << std::endl;
    }
}

void LibraryFunctions::LoadMembers()
{
    try
    {
        ifstream MyReadFile("./files/members.txt");

        if (!MyReadFile.is_open())
        {
            throw runtime_error("Unable to open file");
        }

        string membersData;
        while (getline(MyReadFile, membersData))
        {
            membersFilesize++;
        }

        MyReadFile.clear();  // Clear the EOF flag
        MyReadFile.seekg(0, ios::beg);  // Move the file pointer to the beginning

        members = new Members[membersFilesize];
        int index = 0;
        while (getline(MyReadFile, membersData))
        {
            Members member;
            if(membersData.size() >= 1) {
                membersData = membersData.substr(1, membersData.length() - 2);
            }
            istringstream iss(membersData);
            string token, memberId, name, contact;
            getline(iss, token, ':');
            getline(iss, memberId, ',');
            member.setMemberId(memberId);
            getline(iss, token, ':');
            getline(iss, name, ',');
            member.setMemberName(name);
            getline(iss, token, ':');
            getline(iss, contact, ',');
            member.setContactInformation(contact);
            *(books + index);
            index++;
        }

        MyReadFile.close();
    }
    catch (const exception &e)
    {
        cerr << "Caught Exception: " << e.what() << std::endl;
    }
}

void LibraryFunctions::addNewBooks()
{
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

    try
    {
        ofstream MyFile;
        MyFile.open("./files/books.txt", ios::app);
        if (!MyFile.is_open())
        {
            throw runtime_error("Failed to open file");
        }
        MyFile << "{bookId:" << id << ", title:" << title << ", author:" << author << ", published year:" << year << ", isBorrowed:" << "false" << ",}" << endl;
        MyFile.close();
    }
    catch (const exception &e)
    {
        cerr << "An error occurred: " << e.what() << endl;
    }
}

void LibraryFunctions::addNewMembers()
{
    string name, contact, id;
    cout << "Member Id : ";
    cin >> id;
    cin.ignore();
    cout << "Member Name : ";
    getline(cin, name);
    cout << "Contact Information : ";
    cin >> contact;
    try
    {
        ofstream MyFile;
        MyFile.open("./files/members.txt", ios::app);
        if (!MyFile.is_open())
        {
            throw runtime_error("Failed to open file");
        }
        MyFile << "{memberId:" << id << ", memberName:" << name << ", Contact Information:" << contact << ",}" << endl;
        MyFile.close();
    }
    catch (const exception &e)
    {
        cerr << "An error occurred: " << e.what() << endl;
    }
}

void LibraryFunctions::borrowBook()
{
    helper.promptUser();
    helper.checkMember();  
    try {
        bool isBookThere = false;
        for(int i = 0; i < booksFilesize; i++) {
            string bookId = books[i].getBookId();
            if(bookId == helper.getBookId()) {
                isBookThere = true;
            }
            if(isBookThere) {
                if(books[i].getIsBookBorrowed() == "true") {
                    throw 2;
                }    
                books[i].setIsBookBorrowed("true");
                cout << "Okay, book is available. you can borrow now." << endl;
                cout << "You have successfully borrowed book name '" << books[i].getBookTitle() << "'." << endl;
                helper.updateFile(books, booksFilesize);
                helper.updateTranscationRecord(books[i], "borrowed");
            }
        }
        if(!isBookThere) {
            throw 1;
        }
    } catch(int errNum) {
        switch(errNum) {
            case 1:
                cout << "Error: Unknow book reference";
                break;
            case 2:
                cout << "Oops!, Book is not Available right now.";
                break;
        }
    }
}

void LibraryFunctions::returnBook() {
    helper.promptUser();
    helper.checkMember();
    try {
        bool isBookMatched = false;
        for(int i = 0; i < booksFilesize; i++) {
            if(books[i].getBookId() == helper.getBookId()) {
                books[i].setIsBookBorrowed("false");
                cout << "Successfully received your book" << endl;
                helper.updateFile(books, booksFilesize);
                helper.updateTranscationRecord(books[i],"returned");
                isBookMatched = true;
            }
        }
        if(!isBookMatched) {
             throw 1;
        }
        
    }catch(...) {
         cout << "Invalid Book Id"; 
    }
}