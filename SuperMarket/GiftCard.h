#pragma once

#include "MyString.h"

class GiftCard {
protected:
    MyString code;
    double discount;
    static int counter;

    //static bool isValidCode(const MyString& code);
    void generateCode();

public:
    GiftCard() = default;
    GiftCard(double discount);
    virtual ~GiftCard() = default;

    MyString getCode() const;
    double getDiscount() const;
    virtual MyString getName() const ;

    virtual void print() const;

    virtual bool isApplicable(const MyString& category) const ;
};