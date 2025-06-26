#include "AllProductsGiftCard.h"

AllProductsGiftCard::AllProductsGiftCard( double discount)
    : GiftCard( discount) {}

bool AllProductsGiftCard::isApplicable(const MyString&) const {
    return true;
}

MyString AllProductsGiftCard::getName() const {
    return "AllProductsGiftCard";
}
const char* AllProductsGiftCard::getCode() const {
    return getcode();
}

void AllProductsGiftCard::print() const {
    std::cout << getDiscount() * 100 << "% applied to all products. Transaction completed!" << "\n";
}

MyString AllProductsGiftCard::printcategories() const {
    return  "All";
}