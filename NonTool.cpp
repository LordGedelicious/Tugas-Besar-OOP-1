#include "NonTool.hpp"

NonTool::NonTool() : Item() {
    this->quantity = 0;
}

NonTool::NonTool(string name, string type, int quantity) : Item(name, type) {
    this->quantity = quantity;
}