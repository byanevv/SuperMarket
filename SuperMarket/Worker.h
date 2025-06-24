#pragma once

#include "MyString.h"

class Worker {
protected:
    static int nextId;
    int id;
    MyString firstName;
    MyString lastName;
    MyString phone;
    int age;
    MyString password;

public:
    Worker() = default;
    Worker(const MyString& firstName, const MyString& lastName,
        const MyString& phone, int age, const MyString& password);
    virtual ~Worker() = default;

    int getId() const;
    MyString getFirstName() const;
    MyString getLastName() const;
    MyString getPhone() const;
    int getAge() const;
    MyString getPassword() const;
    virtual MyString getRole() const = 0;
    virtual const char* getSpecialCode() const = 0;
    virtual void print() const = 0;

    virtual void addTransaction() = 0;

};