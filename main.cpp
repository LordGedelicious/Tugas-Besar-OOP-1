#include "Item.hpp"
#include "Table.hpp"
#include "Tool.hpp"
#include "NonTool.hpp"
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

    
    // TEST FOR DEBUG
    Tool *tempTool = new Tool(15, "DIAMOND_PICKAXE", "-", 10);
    inventory->give(tempTool);
    // END

    while(true) {
        cin >> command;
        if (command == "SHOW") { // SHOW
            craft->show("C");
            cout << endl;
            inventory->show("I");
        } else if (command == "GIVE") { // GIVE
            cin >> command;
            idx = idxNT(command, item, row);
            if (idx != row) {
                cin >> command;
                ntool = new NonTool(stoi(item[idx][0]), item[idx][1], item[idx][2], stoi(command));
                inventory->give(ntool);
            } else {
                cout << "Item tidak valid" << endl;
            }
        } else if (command == "DISCARD") { // DISCARD
            cin >> command;
            if (command[0] == 'I') {
                ss << command[1];
                if (command.length() == 3) {
                    ss << command[2];
                }
                idInventory = ss.str();
                ss.str("");
                cin >> command;
                inventory->discard(stoi(idInventory), stoi(command));
            } else {
                cout << "ID tidak valid" << endl;
            }

        } else if (command[0] == 'M') { // MOVE

        } else if (command[0] == 'U') { // USE
        
        } else if (command[0] == 'C') { // CRAFT
        
        } else if (command[0] == 'E') { // EXPORT
        
        } else {
            cout << "Command tidak valid" << endl;
        }
    }
}