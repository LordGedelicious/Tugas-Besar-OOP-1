#include "Tool.hpp"

Tool::Tool() : Item() {
    this->durability = 0;
}

Tool::Tool(string name, string type, int durability) : Item(name, type) {
    this->durability = durability;
}