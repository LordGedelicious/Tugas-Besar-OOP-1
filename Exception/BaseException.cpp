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
    cout << "Discard C" + slotID << " Fail";
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
        cout << "Item " << name << " is not valid!";
    } else {
        cout << "Item with id:" << id << "is not valid!";
    }
}

NotNonToolException::NotNonToolException(Item* failItem) {
    this->falseItem = failItem;
}

void NotNonToolException::printMessage() {
    cout << this->falseItem->getname() << "is not a nontool";
}

ItemInvalidException::ItemInvalidException(Item* srcItem, Item* destItem ) {
    this->srcItem = srcItem;
    this->destItem = destItem;
}

void ItemInvalidException::printMessage() {
    cout << this->srcItem->getname() << " is not same as " << this->destItem->getname() << endl;
}

NotEmptySlotException::NotEmptySlotException(int slotID, char type) {
    this->slotID = slotID;
    this->type = type;
}

void NotEmptySlotException::printMessage() {
    if (type == 'I') {
        cout << "Slot I" + slotID << "is not empty.";
    } else if (type == 'C') {
        cout << "Slot C" + slotID << "is not empty.";
    }
}

EmptySlotException::EmptySlotException(int slotID, char type) {
    this->slotID = slotID;
    this->type = type;
}

void EmptySlotException::printMessage() {
    if (type == 'I') {
        cout << "Slot I" + slotID << "is empty.";
    } else if (type == 'C') {
        cout << "Slot C" + slotID << "is empty.";
    }
}