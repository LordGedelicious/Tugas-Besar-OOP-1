#include "item.hpp"
#include "nontool.hpp"
#include "tool.hpp"
#include <iostream>


int main() {
    nonTool n0;
    nonTool n1(1, "Spruce Plank", "Plank", 2);
    nonTool n2 = n1;
    nonTool n3(2, "Oak Plank", "Plank", 2);
    Tool t1(3, "Wooden Pickaxe", "Pickaxe", 10);
    n0.printInfo();
    n1.printInfo();
    n2.printInfo();
    n3.printInfo();
    nonTool n4(3, "Hi", "Tes", 3);
    n4.printInfo();
    t1.printInfo();



    return 0;
}