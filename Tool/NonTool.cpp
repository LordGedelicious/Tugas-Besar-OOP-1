#include "NonTool.hpp"

NonTool::NonTool() : Item() {
    this->quantity = 0;
}

NonTool::NonTool(int id, string name, string type, int quantity) : Item(id ,name, type,"NonTool") {
    this->quantity = quantity;
}

NonTool::NonTool(const NonTool& other) : Item(other) {
    this->quantity = other.quantity;
}

void NonTool::printDetail() const {
    cout << "id: " << this->id << endl << "name: " << this->name << endl << "type:" << this->type << endl <<"Quantity: " << this->quantity << endl;
}

int NonTool::getQuantity() const{ 
    return this->quantity;
}

void NonTool::add(int q) {
    this->quantity += q;
}