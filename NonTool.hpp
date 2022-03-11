#include "Item.hpp"

#ifndef _NON_TOOL_HPP_
#define _NON_TOOL_HPP_

class NonTool : public Item {
    private:
        int quantity;
        const int maxbufferSize = 64;
    public:
        NonTool();
        NonTool(string name, string type, int quantity);
};

#endif