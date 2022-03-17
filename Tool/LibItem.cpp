#include "LibItem.hpp"

LibItem::LibItem() {
};

void LibItem::addToLibrary(int id, string name, string type, bool isTool) {
    if (isTool) {
        if (type == "WOODEN") {
            items.push_back(new Tool(id,name,type,59));
        } else if (type == "STONE") {
            items.push_back(new Tool(id,name,type,131));
        }
        else if(type == "IRON") {
            items.push_back(new Tool(id,name,type,250));
        } else if (type == "DIAMOND") {
            items.push_back(new Tool (id, name, type,1561));
        }
    } else {
        items.push_back(new NonTool(id, name, type, 0));
    }
}

Item* LibItem::searchItem(string name) const {
    for (auto i = items.begin(); i != items.end(); ++i)
    {
        if (i[0]->getItemName() == name) {
            return i[0];
        }
    }
    return NULL;
}

NonTool LibItem::searchItemNonTool(string name) const {
    for (auto i = items.begin(); i != items.end(); ++i)
    {
        if (i[0]->getItemName() == name) {
            NonTool* ptr_output = (NonTool*) i[0];
            NonTool output(*ptr_output);
            return output;
        }
    }
}


void LibItem::printAll() {
    cout << "List Item" << endl; 
    cout << "------------" << endl;
    for (auto i = items.begin(); i != items.end(); ++i)
    {
        i[0]->printDetail();
    }
}

