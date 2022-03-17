#include "Item.hpp"

#ifndef _NON_TOOL_HPP_
#define _NON_TOOL_HPP_

class NonTool : public Item {
    private:
        int quantity;
        const int maxbufferSize = 64;
    public:
        NonTool();
        NonTool(int id, string name, string type, int quantity);
        NonTool(Item i, int q);

        NonTool(const NonTool& other);
        int getQuantity() const;
        void add(int q);
        void printDetail() const;
};

#endif