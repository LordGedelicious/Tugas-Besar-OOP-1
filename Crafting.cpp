#include "Crafting.hpp"

CraftingTable::CraftingTable() {
    this->craftingTable = new this->slotTable[3][3];
}

CraftingTable::~CraftingTable() {
    cout << "CraftingTable has been deleted" << endl;
}

CraftingTable::CraftingTable(const CraftingTable& other) {
    this->craftingTable = other.craftingTable;
}

Item CraftingTable::getItemByLocation(int row, int column) const {
    slotTable target = this->craftingTable[row][column];
    return std::get<0>(target);
}

int CraftingTable::getQtyByLocation(int row, int column) const {
    slotTable target = this->craftingTable[row][column];
    return std::get<1>(target);
}

void CraftingTable::setItemByLocation(int row, int column, Item newItem, int qty) {
    slotTable target = this->craftingTable[row][column];
    Item targetItem = std::get<0>(target);
    // Gw buat tiga kasus yang ini.
    
    if (targetItem == NULL) { // Kasus 1 : Crafting Slot kosong
        tuple<Item, int> newSlot;
        newSlot = std::make_tuple(newItem, qty);
        this->craftingTable[row][column] = newSlot;
    } else if (targetItem == newItem) { // Kasus 2 : Item harus sama (yang mau diset dan yang ada di crafting table)
        tuple<Item, int> newSlot;
        newSlot = std::make_tuple(newItem, qty + std::get<0>(target));
        this->craftingTable[row][column] = newSlot;
    } else { // Kasus 3 : Kalau bendanya beda, untuk saat ini gw handle sebagai ga boleh aja
        cout << "Ini ganti error handling" << std::endl;
    }
}