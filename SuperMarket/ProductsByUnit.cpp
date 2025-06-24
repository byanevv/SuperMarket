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
    std::cout << "     " << getName() << " : " << getPrice() << " : " << quantity << "\n";
}

void ProductsByUnit::restock(int quantitytt) {
    if (quantitytt > 0) {
        quantity += quantitytt;
    }
    else {
        if (quantity < quantitytt) {
            std::cout << "Not enough left!";
            
        }
        quantity -= quantitytt;

    }
}