#pragma once

#include "MyString.h"

class GiftCard {
private:
    char code[6];
    double discount;
    static int counter;
    int count;

    //static bool isValidCode(const MyString& code);
    void generateCode();

public:
    GiftCard() = default;
    GiftCard(double discount);
    virtual ~GiftCard() = default;

    virtual const char* getCode() const = 0;
    const char* getcode() const;
    double getDiscount() const;
    virtual MyString getName() const ;

    virtual void print() const = 0;
    virtual MyString printcategories() const = 0;

    virtual bool isApplicable(const MyString& category) const ;
};