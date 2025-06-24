#include "Category.h"

int Category::nextId = 1;

Category::Category(const MyString& name, const MyString& description)
    : id(nextId++), name(name), description(description) {}

MyString Category::getName() const {
    return name;
}

MyString Category::getDescription() const {
    return description;
}

void Category::setName(const MyString& name) {
    this->name = name;
}

void Category::setDescription(const MyString& description) {
    this->description = description;
}

int Category::getId() const { return id; }