#include "FruitRepo.h"
#include <fstream>
#include <sstream>

using namespace Repository;
using namespace Domain;

FruitRepo::FruitRepo() {
    /** Open file "Deposit"
     * Check if file is empty, if file is empty, create an empty repository
     * Else, go through each line of the file(csv file); create objects, add to repository**/

    ifstream file;
    file.open("Deposit");
    if (file.peek() == std::ifstream::traits_type::eof())
        this->fruitRepo = {};
    else {
        string line;
        string name, origin, expirationDate;
        int price, quantity;
        std::vector<std::string> words;
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string word;
            while (std::getline(ss, word, ',')) {
                words.push_back(word);
            }
            name = words[0];
            origin = words[1];
            expirationDate = words[2];
            price = stoi(words[3]);
            quantity = stoi(words[4]);
            Fruit fruit(name, origin, expirationDate, price, quantity);
            fruitRepo.push_back(fruit);
            words.clear(); // clear the vector for the next line
        }

    }

}

void FruitRepo::updateDeposit() {
    /** After every add/remove operation update file "Deposit" **/
    /** Fruits are sorted after attribute name **/
    sort(fruitRepo.begin(), fruitRepo.end());
    ofstream file;
    file.open("Deposit");
    for (int i = 0; i < fruitRepo.size(); i++) {
        file << fruitRepo[i].getName() << ',';
        file << fruitRepo[i].getOrigin() << ',';
        file << fruitRepo[i].getExpirationDate() << ',';
        file << fruitRepo[i].getPrice() << ',';
        file << fruitRepo[i].getQuantity() << endl;
    }
}

void FruitRepo::addFruit(Fruit fruit) {
    /** If fruit is already in the repository => update quantity
     * else simply add fruit to repository**/
    bool found = false;
    for (int i = 0; i < fruitRepo.size(); i++)
        if (fruitRepo[i].getName() == fruit.getName() && fruitRepo[i].getOrigin() == fruit.getOrigin()) {
            found = true;
            int oldQuantity = fruitRepo[i].getQuantity();
            int newQuantity = oldQuantity + fruit.getQuantity();
            fruitRepo[i].setQuantity(newQuantity);
            break;

        }
    if (!found)
        this->fruitRepo.push_back(fruit);
    updateDeposit();

}

void FruitRepo::deleteFruit(Fruit fruit) {
    /** If fruit was found => delete fruit
     * Else throw exception **/
    bool found = false;
    for (int i = 0; i < fruitRepo.size(); i++)
        if (fruitRepo[i].getName() == fruit.getName() && fruitRepo[i].getOrigin() == fruit.getOrigin()) {
            fruitRepo.erase(fruitRepo.begin() + i);
            found = true;
            break;
        }
    if (found)
        updateDeposit();
    else {
        throw invalid_argument("Item was not found!");
    }

}

vector<Fruit> FruitRepo::getAll() {
    /** Return vector of fruits**/
    return fruitRepo;
}