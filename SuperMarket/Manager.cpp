#include "Manager.h"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "MyString.h"

Manager::Manager(const MyString& firstName, const MyString& lastName,const MyString& phoneNumber, int age, const MyString& password)
    : Worker(firstName, lastName, phoneNumber, age, password) {
    std::srand(std::time(nullptr)); 
    generateSpecialCode();
    saveCodeToFile();
}

void Manager::generateSpecialCode() {
    specialCode[0] = '0' + rand() % 10;
    specialCode[1] = 'A' + rand() % 26;
    specialCode[2] = 'A' + rand() % 26;
    specialCode[3] = '0' + rand() % 10;
    specialCode[4] = '0' + rand() % 10;
    specialCode[5] = '0' + rand() % 10;
    specialCode[6] = '0' + rand() % 10;
    specialCode[7] = 'a' + rand() % 26;
    specialCode[8] = '\0';
}

void Manager::saveCodeToFile() {

    MyString idstr = MyString(id);
    MyString fileName = idstr + "_special_code.txt";

    std::ofstream outFile(fileName.c_str());
    if (outFile.is_open()) {
        outFile << specialCode;
        outFile.close();
    }
}

const char* Manager::getSpecialCode() const {
    return specialCode;
}

MyString Manager::getRole() const {
    return "Manager";
}

void Manager::print() const {
    std::cout << firstName << " " << lastName << " with id " << id <<  " and phone number : " << phone << "\n";
}