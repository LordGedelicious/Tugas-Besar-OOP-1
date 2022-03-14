#include <iostream>
#include "item.hpp"
using namespace std;

const int max_lib = 200;
class library {
    private:
    item *nonTool_lib;
    int nonTool_tail;
    item *Tool_lib;
    int Tool_tail;

    public:
    library();
    void addItem(int ID, string name, string type, string category);
    void printLibrary();
    void TEST_init();
    



};