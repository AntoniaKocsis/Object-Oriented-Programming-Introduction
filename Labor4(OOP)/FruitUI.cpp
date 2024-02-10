#include "FruitUI.h"

using namespace UI;
FruitUI::FruitUI(shared_ptr<FruitController> contr) {
    controller = contr;
}
void FruitUI::menu() {
    int choice;
    bool running = true;
    string option;

    while (running) {
        cout<<endl;
        cout << "**************************************  MENU  ****************************************\n";
        cout <<endl;
        cout << " 1 - Show Inventory \n";
        cout << " 2 - Search for a specific item \n";
        cout << " 3 - Track stock \n";
        cout << " 4 - Track expiration dates \n";
        cout << " 5 - Add item \n";
        cout << " 6 - Remove item \n";
        cout << " 7 - Exit\n";
        cout << " Enter your choice and press return: ";
        cout << endl;

        cin >> choice;

        switch (choice) {
            case 1:
                showAll();
                cout << endl;
                cout << "Is there any other operation you wold like to perform? (yes / no)";
                cin >> option;
                if (option == "no")
                    running = false;
                option.clear();

                break;
            case 2:
                showFiltered();
                cout << endl;
                cout << "Is there any other operation you wold like to perform? (yes / no)";
                cin >> option;
                if (option == "no")
                    running = false;
                option.clear();
                break;
            case 3:
                cout << endl;
                showAlmostEmpty();
                cout << "Is there any other operation you wold like to perform? (yes / no)";
                cin >> option;
                if (option == "no")
                    running = false;
                option.clear();
                break;
            case 4:
                cout << endl;
                showExpirationDate();
                cout << "Is there any other operation you wold like to perform? (yes / no)";
                cin >> option;
                if (option == "no")
                    running = false;
                option.clear();
                break;
            case 5:
                cout << endl;
                addFruit();
                cout << "Is there any other operation you wold like to perform? (yes / no)";
                cin >> option;
                if (option == "no")
                    running = false;
                option.clear();
                break;
            case 6:
                cout << endl;
                deleteFruit();
                cout << "Is there any other operation you wold like to perform? (yes / no)";
                cin >> option;
                if (option == "no")
                    running = false;
                option.clear();
                break;
            case 7:
                cout << "";
                running = false;
                break;
            default:
                cout << "Not a Valid Choice. \n";
                cout << "Choose again.\n";
                cin >> choice;
                break;
        }

    }

}

void FruitUI::printVector(vector<Fruit> vector1) {
    for (int i = 0; i < vector1.size(); i++) {
        cout << endl;
        cout << "Name: " << vector1[i].getName() << "  Origin: " << vector1[i].getOrigin() << "  Expiration Date: "
             << vector1[i].getExpirationDate() << "  Price: " << vector1[i].getPrice() << "  Quantity: "
             << vector1[i].getQuantity();
        cout << endl;
    }
}

void FruitUI::showAll() {
    cout << endl;
    cout << "-------------------------------------- ITEMS -----------------------------------------";
    vector<Fruit> vector1 = controller->showAll();
    printVector(vector1);

}

void FruitUI::showAlmostEmpty() {
    cout << endl;
    cout << "-------------------------------------- TRACKING STOCK -----------------------------------------";
    cout << endl;
    cout << "Please enter a reference value: " << endl;
    int value;
    cin >> value;
    vector<Fruit> vector1 = controller->stock(value);
    printVector(vector1);
}

void FruitUI::showExpirationDate() {
    cout << endl;
    cout << "-------------------------------------- EXPIRATION DATES -----------------------------------------";
    cout << endl;
    vector<Fruit> vector1 = controller->sortedExpirationDate();
    printVector(vector1);
}

void FruitUI::showFiltered() {
    cout << endl;
    cout << "-------------------------------------- FILTERED SEARCH -----------------------------------------";
    cout << endl;
    string str;
    cout << "Please enter the search criteria";
    cin >> str;
    vector<Fruit> vector1 = controller->findFruits(str);
    printVector(vector1);
}

void FruitUI::addFruit() {
    cout << endl;
    cout << "-------------------------------------- ADDING ITEM -----------------------------------------";
    cout << endl;
    string name, origin, expirationDate;
    int price, quantity;
    cout << "Name: " << endl;
    cin >> name;
    cout << "Origin: " << endl;
    cin >> origin;
    cout << "Expiration Date (Please use this format: day/month/year): " << endl;
    cin >> expirationDate;
    cout << "Price: " << endl;
    cin >> price;
    cout << "Quantity: " << endl;
    cin >> quantity;
    cout << "Adding item.." << endl;
    controller->addFruit(name, origin, expirationDate, price, quantity);
    cout << "Item was added succesfully.." << endl;

}

void FruitUI::deleteFruit() {
    cout << endl;
    cout << "-------------------------------------- REMOVING ITEM -----------------------------------------";
    cout << endl;
    string name, origin;
    cout << "Name: " << endl;
    cin >> name;
    cout << "Origin: " << endl;
    cin >> origin;
    cout << "Removing item.." << endl;
    try {
        controller->deleteFruit(name, origin);
        cout << "Item was removed succesfully.." << endl;
    }
    catch (exception &e) {
        cout << "Item was not found. Please try again" << endl;
        deleteFruit();
    }

}
