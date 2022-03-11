#include "Item.hpp"

Item::Item() : id(0) {
    this->name = "";
    this->type = "";
}

Item::Item(string name, string type) : id(0) {
    this->name = name;
    this->type = type;
}