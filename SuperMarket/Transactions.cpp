#include "Transactions.h"
#include <ctime>
#include <iomanip>
#include <sstream>
#include <iostream>

Transaction::Transaction(int cashierId, double totalSum,const MyString& receiptFilename)
    : cashierId(cashierId), totalSum(totalSum),receiptFileName(receiptFileName)
{
   // chasta s vremeto nz kak da stane ama tova ostava za posle

    
}

int Transaction::getCashierId() const {
    return cashierId;
}

double Transaction::getTotalSum() const {
    return totalSum;
}

const MyString& Transaction::getDateTime() const {
    return dateTime;
}

const MyString& Transaction::getReceiptFileName() const {
    return receiptFileName;
}

void Transaction::print(int transid) const {
    std::cout << "Transaction number "<< transid <<" :\n";
    std::cout << "  Cashier ID: " << cashierId << "\n";
    std::cout << "  Sum: " << totalSum << " lv.\n";
    std::cout << "  Time: " << dateTime << "\n";
    std::cout << "  file: receipt_" << transid << ".txt" << "\n";
}
