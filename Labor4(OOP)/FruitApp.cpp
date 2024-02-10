#include "FruitUI.h"
#include <memory>
#include "Tests.h"
using namespace UI;
using namespace Test;
int main() {
    shared_ptr<FruitRepo> repo = make_shared<FruitRepo>();
    shared_ptr<FruitController> controller = make_shared<FruitController>(repo);
    FruitUI ui(controller);
    ui.menu();
    Tests tests(controller);
    tests.testAll();



    return 0;
}
