#include "Item.hpp"
#include "Table.hpp"
#include "Tool.hpp"
#include "NonTool.hpp"
#include "command.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

int idxNT(string name, string** item, int row) {
    bool flag = false;
    int i = 0;
    while (i < row && !flag) {
        if (item[i][1] == name && item[i][3] == "NONTOOL") {
            flag = true;
        } else {
            i++;
        }
    }
    return i;
}

int main() {
    Table<3, 9> *inventory = new Table<3, 9>();
    Table<3, 3> *craft = new Table<3, 3>();
    NonTool *ntool;
    string command, line, idInventory;
    int row, i, idx;
    stringstream ss;

    ifstream file("item.txt");
    row = 0;
    if (file.is_open()) {
        while (getline(file, line)) {
            row++;
        }
        file.close();
    }

    string** item;
    item = new string*[row];
    for (i = 0; i < row; i++) {
        item[i] = new string[4];
    }
    string id;
    string name;
    string type;
    string tool_type;



    file.open("item.txt");
    i = 0;
    if (file.is_open()) {
        while (file >> id >> name >> type >> tool_type) {
            item[i][0] = id;
            item[i][1] = name;
            item[i][2] = type;
            item[i][3] = tool_type;
            i++;
        }
        file.close();
    }

    while(true) {
        cin >> command;
        if (command == "SHOW") { // SHOW
            Show();
        } else if (command == "GIVE") { // GIVE
            Give();
        } else if (command == "DISCARD") { // DISCARD
            Discard();
        } else if (command == "MOVE") { // MOVE
            Move();
        } else if (command == "USE") { // USE
            Use();
        } else if (command == "CRAFT") { // CRAFT
            Craft();
        } else if (command == "EXPORT") { // EXPORT
            Export();
        } else {
            cout << "Command tidak valid" << endl;
        }
    }
}
