#include "GiftCard.h"
#include <cstdlib>
#include <ctime>

int GiftCard::counter = 1;

GiftCard::GiftCard(double discount) : discount(discount),count(counter++){
    
    

    generateCode();

}

void GiftCard::generateCode() {
    code[0] = '0' + rand() % 10;
    code[1] = 'A' + rand() % 26;
    code[2] = count + '0';
    code[3] = 'A' + rand() % 26;
    code[4] = '0' + rand() % 10;
    code[5] = '\0';
  
}

const char* GiftCard::getcode() const {
    return code;
}


double GiftCard::getDiscount() const {
    return discount;
}

//bool GiftCard::isValidcode(const MyString& code) {
//    std::regex pattern(R"(^[0-9][A-Z][0-9]+[A-Z][0-9]$)");
//    return std::regex_match(code.c_str(), pattern);
//}


MyString GiftCard::getName() const { return "skibid"; }

bool GiftCard::isApplicable(const MyString& category) const { return true; }