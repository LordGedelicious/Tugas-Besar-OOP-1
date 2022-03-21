#include "Libitem.hpp"
#include <iostream>
#include <string.h>
using namespace std;

libitem::libitem() {
    
}
void libitem::addItem(int ID, string name, string type, string category) {
    if (category.compare("TOOL") == 0) {
        Item newitem(ID, name, type, 'T');
        tools.push_back(newitem);
    }
    else if (category.compare("NONTOOL") == 0) {
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

NonTool libitem::searchnontoolsbyname(string name) const{
    for (auto i = nontools.begin(); i < nontools.end(); i++){
        if (i->getname() == name) {
            NonTool nt(i->getid(),i->getname(),i->gettype(), 0);
            return nt;
        }
    }
    throw "not found";
}

NonTool libitem::searchnontoolsbyid(int id) const{
    for (auto i = nontools.begin(); i < nontools.end(); i++){
        if (i->getid() == id) {
            NonTool nt(i->getid(),i->getname(),i->gettype(), 0);
            return nt;
        }
    }
    throw "not found";
}

Tool libitem::searchtoolsbyname(string name) const{
    for (auto i = tools.begin(); i < tools.end(); i++){
        if (i->getname() == name) {
            Tool t(i->getid(),i->getname(),i->gettype(), 10);
            return t;
        }
    }
    throw "not found";
}

Tool libitem::searchtoolsbyid(int id) const{
    for (auto i = tools.begin(); i < tools.end(); i++){
        if (i->getid() == id) {
            Tool t(i->getid(),i->getname(),i->gettype(), 10);
            return t;
        }
    }
    throw "not found";
}

void libitem::readFile(string fileName){
    int id;
    string name;
    string type;
    string category;
    ifstream file(fileName);
    if (file.is_open()){
        while(file >> id >> name >> type >> category){ //baca tiap line
            this->addItem(id, name, type, category);
        }
    }
}

int main() {
    libitem li;
    li.addItem(1,"wood", "plank", "nontool");
    li.addItem(2,"oak", "plank", "nontool");
    li.addItem(3,"wooden_sword", "-", "tool");
    li.printlibitem();
    string search = "wood";
    NonTool i = li.searchnontoolsbyname(search);
    cout << i.getname();
    return 0;
}
