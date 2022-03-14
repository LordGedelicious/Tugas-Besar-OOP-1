#include "Item.hpp"
#include "Table.hpp"
#include "Tool.hpp"
#include "NonTool.hpp"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    Table<Item, 3, 9> *inventory = new Table<Item, 3, 9>();
    Table<Item, 3, 3> *craft = new Table<Item, 3, 3>();
    string command;
    stringstream ss;

    while(true) {
        cin >> command;
        if (command[0] == 'S') { // SHOW
            if (command.length() == 4) {
                if (command[1] == 'H' and command[2] == 'O' and command[3] == 'W') {
                    craft->show("C");
                    cout << endl;
                    inventory->show("I");
                }
            } else {
                cout << "Command tidak valid" << endl;
            }
        } else if (command[0] == 'G') { // GIVE

        } else if (command[0] == 'D') { // DISCARD

        } else if (command[0] == 'M') { // MOVE

        } else if (command[0] == 'U') { // USE
        
        } else if (command[0] == 'C') { // CRAFT
        
        } else if (command[0] == 'E') { // EXPORT
        
        } else {
            cout << "Command tidak valid" << endl;
        }
    }
}