#include "SingleCategoryGiftCard.h"

SingleCategoryGiftCard::SingleCategoryGiftCard(const MyString& code, double discount, const MyString& category)
    : GiftCard(code, discount), category(category) {}

bool SingleCategoryGiftCard::isApplicable(const MyString& inputCategory) const {
    return inputCategory == category;
}
