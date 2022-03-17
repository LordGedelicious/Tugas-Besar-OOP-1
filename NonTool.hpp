#include "Item.hpp"

#ifndef _NON_TOOL_HPP_
#define _NON_TOOL_HPP_

class NonTool : public Item {
    private:
        int quantity;
        const int maxquantity;
    public:
        NonTool();
        NonTool(int id, string name, string type, int quantity);
        int getquantity();
        int getmaxquantity();
        void add(int _quantity);
        void substract(int _quantity);
        bool isFull();
        bool isEmpty();
};

#endif