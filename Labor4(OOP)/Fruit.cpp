#include "Fruit.h"

using namespace Domain;


Fruit::Fruit(string name, string origin, string expirationDate, int price, int quantity) {
    this->name = name;
    this->origin = origin;
    this->expirationDate = expirationDate;
    this->price = price;
    this->quantity = quantity;

}

Fruit::Fruit(string name, string origin) {
    this->name = name;
    this->origin = origin;
}

string Fruit::getName() const { return name; }

string Fruit::getExpirationDate() const { return expirationDate; }

string Fruit::getOrigin() const { return origin; }

int Fruit::getPrice() const { return price; }

int Fruit::getQuantity() { return quantity; }

void Fruit::setName(string name) { this->name = name; }

void Fruit::setExpirationDate(string expirationDate) { this->expirationDate = expirationDate; }

void Fruit::setOrigin(string origin) { this->origin = origin; }

void Fruit::setPrice(int price) { this->price = price; }

void Fruit::setQuantity(int quantity) { this->quantity = quantity; }

