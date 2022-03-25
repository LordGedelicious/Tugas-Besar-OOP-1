#include "pch.h"
#include <istream>
#include <iostream>
#include "BaseException.hpp"

BaseException::BaseException() {
    this->expType = "";
}

string BaseException::getExpType() const{
    return expType;
}

DiscardInvalidException::DiscardInvalidException(int slotID) {
    this->slotID = slotID;
}

void DiscardInvalidException::printMessage() {
    string s("Discard C");
    cout << s + to_string(slotID) << " Fail" << endl;
}

InventoryFullException::InventoryFullException() {
    
}

void InventoryFullException::printMessage() {
    cout << "Inventory is full" << endl;
}

ItemNotFoundException::ItemNotFoundException(string name) {
    this->expType = "ItemNF";
    id = -999;
    this->name = name; 
}

ItemNotFoundException::ItemNotFoundException(int id) {
    this->expType = "ItemNF";
    this->id = id;
    this->name = "";
}

void ItemNotFoundException::printMessage() {
    if (id == -999) {
        cout << "Item " << name << " is not valid!" << endl;
    } else {
        cout << "Item with id:" << id << " is not valid!" << endl;
    }
}

NotNonToolException::NotNonToolException(Item* failItem) {
    this->falseItem = failItem;
}

void NotNonToolException::printMessage() {
    cout << this->falseItem->getname() << " is not a tool"<< endl;
}

NotToolException::NotToolException(Item* failItem) {
    this->falseItem = failItem;
}

void NotToolException::printMessage() {
    cout << this->falseItem->getname() << " is not a tool"<< endl;
}

ItemInvalidException::ItemInvalidException(Item* srcItem, Item* destItem ) {
    this->srcItem = srcItem;
    this->destItem = destItem;
}

void ItemInvalidException::printMessage() {
    cout << this->srcItem->getname() << " is not same as " << this->destItem->getname() << endl;
}

NotEmptySlotException::NotEmptySlotException(char type, int slotID) {
    this->slotID = slotID;
    this->type = type;
}

void NotEmptySlotException::printMessage() {
    if (type == 'I') {
        string s("Slot I");
        cout << s + to_string(slotID) << " is not empty."<< endl;
    } else if (type == 'C') {
        string s("Slot C");
        cout << s + to_string(slotID) << " is not empty."<< endl;
    }
}

EmptySlotException::EmptySlotException(char type, int slotID) {
    this->slotID = slotID;
    this->type = type;
}

void EmptySlotException::printMessage() {
    if (type == 'I') {
        string s("Slot I");
        cout << s + to_string(slotID) << " is not empty." << endl;
    } else if (type == 'C') {
        string s("Slot C");
        cout << s + to_string(slotID) << " is not empty." << endl;
    }
}

CraftingInvalidException::CraftingInvalidException() {

}

void CraftingInvalidException::printMessage() {
    cout << "Crafting failed." << endl;
}