#include "ProductsByUnit.h"

ProductsByUnit::ProductsByUnit(const MyString& name, const Category& category, double price, int quantity)
    : Product(name, category, price), quantity(quantity) {}

double ProductsByUnit::getwhatsleft() const {
    return quantity + 0.00;
}

void ProductsByUnit::setQuantity(int quantity) {
    this->quantity = quantity;
}

void ProductsByUnit::print() const {
    std::cout << getName() << " : " << getPrice() << " : " << quantity << "\n";
}

MyString ProductsByUnit::getType() const {
    return "by_unit";
}

bool ProductsByUnit::restock(int quantitytt) {
    if (quantitytt > 0) {
        quantity += quantitytt;
        return true;
    }
    else {
        if (quantity < -(quantitytt)) {
            std::cout << "Not enough left!\n";
            return false;
        }
        else {
            quantity += quantitytt;
            return true;
        }
    }
}