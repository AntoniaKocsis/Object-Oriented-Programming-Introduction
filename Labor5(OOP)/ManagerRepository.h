#include "Manager.h"
#include <vector>
#pragma once

using namespace manager;
using namespace std;

namespace ManagerRepo {
    class ManagerRepository {
    private:
        vector<Manager> managerRepo;
    public:
        ManagerRepository();

        void updateDatabase();

        void add(Manager manager);

        void remove(Manager manager);

        vector<Manager> getAll();
    };
}