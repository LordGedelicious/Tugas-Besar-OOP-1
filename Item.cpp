#include "Item.hpp"
#include <iostream>

using namespace std;

int idItem = 0;

Item::Item(string name, string type) : id(idItem + 1) {
    this->name = name;
    this->type = type;
    idItem ++;
}