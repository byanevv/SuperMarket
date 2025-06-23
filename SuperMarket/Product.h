#pragma once

#include "MyString.h"
#include "Category.h"

class Product {
protected:
    MyString name;
    Category category;
    double price;

public:
    Product(const MyString& name, const Category& category, double price);
    virtual ~Product() = default;

    MyString getName() const;
    Category getCategory() const;
    double getPrice() const;

    void setName(const MyString& name);
    void setCategory(const Category& category);
    void setPrice(double price);
    virtual void print() const = 0;
};
