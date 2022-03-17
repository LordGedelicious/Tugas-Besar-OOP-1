#ifndef LIBITEM_HPP
#define LIBITEM_HPP

#include "Item.hpp"
#include "Tool.hpp"
#include "NonTool.hpp"
#include <algorithm>
#include <iterator>
#include <vector>

class LibItem{
private:
    vector<Item*> items;
public:
    LibItem();
    void addToLibrary(int id, string name, string type, bool isTool);
    Item* searchItem(string name) const;
    NonTool searchItemNonTool(string name) const; 
    void printAll();
};

#endif