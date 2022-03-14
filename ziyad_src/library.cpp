#include "library.hpp"
#include <iostream>
#include <string.h>
using namespace std;

library::library() {
    this->nonTool_lib = new item[max_lib];
    this->nonTool_tail = -1;
    this->Tool_lib = new item[max_lib];
    this->Tool_tail = -1;
}
void library::addItem(int ID, string name, string type, string category) {
    if (category.compare("tool") == 0) {
        this->Tool_tail++;
        Tool_lib[Tool_tail] = item(ID, name, type);
    }
    else if (category.compare("nontool") == 0) {
        this->nonTool_tail++;
        this->nonTool_lib[nonTool_tail] = item(ID, name, type);
    }
}

void library::printLibrary() {
    cout << "ITEM LIB" << endl;
    cout << "NONTOOL:" << endl;
    for (int i=0; i<=this->nonTool_tail; i++) {
        cout << nonTool_lib[i].get_ID() << " " << nonTool_lib[i].get_Name() << endl;
    }
    cout << "TOOL:" << endl;
    for (int i=0; i<=this->Tool_tail; i++) {
        cout << Tool_lib[i].get_ID() << " " << Tool_lib[i].get_Name() << endl;
    }
}

void library::TEST_init() {
    addItem(1, "OAK_PLANK", "Plank", "nontool");
    addItem(2, "BIRCH_PLANK", "Plank", "nontool");
    addItem(3, "STICK", "-", "nontool");
    addItem(4, "WOODEN_PICKAXE", "-", "tool");
}