#include "Product.h"

int Product::nextId = 1;

Product::Product(const MyString& name, const Category& category, double price)
    : id(nextId++),name(name), category(category), price(price) {}

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

int Product::getId() const { return id; }

void Product::print() const {

}

void Product::restock(int quantity) {

}