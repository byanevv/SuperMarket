#include "SingleCategoryGiftCard.h"


SingleCategoryGiftCard::SingleCategoryGiftCard( double discount, const MyString& category)
    : GiftCard( discount), category(category) {}

bool SingleCategoryGiftCard::isApplicable(const MyString& inputCategory) const {
    return inputCategory == category;
}

MyString SingleCategoryGiftCard::getName() const {
    return "SingleCategoryGiftCard";
}

const char* SingleCategoryGiftCard::getCode() const {
    return getcode();
}

void SingleCategoryGiftCard::print() const {
    std::cout << getDiscount()*100 <<"% applied to all products of category "<<category<<". Transaction completed!" << "\n";
}

MyString SingleCategoryGiftCard::printcategories() const {
    return  category;
}