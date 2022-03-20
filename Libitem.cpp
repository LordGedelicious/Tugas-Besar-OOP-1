#include "Libitem.hpp"
#include <iostream>
#include <string.h>
using namespace std;

libitem::libitem() {
    
}
void libitem::addItem(int ID, string name, string type, string category) {
    if (category.compare("tool") == 0) {
        Item newitem(ID, name, type, 'T');
        tools.push_back(newitem);
    }
    else if (category.compare("nontool") == 0) {
        Item newitem(ID, name, type, 'N');
        nontools.push_back(newitem);
    }
}

void libitem::printlibitem() {
    cout << "ITEM LIB" << endl;
    cout << "NONTOOL:" << endl;
    for (auto i = nontools.begin(); i < nontools.end(); i++){
        cout << i->getid() << " " << i->getname() << endl;
    }
    cout << "TOOL:" << endl;
    for (auto i = tools.begin(); i < tools.end(); i++){
        cout << i->getid() << " " << i->getname() << endl;
    }
}

Item libitem::searchnontoolsbyname(string name) const{
    for (auto i = nontools.begin(); i < nontools.end(); i++){
        if (i->getname() == name) {
            return *i;
        }
    }
    throw "not found";
}

Item libitem::searchnontoolsbyid(int id) const{
    for (auto i = nontools.begin(); i < nontools.end(); i++){
        if (i->getid() == id) {
            return *i;
        }
    }
    throw "not found";
}

Item libitem::searchtoolsbyname(string name) const{
    for (auto i = tools.begin(); i < tools.end(); i++){
        if (i->getname() == name) {
            return *i;
        }
    }
    throw "not found";
}

Item libitem::searchtoolsbyid(int id) const{
    for (auto i = tools.begin(); i < tools.end(); i++){
        if (i->getid() == id) {
            return *i;
        }
    }
    throw "not found";
}


int main() {
    libitem li;
    li.addItem(1,"wood", "plank", "nontool");
    li.addItem(2,"oak", "plank", "nontool");
    li.addItem(3,"wooden_sword", "-", "tool");
    li.printlibitem();
    string search = "wood";
    Item i = li.searchnontoolsbyname(search);
    cout << i.getname();
    return 0;
}
