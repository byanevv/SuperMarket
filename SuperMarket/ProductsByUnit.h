#pragma once

#include "Product.h"

class ProductsByUnit : public Product {
private:
    int quantity;

public:
    ProductsByUnit(const MyString& name, const Category& category, double price, int quantity);
    double getwhatsleft() const override;
    void setQuantity(int quantity);
    void print() const override;
    MyString getType() const override;
    bool restock(int quantitytt) override;
};
