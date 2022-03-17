#include "Item.hpp"

#ifndef _TOOL_HPP_
#define _TOOL_HPP_

class Tool : public Item {
    private:
        int durability;
    public:
        Tool();
        Tool(int id,string name, string type, int durability);
        void printDetail() const;
};

#endif