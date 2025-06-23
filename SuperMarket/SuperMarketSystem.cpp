#include "SuperMarketSystem.h"
#include <iostream>
#include <string> 


SuperMarketSystem::~SuperMarketSystem() {
    //tuka trqbva da se deletvat lainata i da se zapazva v fail
}

void SuperMarketSystem::addManager(const Manager& m) {
    managers.pushBack(m);
}

void SuperMarketSystem::addCashier(const Cashier& c) {
    cashiers.pushBack(c);
}

void SuperMarketSystem::addWaitingCashier(const Cashier& c) {
    waitingCashiers.pushBack(c);
}

//void SuperMarketSystem::approveCashier(const MyString& id) {
//    for (size_t i = 0; i < waitingCashiers.size(); i++) {
//        if (waitingCashiers[i].getId() == id) {
//            addCashier(waitingCashiers[i]);
//            waitingCashiers[i] = waitingCashiers[waitingCashiers.size() - 1];
//            waitingCashiers.popBack();
//            std::cout << "Cashier approved.\n";
//            return;
//        }
//    }
//    std::cout << "No such cashier in waiting list.\n";
//}

bool SuperMarketSystem::registerUser(const MyString& role, const MyString& firstName,
                                     const MyString& lastName, const MyString& phoneNumber,
                                     int age, const MyString& password) {

    if (role == "manager") {
        Manager m(firstName, lastName, phoneNumber, age, password);
        addManager(m);
        std::cout << "Manager registered successfully!\n" << "Special code: " << m.getSpecialCode() << "\n";
        std::cout << "Code: "<< m.getId() <<"_special_code.txt\n";
        MyString feed = "A manager with id " + m.getId();
        supermarketfeed.pushBack(feed + " was added.");
        return true;
    } else if (role == "cashier") {
        Cashier c(firstName, lastName, phoneNumber, age, password);
        addWaitingCashier(c);
        std::cout << "Cashier registration pending approval from a manager.\n";
        MyString feed = "A cashier with id " + c.getId();
        supermarketfeed.pushBack(feed + " was added to the pending list.");
        return true;
    }

    std::cout << "Invalid role!\n";
    return false;
}

bool SuperMarketSystem::login(int id, const MyString& password) {
    if (loggedInUser != nullptr) {
        std::cout << "Worker with this " << loggedInUser->getId() << " is in the system !\n";
        return;
    }
    else {
        for (size_t i = 0; i < managers.size(); i++) {
            if (managers[i].getId() == id && managers[i].getPassword() == password) {
                loggedInUser = &managers[i];
                std::cout << "User " << managers[i].getFirstName() << " " << managers[i].getLastName() << " with ID: "
                    << id << " has been logged into the system!\n";
                return true;
            }
        }

        for (size_t i = 0; i < cashiers.size(); i++) {
            if (cashiers[i].getId() == id && cashiers[i].getPassword() == password) {
                loggedInUser = &cashiers[i];
                std::cout << "User " << cashiers[i].getFirstName() << " " << cashiers[i].getLastName() << " with ID: "
                    << id << " has been logged into the system!\n";
                return true;
            }
        }
        std::cout << "Invalid credentials.\n";
        return false;
    }
}

void SuperMarketSystem::logout() {
    loggedInUser = nullptr;
}

void SuperMarketSystem::leave() {
    if (!loggedInUser) {
        std::cout << "No user logged in.\n";
        return;
    }

    int id = loggedInUser->getId();

    if (loggedInUser->getRole() == "Manager") {
        for (size_t i = 0; i < managers.size(); i++) {
            if (managers[i].getId() == id) {
                MyString feed = "A manager with id " + managers[i].getId();
                supermarketfeed.pushBack(feed + " left work.");
                managers[i] = managers[managers.size() - 1];
                managers.popBack();
                std::cout << "Manager removed.\n";
                break;
            }
        }
    } else if (loggedInUser->getRole() == "Cashier") {
        for (size_t i = 0; i < cashiers.size(); i++) {
            if (cashiers[i].getId() == id) {
                MyString feed = "A Cashier with id " + cashiers[i].getId();
                supermarketfeed.pushBack(feed + " left work.");
                cashiers[i] = cashiers[cashiers.size() - 1];
                cashiers.popBack();
                std::cout << "Cashier removed.\n";
                break;
            }
        }
    }

    logout();
}

void SuperMarketSystem::listUserData() const {
    if (!loggedInUser) {
        std::cout << "No user logged in.\n";
        return;
    }
    loggedInUser->print();
}

void SuperMarketSystem::listWorkers() const {
    std::cout << "Managers:\n";
    for (size_t i = 0; i < managers.size(); i++) {
        managers[i].print();
    }
    std::cout << "Cashiers:\n";
    for (size_t i = 0; i < cashiers.size(); i++) {
        cashiers[i].print();
    }
}

void SuperMarketSystem::listProducts() const {
    for (size_t i = 0; i < products.size(); i++) {
        std::cout << (i + 1) << ". ";
        products[i].print();
    }
}

void SuperMarketSystem::listProductsByCategory(int categoryId) const {
    int j = 0;
    for (size_t i = 0; i < products.size(); i++) {
        if (products[i].getCategory().getId() == categoryId) {
            std::cout << "Products from category " << products[i].getCategory().getName();
            std::cout << (j++) << ". "; // da go proverq dali raboti pravilno
            products[i].print();
        }
    }
}

void SuperMarketSystem::listFeed() const {
    std::cout << "All changes to the supermarketsystem : ";
    for (size_t i = 0; i < supermarketfeed.size(); i++)
    {
        std::cout << supermarketfeed[i];
    }
}

void SuperMarketSystem::listTransactions() const {
    std::cout << "All transactions : ";
    for (size_t i = 0; i < transactions.size(); i++) {
        transactions[i].print(i-1);
    }
}

//sell function

//Manager part

void SuperMarketSystem::listPendingCashiers() const {
    std::cout << "Waiting Cashiers:\n";
    for (size_t i = 0; i < cashiers.size(); i++) {
        cashiers[i].print();
    }
}

bool SuperMarketSystem::approveCashier(int cashierId, const MyString& specialCode) {
    if (loggedInUser->getSpecialCode() == specialCode) {

        for (size_t i = 0; i < waitingCashiers.size(); i++) {
            if (waitingCashiers[i].getId() == cashierId ) {
                cashiers.pushBack(waitingCashiers[i]);
                waitingCashiers[i] = waitingCashiers[waitingCashiers.size() - 1];
                waitingCashiers.popBack();
                std::cout << "Cashier approved successfully!\n";
                MyString feed = "A manager with id " + loggedInUser->getId();
                supermarketfeed.pushBack(feed + " approved a new cashier!");
                return true;
            }
        }
    }
    else {
        std::cout << "Wrong code!\n";
    }
    return false;
}

bool SuperMarketSystem::declineCashier(int cashierId, const MyString& specialCode) {
    if (loggedInUser->getSpecialCode() == specialCode) {

        for (size_t i = 0; i < waitingCashiers.size(); i++) {
            if (waitingCashiers[i].getId() == cashierId) {

                waitingCashiers[i] = waitingCashiers[waitingCashiers.size() - 1];
                waitingCashiers.popBack();
                MyString feed = "A manager with id " + loggedInUser->getId();
                supermarketfeed.pushBack(feed + " declined a cashier!");
                return true;
            }
        }
    }
    else {
        std::cout << "Wrong code!\n";
    }
    return false;
}

void SuperMarketSystem::listWarnedCashiers(int minPoints) const {
    std::cout << "Warned Cashiers with at least " << minPoints << " :\n";
    for (size_t i = 0; i < cashiers.size(); i++) {
        if (cashiers[i].getWarningPoints() >= minPoints) {
            cashiers[i].print();
        }
    }
}

bool SuperMarketSystem::warnCashier(int cashierId, int points) {
    for (size_t i = 0; i < cashiers.size(); i++) {
        if (cashiers[i].getId() == cashierId) {
            Warning newwarning(loggedInUser->getId(),points);
            MyString feed = "A manager with id " + loggedInUser->getId();
            feed += " warned a cashier with id ";
            feed += cashierId;
            supermarketfeed.pushBack(feed + ".");
        }
    }
    return false;
}

bool SuperMarketSystem::promoteCashier(int cashierId, const MyString& specialCode) {
    if (loggedInUser->getSpecialCode() == specialCode) {
        for (size_t i = 0; i < cashiers.size(); i++) {
            if (cashiers[i].getId() == cashierId) {
                Manager m(cashiers[i].getFirstName(), cashiers[i].getLastName(),
                    cashiers[i].getPhone(), cashiers[i].getAge(), cashiers[i].getPassword());

                managers.pushBack(m);
                cashiers[i] = cashiers[cashiers.size() - 1];
                cashiers.popBack();
                std::cout << "A cashier was promoted to manager successfully!\n" << "Special code: " << m.getSpecialCode() << "\n";
                std::cout << "Code: " << m.getId() << "_special_code.txt\n";

                MyString feed = "A manager with id " + loggedInUser->getId();
                feed += " promoted a cashier with id ";
                feed += cashierId;
                supermarketfeed.pushBack(feed + ".");

                return true;
            }
        }
    }
    return false;
}

bool SuperMarketSystem::fireCashier(int cashierId, const MyString& specialCode) {
    if (loggedInUser->getSpecialCode() == specialCode) {
        for (size_t i = 0; i < cashiers.size(); i++) {
            if (cashiers[i].getId() == cashierId) {
                cashiers[i] = cashiers[cashiers.size() - 1];
                cashiers.popBack();
                MyString feed = "A manager with id " + loggedInUser->getId();
                feed += " fired a cashier with id ";
                feed += cashierId;
                supermarketfeed.pushBack(feed + ".");
                return true;
            }
        }
    }
    return false;
}

bool SuperMarketSystem::addCategory(const MyString& name, const MyString& description) {
    for (size_t i = 0; i < categories.size(); i++) {
        if (categories[i].getName() == name) { 
            std::cout << "There is already a category with this name.";
            return false; }
        MyString feed = "A manager with id " + loggedInUser->getId();
        feed += " tried to add a new category ";
        feed += name;
        supermarketfeed.pushBack(feed + " but there was already one like that.");

    }
    categories.pushBack(Category(name, description));
    MyString feed = "A manager with id " + loggedInUser->getId();
    feed += " added a new category ";
    feed += name;
    supermarketfeed.pushBack(feed + ".");
    return true;
}

bool SuperMarketSystem::deleteCategory(int categoryId) {
    for (size_t i = 0; i < products.size(); i++) {
        if (products[i].getCategory().getId() == categoryId) {
            std::cout << "You first have to delete all the products from this category to be able to delete it.\n";
            MyString feed = "A manager with id " + loggedInUser->getId();
            feed += " tried to delete category ";
            feed += categories[categoryId].getName();
            supermarketfeed.pushBack(feed + " but there were products from this category.");
            return false; 
        }
    }

    for (size_t i = 0; i < categories.size(); ++i) {
        if (categories[i].getId() == categoryId) {

            MyString feed = "A manager with id " + loggedInUser->getId();
            feed += " deleted category ";
            feed += categories[i].getName();
            supermarketfeed.pushBack(feed + ".");

            categories[i] = categories[categories.size() - 1];
            categories.popBack();
            return true;
        }
    }
    return false;
}

void SuperMarketSystem::addProductFromConsole(const MyString& productType) {
    MyString name, categoryName;
    double price;
    double quantity;

    std::cout << "Enter product name: ";
    std::cin.ignore();
    std::cin >> name;
    //problem with taking the name in 2 parts

    std::cout << "Enter product category: ";
    std::cin >> categoryName;

    int categoryId = -1;
    for (size_t i = 0; i < categories.size(); i++){
        if (categories[i].getName() == categoryName) {
            categoryId = categories[i].getId();
            break;
        }
    }

    if (categoryId == -1) {
        std::cout << "Category \"" << categoryName << "\" not found!\n";
        return;
    }

    if (productType == "product_by_weight") {
        std::cout << "Enter price per kg: ";
        std::cin >> price;

        std::cout << "Enter quantity (kg): ";
        std::cin >> quantity;

        ProductsByWeight p(name, categories[categoryId], price, quantity);
        products.pushBack(p);

    }
    else if (productType == "product_by_unit") {
        std::cout << "Enter price per unit: ";
        std::cin >> price;

        std::cout << "Enter quantity (units): ";
        std::cin >> quantity;

        ProductsByUnit p(name, categories[categoryId], price, static_cast<int>(quantity));
        products.pushBack(p);

    }
    else {
        std::cout << "Unknown product type: " << productType << '\n';
        return;
    }

    std::cout << "Product \"" << name << "\" added successfully under category \"" << categoryName << "\"\n";
    MyString feed = "A manager with id " + loggedInUser->getId();
    feed += " added a new product ";
    feed += name;
    supermarketfeed.pushBack(feed + ".");
}


bool SuperMarketSystem::deleteProduct(int productId) {
    for (size_t i = 0; i < products.size(); ++i) {
        if (products[i].getId() == productId) {

            MyString feed = "A manager with id " + loggedInUser->getId();
            feed += " deleted a product ";
            feed += products[i].getName();
            supermarketfeed.pushBack(feed + " but there was already one like that.");

            products[i] = products[products.size() - 1];
            products.popBack();
            return true;
        }
    }
    return false;
}