#pragma once

#include "GiftCard.h"

class SingleCategoryGiftCard : public GiftCard {
private:
    MyString category;

public:
    SingleCategoryGiftCard(const MyString& code, double discount, const MyString& category);
    bool isApplicable(const MyString& category) const override;
};