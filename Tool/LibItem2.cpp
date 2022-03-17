#include "LibItem2.hpp"

LibItem2::LibItem2() {
};

void LibItem2::addToLibrary(int id, string name, string type, bool isTool) {
    if (isTool) {
        if (type == "WOODEN") {
            Tool pushtool(id, name, type, 59);
            Tools.push_back(pushtool);
        } else if (type == "STONE") {
            Tool pushtool(id, name, type, 131);
            Tools.push_back(pushtool);
        }
        else if(type == "IRON") {
            Tool pushtool(id, name, type, 250);
            Tools.push_back(pushtool);
        } else if (type == "DIAMOND") {
            Tool pushtool(id, name, type, 1561);
            Tools.push_back(pushtool);
        }
    } else {
        NonTool pushnontool(id, name, type, 0);
        NonTools.push_back(pushnontool);
    }
}


NonTool LibItem2::searchNonTool(string name) const {
    for (auto i = NonTools.begin(); i != NonTools.end(); ++i)
    {
        if (i->getItemName() == name) {
            return *i;
        }
    }
    throw 1;
}

Tool LibItem2::searchTool(string name) const {
    for (auto i = Tools.begin(); i != Tools.end(); ++i)
    {
        if (i->getItemName() == name) {
            return *i;
        }
    }
    throw 1;
}


void LibItem2::printAll() {
    cout << "List NonTool" << endl; 
    cout << "------------" << endl;
    for (auto i = NonTools.begin(); i != NonTools.end(); ++i)
    {
        i->printDetail();
    }
    cout << "List Tool" << endl; 
    cout << "------------" << endl;
    for (auto i = Tools.begin(); i != Tools.end(); ++i)
    {
        i->printDetail();
    }
}

