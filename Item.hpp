#ifndef _ITEM_HPP_
#define _ITEM_HPP_

#include <iostream>
#include <string>

using namespace std;

class Item {
    protected:
        const int id;
        string name;
        string type;
        char category; //T for tool, N for nontool
    public:
        // Default Constructor
        Item();
        // User-defined Constructor
        Item(int id, string name, string type, char cat);
        // Getter-Setter Functions
        int getid() const;
        string getname() const;
        string gettype() const;
        virtual int getquantity();
        virtual int getdurability();
        // Other Functions
        // To add quantity (for NonTool)
        virtual void add(int _quantity);
        // To subtract quantity (for NonTool)
        virtual void substract(int _quantity);
        // Pure virtual functions (implemented in NonTool and Tool)
        virtual bool isFull() = 0;
        virtual bool isEmpty() = 0;
        // Boolean Functions (alternative to getCategory())
        bool isTool();
        bool isNonTool();
};

#endif