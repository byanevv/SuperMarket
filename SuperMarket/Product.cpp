#include "Product.h"

Product::Product(const MyString& name, const Category& category, double price)
    : name(name), category(category), price(price) {}

MyString Product::getName() const {
    return name;
}

Category Product::getCategory() const {
    return category;
}

double Product::getPrice() const {
    return price;
}

void Product::setName(const MyString& name) {
    this->name = name;
}

void Product::setCategory(const Category& category) {
    this->category = category;
}

void Product::setPrice(double price) {
    this->price = price;
}
