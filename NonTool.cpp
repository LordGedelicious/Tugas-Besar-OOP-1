#include "NonTool.hpp"

NonTool::NonTool() : Item(), maxquantity(64) {
    this->quantity = 0;
}

NonTool::NonTool(int id, string name, string type, int quantity) : Item(id, name, type, 'N'), maxquantity(64) {
    this->quantity = quantity;
}

int NonTool::getquantity() {
    return this->quantity;
}

int NonTool::getmaxquantity() {
    return this->maxquantity;
}

void NonTool::add(int _quantity) {
    if (this->quantity + _quantity > this->maxquantity) {
        this->quantity = this->maxquantity;
    } else {
        this->quantity += _quantity;
    }
}

void NonTool::substract(int _quantity) {
    if (this->quantity - _quantity < 0) {
        this->quantity = 0;
    } else {
        this->quantity -= _quantity;
    }
}

bool NonTool::isFull() {
    return (this->quantity == this->maxquantity);
}

bool NonTool::isEmpty() {
    return (this->quantity == 0);
}

void NonTool::operator=(const NonTool other) {
    this->quantity = other.quantity;
    this->name = other.name;
    this->type = other.type;
    this->category = other.category;
}