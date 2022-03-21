#include <iostream>
#include "Item.hpp"
#include <vector>

#ifndef LIBITEM_HPP_
#define LIBITEM_HPP_

using namespace std;

class libitem {
    private:
    vector<Item> tools;
    vector<Item> nontools;
    public:
    libitem();
    void addItem(int ID, string name, string type, string category);
    Item searchnontoolsbyname(string name) const;
    Item searchnontoolsbyid(int id) const;
    Item searchtoolsbyname(string name) const;
    Item searchtoolsbyid(int id) const;
    void printlibitem();
    void readFile(string fileName);
};

#endif
