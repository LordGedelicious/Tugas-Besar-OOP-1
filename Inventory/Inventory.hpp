#ifndef INVENTORY_HPP
#define INVENTORY_HPP
#include <array>
#include <algorithm>

#include "../Tool/LibItem2.hpp"

class Inventory{
private:
    array<Item*,27> Slots;
public:
    Inventory();
    void giveItem(LibItem2 ,string name, int quantity);
    void printSLot(int idx);

    void printInventory() const;
};

#endif