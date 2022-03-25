#ifndef LIBITEM_HPP_
#define LIBITEM_HPP_

#include <iostream>
#include "Item.hpp"
#include "Tool.hpp"
#include "NonTool.hpp"
#include "Exception/BaseException.hpp"
#include <vector>
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

using namespace std;

class libitem {
    private:
    vector<Tool> tools;
    vector<NonTool> nontools;
    public:
    libitem();
    void addItem(int ID, string name, string type, string category);
    NonTool searchnontoolsbyname(string name) const;
    NonTool searchnontoolsbyid(int id) const;
    Tool searchtoolsbyname(string name) const;
    Tool searchtoolsbyid(int id) const;
    void printlibitem();
    void readFile(string fileName);
};

#endif
