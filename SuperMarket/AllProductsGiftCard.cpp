#include "AllProductsGiftCard.h"

AllProductsGiftCard::AllProductsGiftCard(const MyString& code, double discount)
    : GiftCard(code, discount) {}

bool AllProductsGiftCard::isApplicable(const MyString&) const {
    return true;
}