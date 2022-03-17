#include "Item.hpp"

Item::Item() : id(0) {
    this->name = "";
    this->type = "";
    this->identifier = "none";
}


Item::Item(int id,string name, string type, string identifier) : id(id) {
    this->name = name;
    this->type = type;
    this->identifier = identifier;
}

Item::Item(const Item& other) : id(other.id) {
    this->name = other.name;
    this->type = other.type;
    this->identifier = other.identifier;
}

string Item::getItemName() const {
    return this->name;
}

string Item::getIdentifier() const {
    return this->identifier;
}