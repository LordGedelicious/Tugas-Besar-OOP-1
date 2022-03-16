#include "Inventory.hpp"

Inventory::Inventory() {
    this->status = true;
}

Inventory::Inventory(const Inventory& other) {
    this->status = other.status;
    this->InventoryList = other.InventoryList;
}

Inventory::~Inventory() {
    // Kalau kemarin ngebaca stack overflow, katanya ga perlu dibuat kyk gini, cukup delete aja
    cout << "Inventory has been deleted" << endl;
}

Inventory& Inventory::operator+=(const Item& newItem) {
    
}

