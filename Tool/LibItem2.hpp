#ifndef LIBITEM2_HPP
#define LIBITEM2_HPP

#include "Item.hpp"
#include "Tool.hpp"
#include "NonTool.hpp"
#include <algorithm>
#include <iterator>
#include <vector>

class LibItem2{
private:
    vector<Tool> Tools;
    vector<NonTool> NonTools;
public:
    LibItem2();
    void addToLibrary(int id, string name, string type, bool isTool);
    NonTool searchNonTool(string name) const; 
    Tool searchTool(string name) const; 
    void printAll();
};


#endif