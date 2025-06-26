#pragma once

#include "Worker.h"
#include "Cashier.h"
#include "Warning.h"
#include "Manager.h"
#include "GiftCard.h"
#include "AllProductsGiftCard.h"
#include "MultipleCategoryGiftCard.h"
#include "SingleCategoryGiftCard.h"
#include "Category.h"
#include "Product.h"
#include "ProductsByUnit.h"
#include "ProductsByWeight.h"
#include "MyString.h"
#include "Vector.hpp"
#include "Transactions.h"

class SuperMarketSystem {
private:
    Vector<Manager> managers;
    Vector<Cashier> cashiers;
    Vector<Cashier> waitingCashiers;

    Vector<Category> categories;
    Vector<Product*> products;
    Vector<GiftCard*> giftCards;
    Vector<MyString> supermarketfeed;
    Vector<Transaction> transactions;

    Worker* loggedInUser = nullptr;

public:
    SuperMarketSystem() = default;
    ~SuperMarketSystem();

    // Registration and Login
    void registerUser(const MyString& role, const MyString& firstName,
        const MyString& lastName, const MyString& phoneNumber,
        int age, const MyString& password);

    bool login(int id, const MyString& password);
    void logout();
    void leave();

    // Listing
    void listUserData() const;
    void listWorkers() const;
    void listProducts() const;
    void listProductsByCategory(int categoryId) const;
    void listFeed() const;
    void listTransactions() const;

    // Helpers for adding data
    void addManager(const Manager& m);
    void addCashier(const Cashier& c);
    void addWaitingCashier(const Cashier& c);
    void editCategory(int id);
    
    void sell();
    bool isaCashierloggedin() const;

    // Manager Functionalities
    bool isaManagerloggedin() const;

    void listPendingCashiers() const;
    bool approveCashier(int cashierId, const MyString& specialCode);
    bool declineCashier(int cashierId, const MyString& specialCode);
    void listWarnedCashiers(int minPoints) const;
    bool warnCashier(int cashierId, int points);
    bool promoteCashier(int cashierId, const MyString& specialCode);
    bool fireCashier(int cashierId, const MyString& specialCode);

    bool addCategory(const MyString& name, const MyString& description);
    bool deleteCategory(int categoryId);

    void addProductFromConsole(const MyString& productType);
    bool deleteProduct(int productId);

    //Load files information
    bool loadProductsFromFile(const MyString& filename);
    bool loadGiftCardsFromFile(const MyString& filename);

};