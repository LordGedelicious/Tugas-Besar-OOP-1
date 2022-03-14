#include "inventory.hpp"
#include "control.cpp"
#include <iostream>
using namespace std;

inventory::inventory() {
    this->buffer = new item*[maxElmt];
    for (int i=0; i<maxElmt; i++) {
        this->buffer[i] = NULL;
    }
}

item* inventory::get_item_by_idx(int idx) {
    return this->buffer[idx];
}

void inventory::set_item_by_idx(int idx, item* i) {
    this->buffer[idx] = i;
}

void inventory::printInventory() {
    for (int i=0; i<maxElmt; i++) {
        item* i_temp = get_item_by_idx(i);
        cout << "I" << i << " ";
        if (i_temp != NULL) {
             cout << i_temp->get_Name();
             if (isTool(i_temp)) {
                 Tool* i_ptr = (Tool *)i_temp;
                 cout << " Dur: " << i_ptr->get_Durability();
             }
             else if (isNonTool(i_temp)) {
                 nonTool* i_ptr = (nonTool *)i_temp;
                 cout << " Qty: " << i_ptr->get_Quantity();
             }
        }
        cout << endl;
    }
}