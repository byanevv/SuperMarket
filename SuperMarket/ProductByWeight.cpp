#include "ProductsByWeight.h"

ProductsByWeight::ProductsByWeight(const MyString& name, const Category& category, double price, double kilos)
    : Product(name, category, price), kilos(kilos) {}

double ProductsByWeight::getwhatsleft() const {
    return kilos;
}

void ProductsByWeight::setKilos(double kilos) {
    this->kilos = kilos;
}

void ProductsByWeight::print() const {
    std::cout << getName() << " : " << getPrice() << "/kg : " << kilos << "\n";
}

MyString ProductsByWeight::getType() const {
    return "by_weight";
}

bool ProductsByWeight::restock(int quantitytt) {
    if (quantitytt > 0) {
        kilos += quantitytt;
        return true;
    }
    else {
        if (kilos < -(quantitytt)) {
            std::cout << "Not enough left!\n";
            return false;
        }
        else {
            kilos += quantitytt;
            return true;
        }
    }
}