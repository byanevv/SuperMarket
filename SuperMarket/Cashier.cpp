#include "Cashier.h"

Cashier::Cashier(const MyString& firstName, const MyString& lastName,
    const MyString& phone, int age, const MyString& password)
    : Worker(firstName, lastName, phone, age, password),
    transactionCount(0), warningCount(0), warningCapacity(5) {
    warnings = new Warning[warningCapacity];
}

Cashier::~Cashier() {
    delete[] warnings;
}

void Cashier::addTransaction() {
    transactionCount++;
}

void Cashier::resizeWarnings() {
    warningCapacity *= 2;
    Warning* newWarnings = new Warning[warningCapacity];
    for (int i = 0; i < warningCount; ++i) {
        newWarnings[i] = warnings[i];
    }
    delete[] warnings;
    warnings = newWarnings;
}

void Cashier::addWarning(const Warning& newWarning) {
    if (warningCount >= warningCapacity) {
        resizeWarnings();
    }
    warnings[warningCount++] = newWarning;
}

int Cashier::getTransactionCount() const {
    return transactionCount;
}

int Cashier::getWarningCount() const {
    return warningCount;
}

int Cashier::getWarningPoints() const {
    int sum = 0;
    for (size_t i = 0; i < warningCount; i++)
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