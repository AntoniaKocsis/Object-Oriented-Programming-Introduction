#include "FruitRepo.h"
#include <vector>
#pragma once
using namespace Repository;
using namespace Domain;

#include <memory>

namespace Controller {

    struct Date {
        int day, month, year;
    };

    class FruitController {
    private:
        shared_ptr<FruitRepo> repository;
    public:
        FruitController(shared_ptr<FruitRepo> repo);
        void addFruit(string name, string origin, string expirationDate, int price, int quantity);

        void deleteFruit(string name, string origin);

        vector<Fruit> findFruits(string str);

        vector<Fruit> showAll();

        vector<Fruit> stock(int quantity);

        static vector<Date> getDates(const Fruit &f1, const Fruit &f2);

        bool compare(const Fruit &f1, const Fruit &f2);

        vector<Fruit> sortedExpirationDate();


    };
}
