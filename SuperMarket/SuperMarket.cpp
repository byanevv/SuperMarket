// SuperMarket Borislav  Yanev

#include <iostream>
#include "SuperMarketSystem.h"
#include "MyString.h"
#include "Vector.hpp"
#include <cstdlib>
#include <ctime>

MyString removethings(MyString word) {
    MyString newword = word.substr(1,word.getSize()-2);
    
    return newword;
}

int main()
{
    std::srand(std::time(nullptr));
    SuperMarketSystem supermarket;

	std::cout << "Welcome to FMI Supermarket Management System 2024-2025!" << std::endl;
	std::cout << "Please choose an action: \n\n" ;
    supermarket.registerUser("manager","Borislav","Yanev","0955959454",20,"skib");
    supermarket.registerUser("cashier", "sasho", "toaletna", "5454545", 10, "debel");

	MyString command;
	while (true) {
		std::cout << "> ";
		std::cin >> command;
        if (command == "register") {
            MyString role, firstname, lastname, phonenumber, age, password;
            //register <manager> <Hiks> <hikskov> <0998989> <20> <password>
            std::cin >> role >> firstname >> lastname >> phonenumber >> age >> password;
            role = removethings(role);
            firstname = removethings(firstname);
            lastname = removethings(lastname);
            phonenumber = removethings(phonenumber);
            age = removethings(age);
            int newage = age.toInt();
            password = removethings(password);
            supermarket.registerUser(role,firstname,lastname,phonenumber, newage,password);

        }
        else if (command == "login") {
            MyString id, password;
            std::cin >> id >> password;
            id = removethings(id);
            int newid = id.toInt();
            password = removethings(password);
            supermarket.login(newid,password);

        }
        else if (command == "list-user-data") {
            supermarket.listUserData();
        }
        else if (command == "list-workers") {
            supermarket.listWorkers();
        }
        else if (command == "list-products") {
            supermarket.listProducts();
        }
        else if (command == "list-products-bycategory") {
            MyString category;
            std::cin >> category;
            category = removethings(category);

            int newacategoryid = category.toInt();

            supermarket.listProductsByCategory(newacategoryid);
        }
        else if (command == "list-feed") {
            supermarket.listFeed();
        }
        else if (command == "list-transactions") {
            supermarket.listTransactions();
        }
        else if (command == "leave") {
            supermarket.leave();
        }
        else if (command == "logout") {
            supermarket.logout();
        }
        else if (command == "edit-category") {
            MyString id;
            std::cin >> id;
            id = removethings(id);
            int newid = id.toInt();
            
            supermarket.editCategory(newid);
        }
        else if(command == "sell")
        {
            std::cout << std::endl;

            if (supermarket.isaCashierloggedin()) {
                supermarket.sell();
            }
            else {
                std::cout << "A cashier has to be logged in so he can make a sell. \n";
            }
        }
        else if (command == "list-pending") {
            if (supermarket.isaManagerloggedin()) {
                supermarket.listPendingCashiers();
            }
            else {
                std::cout << "A manager can only access this command!\n";
            }
                
        }
        else if (command == "approve") {
            if (supermarket.isaManagerloggedin()) {
                MyString id, specialcode;
                std::cin >> id >> specialcode;
                id = removethings(id);
                int newid = id.toInt();
                specialcode = removethings(specialcode);
                supermarket.approveCashier(newid, specialcode);
            }
            else {
                std::cout << "A manager can only access this command!\n";
            }

        }
        else if (command == "decline") {
            if (supermarket.isaManagerloggedin()) {
                MyString id, specialcode;
                std::cin >> id >> specialcode;
                id = removethings(id);
                int newid = id.toInt();
                specialcode = removethings(specialcode);
                supermarket.declineCashier(newid, specialcode);
            }
            else {
                std::cout << "A manager can only access this command!\n";
            }

        }
        else if (command == "list-warned-cashiers") {
            if (supermarket.isaManagerloggedin()) {
                MyString points;
                std::cin >> points;
                points = removethings(points);
                int newpoints = points.toInt();

                supermarket.listWarnedCashiers(newpoints);
            }
            else {
                std::cout << "A manager can only access this command!\n";
            }

        }
        else if (command == "warn-cashier") {
            if (supermarket.isaManagerloggedin()) {
                MyString id,points;
                std::cin >> id >> points;
                id = removethings(id);
                int newid = id.toInt();
                points = removethings(points);
                int newpoints = points.toInt();
                if (newpoints % 100 != 0) {
                    std::cout << "Not the right ammount ot points for a warning.\n";
                    continue;
                }

            supermarket.warnCashier(newid,newpoints);
            }
            else {
                std::cout << "A manager can only access this command!\n";
            }
        }
        else if (command == "promote-cashier") {
            if (supermarket.isaManagerloggedin()) {

                MyString id, specialcode;
                std::cin >> id >> specialcode;
                id = removethings(id);
                int newid = id.toInt();
                specialcode = removethings(specialcode);
                supermarket.promoteCashier(newid, specialcode);
            }
            else {
                std::cout << "A manager can only access this command!\n";
            }
        }
        else if (command == "fire-cashier") {
            if (supermarket.isaManagerloggedin()) {

                MyString id, specialcode;
                std::cin >> id >> specialcode;
                id = removethings(id);
                int newid = id.toInt();
                specialcode = removethings(specialcode);
                supermarket.fireCashier(newid, specialcode);
            }
            else {
                std::cout << "A manager can only access this command!\n";
            }
        }
        else if (command == "add-category") {
            if (supermarket.isaManagerloggedin()) {

                MyString catname,catdescription;
                std::cin >> catname >> catdescription;
                catname = removethings(catname);
                
                catdescription = removethings(catdescription);
                supermarket.addCategory(catname,catdescription);
            }
            else {
                std::cout << "A manager can only access this command!\n";
            }
        }
        else if (command == "delete-category") {
            if (supermarket.isaManagerloggedin()) {

                MyString id;
                std::cin >> id;
                id = removethings(id);

                int newid = id.toInt();

                supermarket.deleteCategory(newid);
            }
            else {
                std::cout << "A manager can only access this command!\n";
            }
        }
        else if (command == "add-product") {
            if (supermarket.isaManagerloggedin()) {

                MyString producttype;
                std::cin >> producttype;
                producttype = removethings(producttype);
            
                supermarket.addProductFromConsole(producttype);
            }
            else {
                std::cout << "A manager can only access this command!\n";
            }
        }
        else if (command == "delete-product") {
            if (supermarket.isaManagerloggedin()) {

                MyString id;
                std::cin >> id;
                id = removethings(id);

                int newid = id.toInt();

                supermarket.deleteProduct(newid);
            }
            else {
                std::cout << "A manager can only access this command!\n";
            }
        }
        else if (command == "load-products") {
            if (supermarket.isaManagerloggedin()) {

                MyString filename;
                std::cin >> filename;
                filename = removethings(filename);

                supermarket.loadProductsFromFile(filename);
            }
            else {
                std::cout << "A manager can only access this command!\n";
            }
        }
        else if (command == "load-gift-cards") {
            if (supermarket.isaManagerloggedin()) {

                MyString filename;
                std::cin >> filename;
                filename = removethings(filename);

                supermarket.loadGiftCardsFromFile(filename);
            }
            else {
                std::cout << "A manager can only access this command!\n";
            }
        }
        else if (command == "END") {
            break;
        }
        else {
            std::cout << "Unknown command.\n";
        }
	
	}

}
