#include "Tool.hpp"

Tool::Tool(string name, int durability) : Item(name, "Tool") {
    this->durability = durability;
    cout << "Created a Tool with name " << name << " and durability " << durability << endl;
}

// Belum buat error exception kalau durability lebih dari 10
Tool operator+(int addedDurability, const Tool& other) {
    Tool result = other;
    result.durability += addedDurability;
    return result;
}

Tool operator-(int reducedDurability, const Tool& other) {
    Tool result = other;
    result.durability -= reducedDurability;
    return result;
}

int Tool::getID() const {
    return this->id;
}

string Tool::getName() const {
    return this->name;
}

void Tool::setName(string newName) {
    this->name = newName;
}

string Tool::getType() const {
    return this->type;
}

void Tool::setType(string newType) {
    this->type = newType;
}

int Tool::getDurability() const {
    return this->durability;
}

void Tool::setDurability(int newDurability) {
    this->durability = newDurability;
}

void Tool::printStatus() const {
    cout << "ID : " << this->id << endl;
    cout << "Name : " << this->name << endl;
    cout << "Type : " << this->type << endl;
    cout << "Durability : " << this->durability << endl;
}