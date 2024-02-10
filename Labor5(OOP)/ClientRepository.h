#include "Client.h"
#include <vector>


using namespace client;
using namespace std;

namespace ClientRepo {
    class ClientRepository {
    private:
        vector<Client> clientRepo;
    public:
        ClientRepository();

        void updateDatabase();

        void add(Client client);

        void remove(Client client);

        vector<Client> getAll();
    };
}