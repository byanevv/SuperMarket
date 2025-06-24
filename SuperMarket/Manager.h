#pragma once

#include "Worker.h"
#include "MyString.h"

class Manager : public Worker {
private:
    char specialCode[9]; 
    void generateSpecialCode();
    void saveCodeToFile();

public:
    Manager() = default;
    Manager(const MyString& firstName, const MyString& lastName,
        const MyString& phoneNumber, int age, const MyString& password);
    ~Manager();

    const char* getSpecialCode() const override;
    MyString getRole() const override;
    void print() const override;
    void addTransaction() override;
};
