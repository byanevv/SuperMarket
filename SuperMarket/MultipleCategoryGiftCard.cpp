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

void MultipleCategoryGiftCard::print() const {
    std::cout << discount * 100 << "% applied to products of multiple categories. Transaction completed!" << "\n";
}