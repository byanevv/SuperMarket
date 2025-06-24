#pragma once

#include "GiftCard.h"

class SingleCategoryGiftCard : public GiftCard {
private:
    MyString category;

public:
    SingleCategoryGiftCard( double discount, const MyString& category);
    bool isApplicable(const MyString& category) const override;
    MyString getName() const override;
    void print() const override;
};