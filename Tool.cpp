#include "Tool.hpp"

Tool::Tool() : Item() {
    this->durability = 10;
}

Tool::Tool(int id, string name, string type, int durability) : Item(id, name, type) {
    this->durability = durability;
}

bool Tool::isEmpty() {
    return (this->durability == 0); 
}