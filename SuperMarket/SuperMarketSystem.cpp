#include "SuperMarketSystem.h"
#include <iostream>
#include <fstream>


SuperMarketSystem::~SuperMarketSystem() {
    

    std::ofstream outFilem("Managersinfo.txt");
    if (outFilem.is_open()) {

        for (size_t i = 0; i < managers.size(); i++)
        {
            outFilem << managers[i].getId() << ":" << managers[i].getFirstName() << ":" << managers[i].getLastName() << ":";
            outFilem << managers[i].getPhone() << ":" << managers[i].getAge() << ":" << managers[i].getPassword() << ":";
            outFilem << managers[i].getSpecialCode() << "\n";
 
        }
        outFilem.close();
    }

    std::ofstream outFilec("Cashiersinfo.txt");
    if (outFilec.is_open()) {

        for (size_t i = 0; i < cashiers.size(); i++)
        {
            outFilec << cashiers[i].getId() << ":" << cashiers[i].getFirstName() << ":" << cashiers[i].getLastName() << ":";
            outFilec << cashiers[i].getPhone() << ":" << cashiers[i].getAge() << ":" << cashiers[i].getPassword() << ":";
            outFilec << cashiers[i].getTransactionCount() << ":"  << cashiers[i].getWarningCount() << ":";
            outFilec << cashiers[i].printwarnings() << "\n";
        }
        outFilec.close();
    }

    std::ofstream outFilew("WaitingCashiersinfo.txt");
    if (outFilew.is_open()) {

        for (size_t i = 0; i < waitingCashiers.size(); i++)
        {
            outFilew << waitingCashiers[i].getId() << ":" << waitingCashiers[i].getFirstName() << ":" << waitingCashiers[i].getLastName() << ":";
            outFilew << waitingCashiers[i].getPhone() << ":" << waitingCashiers[i].getAge() << ":" << waitingCashiers[i].getPassword() << "\n";
            
        }
        outFilew.close();
    }

    std::ofstream outFilecc("Categoriesinfo.txt");
    if (outFilecc.is_open()) {

        for (size_t i = 0; i < categories.size(); i++)
        {
            outFilecc << categories[i].getId() << ":" << categories[i].getName() << ":" << categories[i].getDescription() << "\n";

        }
        outFilecc.close();
    }

    std::ofstream outFilef("Feedinfo.txt");
    if (outFilef.is_open()) {

        for (size_t i = 0; i < supermarketfeed.size(); i++)
        {
            outFilef <<  supermarketfeed[i] << "\n";

        }
        outFilef.close();
    }

    std::ofstream outFilet("Transactionsinfo.txt");
    if (outFilet.is_open()) {

        for (size_t i = 0; i < transactions.size(); i++)
        {
            outFilet << transactions[i].getCashierId() << ":" << transactions[i].getTotalSum() << ":" << transactions[i].getReceiptFileName() << ":";
            outFilet << transactions[i].getDateTime() << "\n";

        }
        outFilet.close();
    }

    std::ofstream outFilep("Productsinfo.txt");
    if (outFilep.is_open()) {

        for (size_t i = 0; i < products.size(); i++)
        {
            outFilep << products[i]->getId() << ":" << products[i]->getName() << ":" << products[i]->getCategory().getName() << ":";
            outFilep << products[i]->getPrice() << ":" << products[i]->getType() << ":" << products[i]->getwhatsleft() << "\n";
        }
        outFilep.close();
    }

    std::ofstream outFileg("GiftCardsinfo.txt");
    if (outFileg.is_open()) {

        for (size_t i = 0; i < giftCards.size(); i++)
        {
            outFileg << giftCards[i]->getName() << ":" << giftCards[i]->getDiscount() << ":" << giftCards[i]->getCode() << ":";
            outFileg << giftCards[i]->printcategories() << "\n";
        }
        outFileg.close();
    }




    for (size_t i = 0; i < products.size(); i++) {
        delete products[i];
    }
    products.clear();
    for (size_t i = 0; i < giftCards.size(); i++) {
        delete giftCards[i];
    }
    giftCards.clear();
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
        MyString mid = m.getId();
        MyString feed = "A manager with id " + mid;
        supermarketfeed.pushBack(feed + " was added.");
       
    } else if (role == "cashier") {
        Cashier c(firstName, lastName, phoneNumber, age, password);
        addWaitingCashier(c);
        std::cout << "Cashier registration pending approval from a manager.\n";
        MyString cid = c.getId();
        MyString feed = "A cashier with id " + cid;
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
    std::cout << loggedInUser->getFirstName() << " " << loggedInUser->getLastName() << " logged out of the system .\n";
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
                MyString mid = managers[i].getId();
                MyString feed = "A manager with id " + mid;
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
                MyString cid = cashiers[i].getId();
                MyString feed = "A Cashier with id " + cid;
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
    std::cout << "Products :\n";
    for (size_t i = 0; i < products.size(); i++) {
        std::cout << "     " << (i + 1) << ". ";
        

        products[i]->print();
    }
}

void SuperMarketSystem::listProductsByCategory(int categoryId) const {
    int j = 1;
    for (size_t i = 0; i < products.size(); i++) {
        if (products[i]->getCategory().getId() == categoryId) {
            std::cout << "Products from category " << products[i]->getCategory().getName() << " :\n";
            break;
        }
    }
    for (size_t i = 0; i < products.size(); i++) {
        if (products[i]->getCategory().getId() == categoryId) {
           
            std::cout << "     " << (j++) << ". "; 
            products[i]->print();
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
    std::cout << "All transactions : \n";
    for (size_t i = 0; i < transactions.size(); i++) {
        transactions[i].print(i+1);
    }
}

void SuperMarketSystem::editCategory(int id) {
    bool iscategory = false;
    for (size_t i = 0; i < categories.size(); i++)
    {   
        if (categories[i].getId() == id) {

            std::cout << "Enter Category name: ";
            char buffer[100];
            std::cin.ignore();
            std::cin.getline(buffer, 100);

            MyString category(buffer);
            categories[i].setName(category);

            char desc[400];
            std::cout << "Enter category description: ";
            std::cin.ignore();
            std::cin.getline(desc, 400);
            MyString description(desc);
            categories[i].setDescription(desc);
            MyString lid = loggedInUser->getId();
            MyString feed = "A category was edited from a worker with id " + lid;
            supermarketfeed.pushBack(feed + " .");
            iscategory = true;
        }
    }
    
    if (iscategory == false) {
        std::cout << "Wrong Id!\n";
    }


}
//sell function
void SuperMarketSystem::sell() {

    Vector<int> productssell;
    Vector<double> quantity;
    Vector<double> discounts;
    int price = 0;
    MyString id ;
    double quantityofproduct = 0;
    bool transaction = true;
    MyString yesorno;
    MyString vouchername;
    bool rightvoucher = true;
    bool isthereaproduct = false;
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

            for (size_t i = 0; i < products.size() + 1; i++)
            {
                int intid = id.toInt();

                if (i == intid) {
                    isthereaproduct = true;
                    if (products[i - 1]->restock(-quantityofproduct)) {
                        price += products[i - 1]->getPrice() * quantityofproduct;
                        for (size_t j = 0; j < productssell.size(); j++)
                        {
                            if (productssell[j] == intid) {
                                quantity[j] += quantityofproduct;
                            }
                        }
                        productssell.pushBack(intid);
                        quantity.pushBack(quantityofproduct);
                        discounts.pushBack(0);
                        continue;
                    }
                    else {
                        std::wcout << std::endl << "---------\n\n";
                    }
                }

            }

            if (isthereaproduct == false){
                std::cout << "There is not a product with this id.\n";
            }

        }
        else if (id == "END") {
            transaction = false;
        }
    }
      
        std::cout << std::endl << "Add voucher: (Y/N)? ";
        std::cin >> yesorno;
            if(yesorno == "Y") {
                while (rightvoucher) {
                    std::cout << "Enter voucher:  ";
                    std::cin >> vouchername;
      
                    for (size_t i = 0; i < giftCards.size(); i++)
                    {
                        if (giftCards[i]->getCode() == vouchername) {
                            rightvoucher = false;
                            std::cout << std::endl;
                            giftCards[i]->print();
                            for (size_t p = 0; p < productssell.size(); p++)
                            {

                                for (size_t j = 0; j < products.size()+1; j++)
                                {
                                    if (j == productssell[p] ) {

                                        if (giftCards[i]->isApplicable(products[j-1]->getCategory().getName())) {
                                            double discount = quantity[p] * products[j-1]->getPrice()* giftCards[i]->getDiscount();
                                            price -= discount;
                                            discounts[p] = giftCards[i]->getDiscount();
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
                MyString transacnum = (transactions.size()+1);
                MyString receiptname = "receipt_" + transacnum;
                receiptname += ".txt";
                std::cout << std::endl << "Receipt saved as: " << receiptname << std::endl;
                std::cout << "Total: " << price << " lv." << std::endl << std::endl;
               
                Transaction T(loggedInUser->getId(), price, receiptname);
                transactions.pushBack(T);
                loggedInUser->addTransaction();
                
                std::ofstream outFile(receiptname.c_str());

                if (outFile.is_open()) {
                    
                  
                    outFile << "RECEIPT\n";
                    outFile << "TRANSACTION_ID: " << transactions.size() << "\n";
                    outFile << "CASHIER_ID: " << loggedInUser->getId();
                    outFile << "\n" << transactions[transactions.size() - 1].getDateTime();
                    outFile << "\n" << "-----------------------------\n\n";

                    
                    for (size_t i = 0; i < productssell.size(); i++)
                    {
                        for (size_t j = 0; j < products.size()+1; j++)
                        {
                            int idofaproduct = productssell[i]-1;
                            if (j == productssell[i]) {
                             
                                outFile << products[idofaproduct]->getName() << " \n";
                          
                                MyString priceee = products[idofaproduct]->getPrice();
                                outFile << quantity[i] << " * " << priceee << " - ";
            
                                outFile << quantity[i] * (products[idofaproduct]->getPrice() - products[idofaproduct]->getPrice()*discounts[i]);

                                outFile << "\n\n" << "###\n\n";
                            }
                            
                        }
                        outFile << "TOTAL: " << price;
                    }
                   
                    outFile.close();
                }
                MyString lid = loggedInUser->getId();
                MyString feed = "A cashier with id " + lid;
                supermarketfeed.pushBack(feed + " made a sell!");
}

bool SuperMarketSystem::isaCashierloggedin()const {
    if (loggedInUser == nullptr) {
        return false;
    }
    else if (loggedInUser->getRole() == "Cashier") {
        return true;
    }
    else if (loggedInUser->getRole() == "Manager") {
        return false;
    }
}
//Manager part
bool SuperMarketSystem::isaManagerloggedin()const {
    if (loggedInUser == nullptr) {
        return false;
    }
    else if (loggedInUser->getRole() == "Manager") {
        return true;
    }
    else if(loggedInUser->getRole() == "Cashier"){
        return false;
    }
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
                MyString lid = loggedInUser->getId();
                MyString feed = "A manager with id " + lid;
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
                std::cout << "Manager declined cashier with id " << cashierId << " .\n";
                MyString lid = loggedInUser->getId();
                MyString feed = "A manager with id " + lid;
                supermarketfeed.pushBack(feed + " declined a cashier!");
                return true;
            }
        }
        std::cout << "There is not a cashier with this id in the waiting list.\n";
    }
    else {
        std::cout << "Wrong code!\n";
    }
    return false;
}

void SuperMarketSystem::listWarnedCashiers(int minPoints) const {
    std::cout << "Warned Cashiers with at least " << minPoints << " points :\n";
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
            cashiers[i].addWarning(newwarning);

            std::cout << "A cashier with id " << cashierId << " was warned.\n";
            MyString lid = loggedInUser->getId();
            MyString feed = "A manager with id " + lid;
            feed += " warned a cashier with id ";
            MyString cid = cashierId;
            feed += cid;
            supermarketfeed.pushBack(feed + ".");
        }
    }
    return false;
}

bool SuperMarketSystem::promoteCashier(int cashierId, const MyString& specialCode) {
    if (loggedInUser->getSpecialCode() == specialCode) {
        for (size_t i = 0; i < cashiers.size(); i++) {
            if (cashiers[i].getId() == cashierId) {
                Manager m(cashiers[i].getId(),cashiers[i].getFirstName(), cashiers[i].getLastName(),
                    cashiers[i].getPhone(), cashiers[i].getAge(), cashiers[i].getPassword());

                managers.pushBack(m);
                cashiers[i] = cashiers[cashiers.size() - 1];
                cashiers.popBack();
                std::cout << "A cashier was promoted to manager successfully!\n" << "Special code: " << m.getSpecialCode() << "\n";
                std::cout << "Code: " << m.getId() << "_special_code.txt\n";

                MyString lid = loggedInUser->getId();
                MyString feed = "A manager with id " + lid;
                feed += " promoted a cashier with id ";
                MyString cid = cashierId;
                feed += cid;
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
                std::cout << "A manager with id " << loggedInUser->getId() << " fired a cashier with id " << cashierId << " .\n";

                MyString lid = loggedInUser->getId();
                MyString feed = "A manager with id " + lid;
                feed += " fired a cashier with id ";
                MyString cid = cashierId;
                feed += cid;
                supermarketfeed.pushBack(feed + ".");
                return true;
            }
        }
        std::cout << "No cashier with that id , if you tried to fire a manager you can not.\n";
    }
    return false;
}

bool SuperMarketSystem::addCategory(const MyString& name, const MyString& description) {

    for (size_t i = 0; i < categories.size(); i++) {
        if (categories[i].getName() == name) {
            std::cout << "There is already a category with this name.";
            

            MyString lid = loggedInUser->getId();
            MyString feed = "A manager with id " + lid;
            feed += " tried to add a new category ";
            feed += name.c_str();
            supermarketfeed.pushBack(feed + " but there was already one like that.");
            return false;
        }
    }

    categories.pushBack(Category(name, description));
    MyString lid = loggedInUser->getId();
    std::cout << "Manager with id " << lid << " added new category " << name << " .\n";
    MyString feed = "A manager with id " + lid;
    feed += " added a new category ";
    feed += name.c_str();
    supermarketfeed.pushBack(feed + ".");
    return true;
}

bool SuperMarketSystem::deleteCategory(int categoryId) {
    for (size_t i = 0; i < products.size(); i++) {
        if (products[i]->getCategory().getId() == categoryId) {
            std::cout << "You first have to delete all the products from this category to be able to delete it.\n";
            MyString lid = loggedInUser->getId();
            MyString feed = "A manager with id " + lid;
            feed += " tried to delete category ";
            feed += categories[categoryId].getName();
            supermarketfeed.pushBack(feed + " but there were products from this category.");
            return false; 
        }
    }

    for (size_t i = 0; i < categories.size(); ++i) {
        if (categories[i].getId() == categoryId) {

            MyString lid = loggedInUser->getId();
            MyString feed = "A manager with id " + lid;
            feed += " deleted category ";
            MyString cname = categories[i].getName();
            feed = feed + cname;
            supermarketfeed.pushBack(feed + ".");
            std::cout << "A manager with id " << lid << " deleted category " << cname << " .\n";
            categories[i] = categories[categories.size() - 1];
            categories.popBack();
            return true;
        }
    }
    return false;
}

void SuperMarketSystem::addProductFromConsole(const MyString& productType) {
    double price;
    double quantity;

    char buffer[100];

    std::cout << "Enter product name: ";
    std::cin.ignore();
    std::cin.getline(buffer, 100);

    MyString name =buffer;
    

    std::cout << "Enter product category: ";
    std::cin.getline(buffer, 100);
    MyString categoryName = buffer;


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

        Product* p = new ProductsByWeight(name, categories[categoryId-1], price, quantity);
        products.pushBack(p);

    }
    else if (productType == "product_by_unit") {
        std::cout << "Enter price per unit: ";
        std::cin >> price;

        std::cout << "Enter quantity (units): ";
        std::cin >> quantity;

        Product* p = new ProductsByUnit(name, categories[categoryId-1], price, static_cast<int>(quantity));
        products.pushBack(p);

    }
    else {
        std::cout << "Unknown product type: " << productType << '\n';
        return;
    }

    std::cout << "Product \"" << name << "\" added successfully under category \"" << categoryName << "\"\n";\
        MyString lid = loggedInUser->getId();
    MyString feed = "A manager with id " + lid;
    feed += " added a new product ";
    feed += name.c_str();
    supermarketfeed.pushBack(feed + ".");
}

bool SuperMarketSystem::deleteProduct(int productId) {
    for (size_t i = 0; i < products.size(); ++i) {
        if (products[i]->getId() == productId) {

            MyString lid = loggedInUser->getId();
            MyString feed = "A manager with id " + lid;
            feed += " deleted a product ";
            feed += products[i]->getName();
            supermarketfeed.pushBack(feed + " .");
            std::cout << "A manager with id " << lid << " deleted a product with id" << productId << " .\n";
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
    char buffer[200];
   
    while (file.getline(buffer, 200)) {
        MyString line = buffer;
        
        MyString segment;
        Vector<MyString> tokens;

        int count = 0;
        int symbol = 0;
        for (size_t i = 0; i < line.getSize(); i++)
        {
            if (line[i] != ':') {
                count++;
            }
            else {
                segment = line.substr(symbol, count);
                symbol += count + 1;
                line.substr(symbol, 1);
     
                tokens.pushBack(segment);
             
                segment = "";
                count = 0;
            }
        }
        segment = line.substr(symbol, count);
        tokens.pushBack(segment);

        if (tokens[0] == MyString("NEW")) {


            if (tokens.size() < 6) {
                std::cout << "Invalid NEW product format.\n";
                continue;
            }
            bool istherethisproduct = false;
            for (size_t i = 0; i < products.size(); i++)
            {
                if (products[i]->getName() == tokens[2]) {
                    std::cout << "There is already a product with this name .\n";
                    istherethisproduct = true;
                }
            }
            if (istherethisproduct) {
                continue;
            }
                    

            MyString type = tokens[1];

            if (type == "by_unit") {
                // NEW:by_unit:<name>:<category>:<price>:<quantity>
                MyString name = tokens[2];
                MyString category = tokens[3];
                double price = tokens[4].toDouble();
                int quantity = tokens[5].toInt();
                bool isthereacategory = false;
                for (size_t i = 0; i < categories.size(); i++)
                {
                  
                    if (categories[i].getName() == category) {
                        Category categoryproduct = categories[i];
                        Product* p = new ProductsByUnit(name, categoryproduct, price, quantity);
                        isthereacategory = true;
                        products.pushBack(p);
                    }
                }

                if (isthereacategory == false) {
                    Category c(category, "random description");
                    categories.pushBack(c);
                    Product* p = new ProductsByUnit(name, c, price, quantity);
                    products.pushBack(p);
                }
                 
                std::cout << "Added new product \"" << name << "\"\n";
            }
            else if (type == "by_weight") {
                // NEW:by_weight:<name>:<category>:<price>:<weight>
                MyString name = tokens[2];
                MyString category = tokens[3];
                double price = tokens[4].toDouble();
                double weight = tokens[5].toInt();
                bool isthereacategory = false;

                for (size_t i = 0; i < categories.size(); i++)
                {
                    if (categories[i].getName() == category) {
                        Category categoryproduct = categories[i];
                        Product* p = new ProductsByWeight(name, categoryproduct, price, weight);
                        isthereacategory = true;
                        products.pushBack(p);
                    }
                }
                if (isthereacategory == false) {
                    Category c(category, "random description");
                    Product* p = new ProductsByWeight(name, c, price, weight);
                    products.pushBack(p);
                }
                std::cout << "Added new product \"" << name << "\"\n";
            }
            else {
                std::cout << "Unknown product type in NEW: " << type << "\n";
            }
        }
        else {
            // <product_type>:<id>:<quantity>
            if (tokens.size() < 3) {
                std::cout << "Invalid product restock format.\n";
                continue;
            }

            int id = tokens[1].toInt();
            int quantity = tokens[2].toInt();
            bool foundtheproduct = false;

            for (size_t i = 0; i < products.size(); i++)
            {
                if (products[i]->getId() == id) {
                    products[i]->restock(quantity);
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

   
    MyString feed = "A restock happened and added more products ";

    supermarketfeed.pushBack(feed);

    file.close();
    return true;

}

bool SuperMarketSystem::loadGiftCardsFromFile(const MyString& filename) {

    std::ifstream file(filename.c_str());

    if (!file.is_open()) {
        std::cout << "Failed to open file: " << filename << '\n';
        return false;
    }

    char buffer[200];
    
    while (file.getline(buffer, 200)) {

        MyString line = buffer;

        MyString segment;
        Vector<MyString> tokens;

        int count = 0;
        int symbol = 0;
        for (size_t i = 0; i < line.getSize(); i++)
        {
            if (line[i] != ':') {
                count++;
            }
            else {
                segment = line.substr(symbol, count);
                symbol += count + 1;
                line.substr(symbol, 1);

                tokens.pushBack(segment);

                segment = "";
                count = 0;
            }
        }
        segment = line.substr(symbol, count);
        tokens.pushBack(segment);

        MyString typeofgiftcard = tokens[0];

        if (typeofgiftcard == "SingleCategory") {
            //type:category:percent
            if (tokens.size() < 3) {
                std::cout << "Invalid SingleGiftCard format.\n";
                continue;
            }

            double discount = tokens[2].toDouble()/100;
            MyString category = tokens[1];
           
            GiftCard* sc = new SingleCategoryGiftCard(discount,category);
            giftCards.pushBack(sc);
            std::cout << "Added new giftcard with code " << sc->getCode() << " !\n";
            
        }
        else if (typeofgiftcard == "AllProductsCategory") {
            if (tokens.size() < 2) {
                std::cout << "Invalid AllProductsCategory format.\n";
                    continue;
            }
            double discount = tokens[1].toDouble()/100;
            GiftCard * ap = new AllProductsGiftCard(discount);
            giftCards.pushBack(ap);
            std::cout << "Added new giftcard with code " << ap->getCode() << " !\n";
            
        }
        else if (typeofgiftcard == "MultipleGiftCard") {
            int count = tokens[1].toInt();

            if (tokens.size() < 3 + count) {
                std::cout << "Invalid MultipleGiftCard format.\n";
                continue;
            }

            double discount = tokens[tokens.size()-1].toDouble()/100;
            Vector<MyString> multiplecategories;
            for (size_t i = 0; i < count; i++)
            {
                MyString currentcat = tokens[i + 2];
                multiplecategories.pushBack(currentcat);
            }
            GiftCard* mc = new MultipleCategoryGiftCard(discount,multiplecategories);
            giftCards.pushBack(mc);
            std::cout << "Added new giftcard with code " << mc->getCode() << " !\n";
            
        }
        else {
            std::cout << "Wrong GiftCard Type.\n";
        }
      
    }

    MyString feed = "A restock happened and added more giftcards ";

    supermarketfeed.pushBack(feed);

    file.close();
    return true;

}