#pragma once

#include "Product.h"

class ProductsByWeight : public Product {
private:
    double kilos;

public:
    ProductsByWeight(const MyString& name, const Category& category, double price, double kilos);
    double getwhatsleft() const override;
    void setKilos(double kilos);
    void print() const override;
    MyString getType() const override;
    bool restock(int quantitytt) override;
};
