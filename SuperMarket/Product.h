#pragma once

#include "MyString.h"
#include "Category.h"

class Product {
private:
    MyString name;
    Category category;
    double price;
    static int nextId;
    int id;

public:
    Product() = default;
    Product(const MyString& name, const Category& category, double price);
    virtual ~Product() = default;

    MyString getName() const;
    Category getCategory() const;
    double getPrice() const;
    int getId() const;

    void setName(const MyString& name);
    void setCategory(const Category& category);
    void setPrice(double price);
    virtual void print() const ;
    virtual void restock(int quantity) ;
};
