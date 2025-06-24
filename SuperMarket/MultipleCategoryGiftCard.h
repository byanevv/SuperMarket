#pragma once

#include "GiftCard.h"
#include "Vector.hpp"

class MultipleCategoryGiftCard : public GiftCard {
private:
    Vector<MyString> categories;

public:
    MultipleCategoryGiftCard( double discount, Vector<MyString> newcategories);
    bool isApplicable(const MyString& category) const override;
    MyString getName() const override;
    void print() const override;
};