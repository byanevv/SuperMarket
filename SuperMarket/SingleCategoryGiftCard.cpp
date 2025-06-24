#include "SingleCategoryGiftCard.h"

SingleCategoryGiftCard::SingleCategoryGiftCard( double discount, const MyString& category)
    : GiftCard( discount), category(category) {}

bool SingleCategoryGiftCard::isApplicable(const MyString& inputCategory) const {
    return inputCategory == category;
}

MyString SingleCategoryGiftCard::getName() const {
    return "SingleCategoryGiftCard";
}

void SingleCategoryGiftCard::print() const {
    std::cout << discount*100 <<"% applied to all products of category "<<category<<". Transaction completed!" << "\n";
}