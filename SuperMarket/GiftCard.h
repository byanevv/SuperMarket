#pragma once

#include "MyString.h"

class GiftCard {
protected:
    MyString code;
    double discount;
    static int counter;

    static bool isValidCode(const MyString& code);

public:
    GiftCard(const MyString& code, double discount);
    virtual ~GiftCard() = default;

    MyString getCode() const;
    double getDiscount() const;

    virtual bool isApplicable(const MyString& category) const = 0;
};