#ifndef _MAIN_IDEA_HPP_
#define _MAIN_IDEA_HPP_

#include <iostream>
#include <string>

using namespace std;

class Item {
    private:
        const int id;
        string name;
        string type;
        virtual int quantity = 0;
    public:
        Item();
        Item(string name, string type);
};

class NonTool : public Item {
    private:
        int quantity;
        const int maxbufferSize = 64;
    public:
        NonTool();
        NonTool(string name, string type, int quantity);
};

class Tool : public Item {
    private:
        int durability;
    public:
        Tool();
        Tool(string name, string type, int durability);
};

#endif