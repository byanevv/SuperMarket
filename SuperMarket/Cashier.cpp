#include "Cashier.h"

Cashier::Cashier(const MyString& firstName, const MyString& lastName,
    const MyString& phone, int age, const MyString& password)
    : Worker(firstName, lastName, phone, age, password),
    transactionCount(0) {
    
}

Cashier::~Cashier() {
    
}

void Cashier::addTransaction() {
    transactionCount++;
    if (transactionCount % 3 == 0) {
        if (warnings.size()>=1) {
            for (size_t i = 0; i < warnings.size()-1; i++)
            {   
                warnings[i] = warnings[i + 1];
            }
            warnings.popBack();
        }
    }
}

void Cashier::addWarning(const Warning& newWarning) {
    
    warnings.pushBack(newWarning);
}

int Cashier::getTransactionCount() const {
    return transactionCount;
}

int Cashier::getWarningCount() const {
    return warnings.size();
}

int Cashier::getWarningPoints() const {
    int sum = 0;
    for (size_t i = 0; i < warnings.size(); i++)
    {
        sum += warnings[i].getPoints();
    }
    return sum;
}


MyString Cashier::getRole() const {
    return "Cashier";
}

void Cashier::print() const {
    std::cout << firstName << " " << lastName << " with id " << id << " and phone number : " << phone << "\n";
}

const char* Cashier::getSpecialCode() const {
    std::cout << "Cashiers dont have special code.";
    return "nocode";
}

MyString Cashier::printwarnings() const {
    MyString warningss = "";
    for (size_t i = 0; i < warnings.size(); i++)
    {
        warningss = warningss + warnings[i].getSeverity();
        warningss = warningss + ":";
    }
    return warningss;
}