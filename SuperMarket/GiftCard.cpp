#include "GiftCard.h"
#include <stdexcept>
#include <cstdlib>
#include <ctime>

int GiftCard::counter = 0;

GiftCard::GiftCard(double discount)
    : discount(discount)
{
    counter++;
    std::srand(std::time(nullptr));
    void generatecode();
}

void GiftCard::generateCode() {
    code += '0' + rand() % 10;
    code += 'A' + rand() % 26;
    code +=counter;
    code += 'A' + rand() % 26;
    code += '0' + rand() % 10;
  
}

MyString GiftCard::getCode() const {
    return code;
}

double GiftCard::getDiscount() const {
    return discount;
}

//bool GiftCard::isValidcode(const MyString& code) {
//    std::regex pattern(R"(^[0-9][A-Z][0-9]+[A-Z][0-9]$)");
//    return std::regex_match(code.c_str(), pattern);
//}

void GiftCard::print() const {

}

MyString GiftCard::getName() const { return "skibid"; }

bool GiftCard::isApplicable(const MyString& category) const { return true; }