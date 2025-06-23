#include "ProductsByUnit.h"

ProductsByUnit::ProductsByUnit(const MyString& name, const Category& category, double price, int quantity)
    : Product(name, category, price), quantity(quantity) {}

int ProductsByUnit::getQuantity() const {
    return quantity;
}

void ProductsByUnit::setQuantity(int quantity) {
    this->quantity = quantity;
}

void ProductsByUnit::print() const {
    std::cout << name << " : " << price << " : " << quantity << "\n";
}