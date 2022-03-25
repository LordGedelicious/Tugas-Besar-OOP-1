#include "Libitem.hpp"


libitem::libitem() {
    
}
void libitem::addItem(int ID, string name, string type, string category) {
    if (category.compare("TOOL") == 0) {
        Tool newitem(ID, name, type, 10);
        tools.push_back(newitem);
    }
    else if (category.compare("NONTOOL") == 0) {
        NonTool newitem(ID, name, type, 0);
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
    throw new ItemNotFoundException(name);
}

NonTool libitem::searchnontoolsbyid(int id) const{
    for (auto i = nontools.begin(); i < nontools.end(); i++){
        if (i->getid() == id) {
            NonTool nt(i->getid(),i->getname(),i->gettype(), 0);
            return nt;
        }
    }
    
    throw new ItemNotFoundException(id);
}

Tool libitem::searchtoolsbyname(string name) const{
    for (auto i = tools.begin(); i < tools.end(); i++){
        if (i->getname() == name) {
            Tool t(i->getid(),i->getname(),i->gettype(), 10);
            return t;
        }
    }
    
    throw new ItemNotFoundException(name);
}

Tool libitem::searchtoolsbyid(int id) const{
    for (auto i = tools.begin(); i < tools.end(); i++){
        if (i->getid() == id) {
            Tool t(i->getid(),i->getname(),i->gettype(), 10);
            return t;
        }
    }
    throw new ItemNotFoundException(id);
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

// Buat ngetest aja
// int main() {
//     libitem li;
//     li.addItem(1,"wood", "plank", "NONTOOL");
//     li.addItem(2,"oak", "plank", "NONTOOL");
//     li.addItem(3,"wooden_sword", "-", "TOOL");
//     li.printlibitem();
//     try {
//         string search = "wood";
//         NonTool i = li.searchnontoolsbyname(search);
//         cout << i.getname() << endl;
//     } catch (BaseException* e) {
//         ItemNotFoundException* e_out = (ItemNotFoundException*)e; 
//         e_out->printMessage();
//     }
//     try {
//         string search = "anjay";
//         NonTool i = li.searchnontoolsbyname(search);
//         cout << i.getname();
//     } catch (BaseException* e) {
//         ItemNotFoundException* e_out = (ItemNotFoundException*)e; 
//         e_out->printMessage();
//     }
//     return 0;
// }
