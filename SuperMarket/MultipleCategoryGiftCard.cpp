#include "MultipleCategoryGiftCard.h"

MultipleCategoryGiftCard::MultipleCategoryGiftCard(double discount, Vector<MyString> newcategories)
    : GiftCard( discount), categories(newcategories) {}

bool MultipleCategoryGiftCard::isApplicable(const MyString& inputCategory) const {
    for (size_t i = 0; i < categories.size(); i++)
    {
        if (categories[i] == inputCategory) {
            return true;
        }
    }
    return false;
}

MyString MultipleCategoryGiftCard::getName() const {
    return "MultipleCategoryGiftCard";
}
const char* MultipleCategoryGiftCard::getCode() const {
    return getcode();
}

void MultipleCategoryGiftCard::print() const {
    std::cout << getDiscount() * 100 << "% applied to products of multiple categories. Transaction completed!" << "\n";
}

MyString MultipleCategoryGiftCard::printcategories() const {
    MyString returnline = "";

    returnline += categories.size();
    returnline += ":";

    for (size_t i = 0; i < categories.size(); i++)
    {
        returnline += categories[i];
        returnline += ":";
    }

    return returnline;
}