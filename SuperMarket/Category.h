#pragma once

#include "MyString.h"

class Category {
private:
    MyString name;
    MyString description;
    static int nextId;
    int id;

public:
    Category() = default;
    Category(const MyString& name, const MyString& description);
    MyString getName() const;
    MyString getDescription() const;
    void setName(const MyString& name);
    void setDescription(const MyString& description);
    int getId() const;
};