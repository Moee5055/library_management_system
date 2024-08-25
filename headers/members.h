#pragma once

//Header Section
#include <iostream>

//Members definiton
class Members {
    private:
        int memberId;
        std::string name;
        std::string contactInformation;
    public:
        int getMemberId();
        std::string getName();
        std::string getContactInformation();
};

//Members Implementation
int Members::getMemberId() {
    return memberId;
}

std::string Members::getContactInformation() {
    return contactInformation;
}

std::string Members::getName() {
    return name;
}

