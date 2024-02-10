#include "User.h"

using namespace user;
namespace manager {
    class Manager : public User {
    public:
        Manager(const string &username, const string &password);

    };
}