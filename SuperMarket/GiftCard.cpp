#include "GiftCard.h"
#include <regex>
#include <stdexcept>

int GiftCard::counter = 0;

GiftCard::GiftCard(const MyString& code, double discount)
    : code(code), discount(discount)
{
    counter++; 
}

MyString GiftCard::getCode() const {
    return code;
}

double GiftCard::getDiscount() const {
    return discount;
}

bool GiftCard::isValidCode(const MyString& code) {
    std::regex pattern(R"(^[0-9][A-Z][0-9]+[A-Z][0-9]$)");
    return std::regex_match(code.c_str(), pattern);
}