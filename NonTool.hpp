#include "Item.hpp"

#ifndef _NON_TOOL_HPP_
#define _NON_TOOL_HPP_

class NonTool : public Item {
    private:
        int quantity;
        const int maxquantity;
    public:
        // Default Constructor
        NonTool();
        // User-defined Constructor
        NonTool(int id, string name, string type, int quantity);
        // Getter-Setter Functions
        int getquantity();
        int getmaxquantity();
        // Implementation of Item's Virtual Functions
        void add(int _quantity);
        void substract(int _quantity);
        bool isFull();
        bool isEmpty();
        // Operator Overloading to copy a NonTool's attributes
        void operator=(const NonTool other);
};

#endif