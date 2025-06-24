#pragma once

#include "Product.h"

class ProductsByUnit : public Product {
private:
    int quantity;

public:
    ProductsByUnit(const MyString& name, const Category& category, double price, int quantity);
    int getQuantity() const;
    void setQuantity(int quantity);
    void print() const override;
    void restock(int quantitytt) override;
};
