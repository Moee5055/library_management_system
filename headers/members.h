#pragma once

//Header Section
#include <iostream>

//Members definiton
class Members {
    private:
         std::string memberId, name, contactInformation;
    public:
        std::string getMemberId();
        std::string getName();
        std::string getContactInformation();
        void setMemberId(std::string memberId);
        void setMemberName(std::string name);
        void setContactInformation(std::string contact);
};

//Members Implementation
std::string Members::getMemberId() {
    return memberId;
}

std::string Members::getContactInformation() {
    return contactInformation;
}

std::string Members::getName() {
    return name;
}

void Members::setMemberId(std::string memberId) {
    this->memberId = memberId;
}

void Members::setMemberName(std::string name) {
    this->name = name;
}

void Members::setContactInformation(std::string contact) {
    this->contactInformation = contact;
}