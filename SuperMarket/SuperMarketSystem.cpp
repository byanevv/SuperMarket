#include "SuperMarketSystem.h"
#include <iostream>

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
//    for (size_t i = 0; i < waitingCashiers.size(); ++i) {
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
        for (size_t i = 0; i < managers.size(); ++i) {
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
        for (size_t i = 0; i < cashiers.size(); ++i) {
            if (cashiers[i].getId() == id) {
                MyString feed = "A manager with id " + cashiers[i].getId();
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
    for (size_t i = 0; i < managers.size(); ++i) {
        managers[i].print();
    }
    std::cout << "Cashiers:\n";
    for (size_t i = 0; i < cashiers.size(); ++i) {
        cashiers[i].print();
    }
}

void SuperMarketSystem::listProducts() const {
    for (size_t i = 0; i < products.size(); ++i) {
        std::cout << (i + 1) << ". ";
        products[i].print();
    }
}

void SuperMarketSystem::listProductsByCategory(int categoryId) const {
    int j = 0;
    for (size_t i = 0; i < products.size(); ++i) {
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
    for (size_t i = 0; i < transactions.size(); ++i) {
        transactions[i].print(i-1);
    }
}
