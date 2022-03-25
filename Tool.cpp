#include "Tool.hpp"

Tool::Tool() : Item() {
    this->durability = 10;
}

Tool::Tool(int id, string name, string type, int durability) : Item(id, name, type, 'T') {
    this->durability = durability;
}

int Tool::getdurability() {
    return this->durability;
}

bool Tool::isFull() {
    return true;
}

bool Tool::isEmpty() {
    return (this->durability == 0); 
}

void Tool::use() {
    this->durability -= 1;
}

bool Tool::isDestroyed() {
    return this->durability <= 0;
}