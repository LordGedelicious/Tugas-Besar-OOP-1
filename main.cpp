#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Recipe.hpp"
#include "Table.hpp"
#include "Command.hpp"
#include "Libitem.hpp"
#include "LibRecipe.hpp"
#include "BaseException.hpp"
using namespace std;

int main(){
    int slotID, itemQty, N;
    string command, fileName, InvID, itemName, src, x;
    vector<string> dest;
    Table <3,3> *crafting = new Table<3,3>();
    Table <3,9> *inventory = new Table<3,9>();

    libitem lib;
    string item = "./config/item.txt";
    lib << item;

    RecipeList rList;
    string recipe = "./config/Recipe";
    rList << recipe;

    bool running = true;
    while (running){
        cin >> command;
        if (command == "SHOW"){
            crafting->show("C");
            cout << endl;
            inventory->show("I");
        }
        else if (command == "GIVE"){
            cin >> itemName;
            cin >> itemQty;
            Give give(itemName, itemQty);
            give.Execute(inventory, lib);
        }
        else if (command == "DISCARD"){
            cin >> InvID;
            cin >> itemQty;
            Discard discard(InvID, itemQty);
            discard.Execute(inventory);
        }
        else if (command == "MOVE"){
            cin >> src;
            cin >> N;
            for (int i=0;i<N;i++){
                cin >> x;
                dest.push_back(x);
            }
            Move move(src,N,dest);
            move.Execute(inventory,crafting);
            dest.clear();
        }
        else if (command == "USE"){
            cin >> InvID;
            Use use(InvID);
            use.Execute(inventory);
        }
        else if (command == "CRAFT"){
            Craft craft;
            craft.Execute(crafting, inventory, rList, lib);
        }
        else if (command == "EXPORT"){
            cin >> fileName;
            Export exp(fileName);
            try {
                exp.Execute(inventory);
            } catch (const char* err) {
                cout << err << endl;
            }
        }
        else if (command == "EXIT"){
            break;
        }
        else{
            cout << "Command Invalid" << endl;
        }
        cout << endl;
    }
};
