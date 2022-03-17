#include "Item.hpp"

Item::Item() : id(0) {
    this->name = "";
    this->type = "";
}

Item::Item(int id, string name, string type) : id(id) {
    this->name = name;
    this->type = type;
}

int Item::getid() const {
    return this->id;
}

string Item::getname() {
    return this->name;
}

string Item::gettype() {
    return this->type;
}

int Item::getquantity() {
    return 0;
}

void Item::add(int _quantity) {
    //
}

bool Item::isFull() {
    return true;
}

bool Item::isEmpty() {
    return true;
}