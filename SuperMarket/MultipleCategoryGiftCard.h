#pragma once

#include "GiftCard.h"
#include "Vector.hpp"

class MultipleCategoryGiftCard : public GiftCard {
private:
    Vector<MyString> categories;

public:
    MultipleCategoryGiftCard( double discount, Vector<MyString> newcategories);
    const char* getCode() const override;
    bool isApplicable(const MyString& category) const override;
    MyString getName() const override;
    void print() const override;
    MyString printcategories() const override;
};