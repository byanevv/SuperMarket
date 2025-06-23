#pragma once

#include "Worker.h"
#include "Warning.h"

class Cashier : public Worker {
private:
    int transactionCount;
    Warning* warnings;     
    int warningCount;      
    int warningCapacity;    

    void resizeWarnings();  

public:
    Cashier(const MyString& firstName, const MyString& lastName,
        const MyString& phone, int age, const MyString& password);
    ~Cashier();

    void addTransaction();
    void addWarning(const Warning& newWarning);

    int getTransactionCount() const;
    int getWarningCount() const;
    MyString getRole() const override;
    void print() const override;
};
