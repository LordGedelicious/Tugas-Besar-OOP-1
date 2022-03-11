#ifndef _ITEM_HPP_
#define _ITEM_HPP_

#include <iostream>
#include <string>

using namespace std;

class Item {
    private:
        const int id;
        string name;
        string type;
    public:
        Item();
        Item(string name, string type);
};

#endif