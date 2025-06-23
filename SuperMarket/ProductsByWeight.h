#pragma once

#include "Product.h"

class ProductsByWeight : public Product {
private:
    double kilos;

public:
    ProductsByWeight(const MyString& name, const Category& category, double price, double kilos);
    double getKilos() const;
    void setKilos(double kilos);
    void print() const override;
};
