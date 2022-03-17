#include "Inventory.hpp"

Inventory::Inventory() {
    for (int i = 0; i < Slots.size(); i++) {
        Slots[i] = NULL;
    }
}

void Inventory::printInventory() const{
    for (int i = 0; i < Slots.size(); i++) {
        if (Slots[i] != NULL) 
            Slots[i]->printDetail();
    }
}
void Inventory::printSLot(int idx){
    if (Slots[idx] != NULL)
    {
        Slots[idx]->printDetail();
    }
    else {
        throw 1;
    }
}

void Inventory::giveItem(LibItem2 Libitem2,string name, int quantity) {
    try {
        NonTool item = Libitem2.searchNonTool(name);
        item.add(quantity);
        int i = 0;
        while (i < Slots.size() && Slots[i] != NULL) {
            i++;
        }
        Slots[i] = new NonTool(item);
    } catch (int i) {
        cout << "ga ada itemnya ngab" << endl;
    }
}








