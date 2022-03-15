#include "NonTool.hpp"

NonTool::NonTool(string name, int quantity) : Item(name, "NonTool") {
    this->quantity = quantity;
}

NonTool operator+ (int addedQuantity, const NonTool& other) {
    NonTool result = other;
    result.quantity += addedQuantity;
    return result;
}

NonTool operator- (int removedQuantity, const NonTool& other) {
    NonTool result = other;
    result.quantity -= removedQuantity;
    return result;
}

int NonTool::getID() const {
    return this->id;
}

string NonTool::getName() const {
    return this->name;
}

void NonTool::setName(string newName) {
    this->name = newName;
}

string NonTool::getType() const {
    return this->type;
}

void NonTool::setType(string newType) {
    this->type = newType;
}

int NonTool::getQuantity() const {
    return this->quantity;
}

void NonTool::setQuantity(int newQuantity) {
    this->quantity = newQuantity;
}

void NonTool::printStatus() const {
    cout << "ID : " << this->id << endl;
    cout << "Name : " << this->name << endl;
    cout << "Type : " << this->type << endl;
    cout << "Quantity : " << this->quantity << endl;
}