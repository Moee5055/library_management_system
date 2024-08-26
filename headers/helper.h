#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
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
};

void HelperFunctions::promptUser() {
    cout << "Your Member Id ? : ";
    cin >> this->memberId;
    cout << "Book Id ? : ";
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
