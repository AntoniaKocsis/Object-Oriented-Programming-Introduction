#include <iostream>
#include <vector>
#pragma once
using namespace std;
namespace Domain {
    class Fruit {
    private:
        string name;
        int price;
        string origin;
        string expirationDate;
        int quantity;

    public:

        Fruit(string name, string origin, string expirationDate, int price, int quantity);

        Fruit(string name, string origin);

        string getName() const;

        string getOrigin() const;

        string getExpirationDate() const;

        int getPrice() const;

        int getQuantity();

        void setName(string name);

        void setOrigin(string origin);

        void setExpirationDate(string expirationDate);

        void setPrice(int price);

        void setQuantity(int quantity);

        // Overload < operator
        bool operator<(const Fruit &other) const {
            return name < other.name;
        }

        // Overload > operator
        bool operator>(const Fruit &other) const {
            return name > other.name;
        }

        // Overload <= operator
        bool operator<=(const Fruit &other) const {
            return !(*this > other);
        }

        // Overload >= operator
        bool operator>=(const Fruit &other) const {
            return !(*this < other);
        }
    };

}