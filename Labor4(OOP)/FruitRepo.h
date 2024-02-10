#include "Fruit.h"
#pragma once
using namespace Domain;
namespace Repository {
    class FruitRepo {
    private:
        vector<Fruit> fruitRepo;
    public:
        FruitRepo();

        void addFruit(Fruit fruit);

        void deleteFruit(Fruit fruit);

        void updateDeposit();

        vector<Fruit> getAll();
    };

}