#include "AllProductsGiftCard.h"

AllProductsGiftCard::AllProductsGiftCard( double discount)
    : GiftCard( discount) {}

bool AllProductsGiftCard::isApplicable(const MyString&) const {
    return true;
}

MyString AllProductsGiftCard::getName() const {
    return "AllProductsGiftCard";
}

void AllProductsGiftCard::print() const {
    std::cout << discount * 100 << "% applied to all products. Transaction completed!" << "\n";
}