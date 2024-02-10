#include "Controller.h"
#include <sstream>

using namespace Controller;
using namespace std;

FruitController::FruitController(shared_ptr<FruitRepo> repo) {
    repository = repo;
}

void FruitController::addFruit(string name, string origin, string expirationDate, int price, int quantity) {
    /** Create an object of type fruit and call add function from Repository**/
    Fruit fruit(name, origin, expirationDate, price, quantity);
    repository->addFruit(fruit);
}

void FruitController::deleteFruit(string name, string origin) {
    /** Create an object of type fruit and call delete function from Repository**/
    Fruit fruit(name, origin);
    repository->deleteFruit(fruit);
}

vector<Fruit> FruitController::findFruits(string str) {
    /** Find all fruits containing a string(fruits need to be sorted)**/
    /** If string is empty return all fruits **/
    vector<Fruit> fruits = repository->getAll();
    if (!str.empty()) {
        vector<Fruit> filtered;
        for (int i = 0; i < fruits.size(); i++) {
            string s1 = fruits[i].getName();
            string s2 = str;
            if (s1.find(s2) != string::npos)
                filtered.push_back(fruits[i]);
        }
        sort(filtered.begin(), filtered.end());
        return filtered;
    }
    sort(fruits.begin(), fruits.end());
    return fruits;

}

vector<Fruit> FruitController::showAll() {
    /** Get all fruits from "Deposit"**/
    vector<Fruit> fruits = repository->getAll();
    sort(fruits.begin(), fruits.end());
    return fruits;
}

vector<Fruit> FruitController::stock(int quantity) {
    /** Get all fruits with lower quantity than the given param.**/
    vector<Fruit> fruits = repository->getAll();
    vector<Fruit> stock;
    for (auto &fruit: fruits)
        if (fruit.getQuantity() < quantity)
            stock.push_back(fruit);
    return stock;
}

vector<Date> FruitController::getDates(const Fruit &f1, const Fruit &f2) {
    /** Convert the date of the fruits given as a string, into a Date(struct)**/
    string expirationDate1 = f1.getExpirationDate();
    string expirationDate2 = f2.getExpirationDate();
    string day1, day2, month1, month2, year1, year2;
    stringstream s1(expirationDate1);
    stringstream s2(expirationDate2);
    getline(s1, day1, '/');
    getline(s2, day2, '/');
    getline(s1, month1, '/');
    getline(s2, month2, '/');
    getline(s1, year1);
    getline(s2, year2);
    Date d1, d2;
    d1.day = stoi(day1);
    d2.day = stoi(day2);
    d1.month = stoi(month1);
    d2.month = stoi(month2);
    d1.year = stoi(year1);
    d2.year = stoi(year2);
    vector<Date> dates;
    dates.push_back(d1);
    dates.push_back(d2);
    return dates;

}

bool FruitController::compare(const Fruit &f1, const Fruit &f2) {
    /** Create vector  of dates and compare them**/
    vector<Date> dates = getDates(f1, f2);
    Date date1 = dates[0];
    Date date2 = dates[1];
    if (date1.year < date2.year)
        return true;
    if (date1.year > date2.year)
        return false;
    if (date1.year == date2.year) {
        if (date1.month < date2.month)
            return true;
        if (date1.month > date2.month)
            return false;
        if (date1.day == date2.day || date1.day < date2.day)
            return true;
        return false;
    }

}

vector<Fruit> FruitController::sortedExpirationDate() {
    /** Sort fruit after expiration date **/
    vector<Fruit> fruits = repository->getAll();
    for (int i = 0; i < fruits.size(); i++) {
        for (int j = 0; j < fruits.size(); j++) {
            if (compare(fruits[i], fruits[j]))
                swap(fruits[i], fruits[j]);
        }
    }
    return fruits;
}