#ifndef _ITEM_HPP_
#define _ITEM_HPP_

#include <iostream>
#include <string>

using namespace std;

class Item {
    protected:
        const int id;
        string identifier; // Item, NonItem
        string name;
        string type;
    public:
        Item();
        Item(int id,string name, string type, string identifier);
        Item(const Item &item);
        string getItemName() const;
        string getIdentifier() const;
        virtual void printDetail() const = 0;
};

#endif