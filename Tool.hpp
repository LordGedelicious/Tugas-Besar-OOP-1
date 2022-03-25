#include "Item.hpp"

#ifndef _TOOL_HPP_
#define _TOOL_HPP_

class Tool : public Item {
    private:
        int durability;
    public:
        // Default Constructor
        Tool();
        // User-defined Constructor
        Tool(int id, string name, string type, int durability);
        // Getter-Setter Functions
        int getdurability();
        // Implementation of Item's Pure Virtual Function
        bool isFull();
        bool isEmpty();
        // Other Functions
        // To use a tool (minus durability by 1)
        void use();
        // Check if durability is 0, remove from Inventory
        bool isDestroyed();
};

#endif