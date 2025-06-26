#pragma once
#include "MyString.h"

class Transaction {
private:
    int cashierId;
    double totalSum;
    MyString dateTime;
    MyString receiptFileName;

public:
    Transaction() = default;
    Transaction(int cashierId, double totalSum,const MyString& receiptFilename);

    int getCashierId() const;
    double getTotalSum() const;
    const MyString& getDateTime() const;
    const MyString& getReceiptFileName() const;

    void print(int transid) const;
};