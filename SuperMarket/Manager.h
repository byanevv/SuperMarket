#pragma once

#include "Worker.h"

class Manager : public Worker {
private:
    char specialCode[9]; 
    void generateSpecialCode();
    void saveCodeToFile();

public:
    Manager(const MyString& firstName, const MyString& lastName,
        const MyString& phoneNumber, int age, const MyString& password);

    const char* getSpecialCode() const override;
    MyString getRole() const override;
    void print() const override;
};
