#include <iostream>
#pragma once
#include <memory>
#include "FruitRepo.h"
#include "Controller.h"
using namespace std;
using namespace Controller;
namespace Test {
    class Tests {
    private:
        shared_ptr<FruitController> controller;
    public:
        Tests(shared_ptr<FruitController> contr);
        void testAdd();
        void testRemove();
        void testFiltered();
        void testTrackStock();
        void testExpirationDate();
        void testAll();
    };
}