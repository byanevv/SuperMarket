#include "SuperMarketSystem.h"
#include <iostream>
#include <string>
#include <fstream>


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

void SuperMarketSystem::registerUser(const MyString& role, const MyString& firstName,
                                     const MyString& lastName, const MyString& phoneNumber,
                                     int age, const MyString& password) {

    if (role == "manager") {
        Manager m(firstName, lastName, phoneNumber, age, password);
        addManager(m);
        std::cout << "Manager registered successfully!\n" << "Special code: " << m.getSpecialCode() << "\n";
        std::cout << "Code: "<< m.getId() <<"_special_code.txt\n";
        MyString feed = "A manager with id " + m.getId();
        supermarketfeed.pushBack(feed + " was added.");
       
    } else if (role == "cashier") {
        Cashier c(firstName, lastName, phoneNumber, age, password);
        addWaitingCashier(c);
        std::cout << "Cashier registration pending approval from a manager.\n";
        MyString feed = "A cashier with id " + c.getId();
        supermarketfeed.pushBack(feed + " was added to the pending list.");
      
    }
    else {
        std::cout << "Invalid role!\n";
    }
   
}

bool SuperMarketSystem::login(int id, const MyString& password) {
    if (loggedInUser != nullptr) {
        std::cout << "Worker with this " << loggedInUser->getId() << " is in the system !\n";
        return true;
    }
    else {
        for (size_t i = 0; i < managers.size(); i++) {
            if (managers[i].getId() == id && managers[i].getPassword() == password) {
                loggedInUser = &managers[i];
                std::cout << "User " << managers[i].getFirstName() << " " << managers[i].getLastName() << " with id "
                    << id << " has been logged into the system!\n";
                return true;
            }
        }

        for (size_t i = 0; i < cashiers.size(); i++) {
            if (cashiers[i].getId() == id && cashiers[i].getPassword() == password) {
                loggedInUser = &cashiers[i];
                std::cout << "User " << cashiers[i].getFirstName() << " " << cashiers[i].getLastName() << " with id "
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
    std::cout << "Products :";
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
    std::cout << "All changes to the supermarketsystem : \n";
    for (size_t i = 0; i < supermarketfeed.size(); i++)
    {
        std::cout << supermarketfeed[i]<<std::endl;
    }
}

void SuperMarketSystem::listTransactions() const {
    std::cout << "All transactions : ";
    for (size_t i = 0; i < transactions.size(); i++) {
        transactions[i].print(i-1);
    }
}

//sell function
void SuperMarketSystem::sell() {

    Vector<MyString> productssell;
    Vector<double> quantity;
    Vector<double> discounts;
    int price = 0;
    MyString id ;
    double quantityofproduct = 0;
    bool transaction = true;
    MyString yesorno;
    MyString vouchername;
    bool rightvoucher = true;
    while (transaction)
    {
        listProducts();
        std::cout << std::endl << "Transaction ID: " << transactions.size() + 1 << std::endl << "Price : " << price << std::endl << std::endl;
        std::cout << "Enter product ID to sell. Enter END to end the transaction." << std::endl << "> ";
        std::cin >> id;
        if (id != "END") {
            std::cout << "Enter quantity:" << std::endl << "> ";
            std::cin >> quantityofproduct;
            std::cout << std::endl << "---------" << std::endl << std::endl;

            for (size_t i = 0; i < products.size(); i++)
            {
                id.toInt();

                if (products[i].getId() == id) {
                    price += products[i].getPrice() * quantityofproduct;
                    products[i].restock(-quantityofproduct);
                    for (size_t j = 0; j < productssell.size(); j++)
                    {
                        if (productssell[j] == id) {
                            quantity[j] += quantityofproduct;
                        }
                    }
                    productssell.pushBack(id);
                    quantity.pushBack(quantityofproduct);
                    discounts.pushBack(0);
                }
                else {
                    std::cout << "There is not a product with this id.\n";
                }
            }

        }
        else if (id == "END") {
            transaction = false;
        }
    }
      
        std::cout << std::endl << "Ädd voucher: (Y/N)? ";
        std::cin >> yesorno;
            if(yesorno == "Y") {
                while (rightvoucher) {
                    std::cout << "Enter voucher:  ";
                    std::cin >> vouchername;
      
                    for (size_t i = 0; i < giftCards.size(); i++)
                    {
                        if (giftCards[i].getCode() == vouchername) {
                            rightvoucher = false;
                            std::cout << std::endl;
                            giftCards[i].print();
                            for (size_t p = 0; p < productssell.size(); p++)
                            {

                                for (size_t j = 0; j < products.size(); j++)
                                {
                                    if (products[j].getId() == productssell[p] ) {

                                        if (giftCards[i].isApplicable(products[j].getCategory().getName())) {
                                            double discount = quantity[p] * products[j].getPrice()*giftCards[i].getDiscount();
                                            price -= discount;
                                            discounts[p] = giftCards[i].getDiscount();
                                        }

                                    }
                                }
                                
                            }

                        }
                    }
                    if (rightvoucher == true) {
                        std::cout << "No voucher with this code. Try again.\n";
                    }

                }
                
            }
            
                MyString receiptname = "receipt_" + (transactions.size() + 1);
                receiptname += ".txt";
                std::cout << std::endl << "Receipt saved as: " << receiptname << std::endl;
                std::cout << "Total: " << price << " lv." << std::endl << std::endl;
                Transaction T(loggedInUser->getId(), price, receiptname);
                loggedInUser->addTransaction();

                std::ofstream outFile(receiptname.c_str());
                if (outFile.is_open()) {
                    
                    outFile << "RECEIPT\n" << "TRANSACTION_ID: " << transactions.size() << "\n" << "CASHIER_ID" << loggedInUser->getId();
                    outFile << "\n" << transactions[transactions.size() - 1].getDateTime() << "\n" << "-----------------------------\n\n";
                    for (size_t i = 0; i < productssell.size(); i++)
                    {
                        for (size_t j = 0; j < products.size(); j++)
                        {
                            if (products[j].getId() == productssell[i]) {
                                outFile << products[j].getName() << "\n" << quantity[i] << "*" << products[j].getPrice() << " - ";
                                outFile << quantity[i] * (products[j].getPrice() - products[j].getPrice()*discounts[i]);
                                outFile << "\n" << "###\n";
                            }
                        }
                        outFile << "TOTAL: " << price;
                    }

                    outFile.close();
                }
}

bool SuperMarketSystem::isaCashierloggedin()const {
    if (loggedInUser->getRole() == "Cashier") {
        return true;
    }
    return false;
}
//Manager part
bool SuperMarketSystem::isaManagerloggedin()const {
    if (loggedInUser->getRole() == "Manager") {
        return true;
    }
    return false;
}


void SuperMarketSystem::listPendingCashiers() const {
    std::cout << "Waiting Cashiers:\n";
    for (size_t i = 0; i < waitingCashiers.size(); i++) {
        waitingCashiers[i].print();
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
            std::cout << "A cashier with id " << cashierId << " was warned.\n";
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

bool SuperMarketSystem::loadProductsFromFile(const MyString& filename) {

    std::ifstream file(filename.c_str());

    if (!file.is_open()) {
        std::cout << "Failed to open file: " << filename << '\n';
        return false;
    }

    MyString line;
    while (file >> line) {
        MyString segment;
        Vector<MyString> tokens;
        MyString dvetochki = ":";
        for (size_t i = 0; i < line.getSize(); i++)
        {
            if (line[i] != dvetochki)
            {
                segment += line[i];
            }
            else {
                tokens.pushBack(segment);
                segment = "";
            }
        }

        if (tokens.empty()) continue;

        if (tokens[0] == "NEW") {
            if (tokens.size() < 6) {
                std::cout << "Invalid NEW product format.\n";
                continue;
            }

            MyString type = tokens[1];

            if (type == "by_unit") {
                // NEW:by_unit:<name>:<category>:<price>:<quantity>
                MyString name = tokens[2];
                MyString category = tokens[3];
                double price = std::stod(tokens[4].c_str());
                int quantity = std::stoi(tokens[5].c_str());
                bool isthereacategory = false;
                for (size_t i = 0; i < categories.size(); i++)
                {
                    if (categories[i].getName() == category) {
                        Category categoryproduct = categories[i];
                        ProductsByUnit p(name, categoryproduct, price, quantity);
                        isthereacategory = true;
                        products.pushBack(p);
                    }
                }
                if (isthereacategory == false) {
                    Category c(category, "random description");
                    ProductsByUnit p(name, c, price, quantity);
                    products.pushBack(p);
                }
                 
                std::cout << "Added new product \"" << name << "\"\n";
            }
            else if (type == "by_weight") {
                // NEW:by_weight:<name>:<category>:<price>:<weight>
                MyString name = tokens[2];
                MyString category = tokens[3];
                double price = std::stod(tokens[4].c_str());
                double weight = std::stod(tokens[5].c_str());
                bool isthereacategory = false;

                for (size_t i = 0; i < categories.size(); i++)
                {
                    if (categories[i].getName() == category) {
                        Category categoryproduct = categories[i];
                        ProductsByWeight p(name, categoryproduct, price, weight);
                        isthereacategory = true;
                        products.pushBack(p);
                    }
                }
                if (isthereacategory == false) {
                    Category c(category, "random description");
                    ProductsByWeight p(name, c, price, weight);
                    products.pushBack(p);
                }
                std::cout << "Added new product \"" << name << "\"\n";
            }
            else {
                std::cout << "Unknown product type in NEW: " << type << "\n";
            }
        }
        else {
            // Формат: <product_type>:<id>:<quantity>
            if (tokens.size() < 3) {
                std::cout << "Invalid product restock format.\n";
                continue;
            }

            int id = std::stoi(tokens[1].c_str());
            int quantity = std::stoi(tokens[2].c_str());
            bool foundtheproduct = false;

            for (size_t i = 0; i < products.size(); i++)
            {
                if (products[i].getId() == id) {
                    products[i].restock(quantity);
                    foundtheproduct = true;
                }
            }
            if (foundtheproduct == false) {
                std::cout << "Product with ID " << id << " not found.\n";
                continue;
            }
            std::cout << "Restocked product with ID " << id << " with " << quantity << " units.\n";
        }
    }

    file.close();
    return true;

}

bool SuperMarketSystem::loadGiftCardsFromFile(const MyString& filename) {

    std::ifstream file(filename.c_str());

    if (!file.is_open()) {
        std::cout << "Failed to open file: " << filename << '\n';
        return false;
    }

    MyString line;
    while (file >> line) {
        MyString segment;
        Vector<MyString> tokens;
        MyString dvetochki = ":";
        for (size_t i = 0; i < line.getSize(); i++)
        {
            if (line[i] != dvetochki)
            {
                segment += line[i];
            }
            else {
                tokens.pushBack(segment);
                segment = "";
            }
        }

        if (tokens.empty()) continue;

        MyString typeofgiftcard = tokens[0];

        if (typeofgiftcard == "SingleCategory") {
            //type:category:percent
            if (tokens.size() < 3) {
                std::cout << "Invalid SingleGiftCard format.\n";
                continue;
            }
            double discount = std::stod(tokens[2].c_str());
            MyString category = tokens[1];
            SingleCategoryGiftCard sc(discount,category);
            giftCards.pushBack(sc);
            std::cout << "Added new giftcard !\n";

        }
        else if (typeofgiftcard == "AllProductsCategory") {
            if (tokens.size() < 2) {
                std::cout << "Invalid AllProductsCategory format.\n";
                    continue;
            }
            double discount = std::stod(tokens[2].c_str());
            AllProductsGiftCard ap(discount);
            giftCards.pushBack(ap);
            std::cout << "Added new giftcard !\n";
        }
        else if (typeofgiftcard == "MultipleGiftCard") {
            int count = std::stoi(tokens[1].c_str());

            if (tokens.size() < 3+count) {
                std::cout << "Invalid MultipleGiftCard format.\n";
                continue;
            }

            double discount = std::stod(tokens[tokens.size()-1].c_str());
            Vector<MyString> multiplecategories;
            for (size_t i = 0; i < count; i++)
            {
                MyString currentcat = tokens[i + 2];
                multiplecategories.pushBack(currentcat);
            }
            MultipleCategoryGiftCard mc(discount,multiplecategories);
            giftCards.pushBack(mc);
            std::cout << "Added new giftcard !\n";
        }
        else {
            std::cout << "Wrong GiftCard Type.\n";
        }
      
    }

    file.close();
    return true;

}