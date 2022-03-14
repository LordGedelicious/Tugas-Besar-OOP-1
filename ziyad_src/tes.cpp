#include "item.hpp"
#include "inventory.hpp"
#include "tool.hpp"
#include "nontool.hpp"
#include "control.cpp"
#include "library.hpp"
#include <iostream>
using namespace std;


int main() {
    // item *i1 = new item(1, "item1", "type-A");
    // item i2;
    // Tool *t1 = new Tool(2, "tool1", "-", 10);
    // Tool t2(*i1, 8);
    // nonTool *n1 = new nonTool(3, "oak_plank", "plank", 2);
    // inventory inv;
    // inv.set_item_by_idx(0, i1);
    // inv.set_item_by_idx(1, t1);
    // inv.set_item_by_idx(2, n1);
    // inv.set_item_by_idx(3, &t2);
    // inv.set_item_by_idx(4, &i2);
    // for (int i=0; i<3; i++) {
    //     inv.get_item_by_idx(i)->printInfo();
    // }
    // inv.printInventory();
    library lib;
    lib.TEST_init();
    lib.printLibrary();
    return 0;
}