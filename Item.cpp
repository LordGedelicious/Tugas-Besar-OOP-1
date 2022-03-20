#include "Item.hpp"

Item::Item() : id(0) {
    this->name = "";
    this->type = "";
    this->category = '-';
}

Item::Item(int id, string name, string type, char cat) : id(id) {
    this->name = name;
    this->type = type;
    this->category = cat;
}

int Item::getid() const {
    return this->id;
}

string Item::getname() const{
    return this->name;
}

string Item::gettype() const{
    return this->type;
}

int Item::getquantity() {
    return 0;
}

void Item::add(int _quantity) {
    //
}

void Item::substract(int _quantity) {
    //
}

bool Item::isFull() {
    return true;
}

bool Item::isEmpty() {
    return true;
}

bool Item::isTool() {
    return this->category == 'T';
}
bool Item::isNonTool() {
    return this->category == 'N';
}