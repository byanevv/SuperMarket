#pragma once

#include "GiftCard.h"

class AllProductsGiftCard : public GiftCard {
public:
    AllProductsGiftCard( double discount);
    bool isApplicable(const MyString& category) const override;
    const char* getCode() const override;
    MyString getName() const override;
    void print() const override;
    MyString printcategories() const override;
};
