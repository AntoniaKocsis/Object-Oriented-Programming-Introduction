#include "UserController.h"

#include <utility>

using namespace userController;

UserController::UserController(shared_ptr<ClientRepository> clientRepo, shared_ptr<ManagerRepository> managerRepo) {
    clientRepository = clientRepo;
    managerRepository = managerRepo;
}

void UserController::addClient(const string &username, const string &password) {
    Client client(username, password);
    clientRepository->add(client);
}

void UserController::addManager(const string &username, const string &password) {
    Manager manager(username, password);
    managerRepository->add(manager);
}

void UserController::removeClient(const string &username, const string &password) {
    Client client(username, password);
    clientRepository->remove(client);

}

void UserController::removeManager(const string &username, const string &password) {
    Manager manager(username, password);
    managerRepository->remove(manager);
}

bool UserController::checkClientAccount(const string &username, const string &password) {
    vector<Client> clients = clientRepository->getAll();
    for (auto &client: clients)
        if (client.getUsername() == username && client.getPassword() == password)
            return true;
    return false;
}

bool UserController::checkManagerAccount(const string &username, const string &password) {
    vector<Manager> managers = managerRepository->getAll();
    for (auto &manager: managers)
        if (manager.getUsername() == username && manager.getPassword() == password)
            return true;
    return false;
}

bool UserController::findClient(const string &username) {
    vector<Client> clients = clientRepository->getAll();
    for (auto &client: clients)
        if (client.getUsername() == username)
            return true;
    return false;
}

bool UserController::findManager(const string &username) {
    vector<Manager> managers = managerRepository->getAll();
    for (auto &manager: managers)
        if (manager.getUsername() == username)
            return true;
    return false;
}

