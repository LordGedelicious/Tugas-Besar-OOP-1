#include "BaseException.hpp"

ItemNotFoundException::ItemNotFoundException(string name) {
    id = -999;
    this->name = name; 
}

ItemNotFoundException::ItemNotFoundException(int id) {
    this->id = id;
    this->name = "";
}

void ItemNotFoundException::printMessage() {
    if (id == -999) {
        cout << "Item " << name << " is not valid!";
    } else {
        cout << "Item with id:" << id << "is not valid!";
    }
}