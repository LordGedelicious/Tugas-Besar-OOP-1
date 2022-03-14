#ifndef __INVENTORY_HPP__
#define __INVENTORY_HPP__
#include "item.hpp"
#include <iostream>
using namespace std;


const int maxElmt = 27;
class inventory {
    private:
    item **buffer; //array of pointer to item
    public:
    inventory();
    item* get_item_by_idx(int idx);
    void set_item_by_idx(int idx, item* i);
    void printInventory();
    

    
};
#endif