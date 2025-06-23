#pragma once

#include "GiftCard.h"

class AllProductsGiftCard : public GiftCard {
public:
    AllProductsGiftCard(const MyString& code, double discount);
    bool isApplicable(const MyString& category) const override;
};
