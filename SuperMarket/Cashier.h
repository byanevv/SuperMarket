#pragma once

#include "Worker.h"
#include "Warning.h"
#include "Vector.hpp"

class Cashier : public Worker {
private:
    int transactionCount;
    Vector<Warning> warnings;

public:
    Cashier() = default;
    Cashier(const MyString& firstName, const MyString& lastName,
        const MyString& phone, int age, const MyString& password);
    ~Cashier();

    void addTransaction() override ;
    void addWarning(const Warning& newWarning);

    int getTransactionCount() const;
    int getWarningCount() const;
    int getWarningPoints() const;
    MyString getRole() const override;
    void print() const override;
    MyString printwarnings() const;
    const char* getSpecialCode() const override;
    

};
