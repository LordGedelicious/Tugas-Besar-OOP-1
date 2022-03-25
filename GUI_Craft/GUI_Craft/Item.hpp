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
        Item();
        Item(int id, string name, string type, char cat);
        int getid() const;
        string getname() const;
        string gettype() const;
        virtual int getquantity();
        virtual int getdurability();
        virtual void add(int _quantity);
        virtual void substract(int _quantity);
        virtual bool isFull() = 0;
        virtual bool isEmpty() = 0;
        bool isTool();
        bool isNonTool();
};

#endif