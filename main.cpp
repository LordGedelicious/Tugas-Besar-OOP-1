#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Recipe.hpp"
#include "Table.hpp"
#include "Command.hpp"
#include "Libitem.hpp"
#include "LibRecipe.hpp"
using namespace std;

int main(){
    int slotID, itemQty, N;
    string command, fileName, InvID, itemName, src, x;
    vector<string> dest;
    Table <3,3> *crafting = new Table<3,3>();
    Table <3,9> *inventory = new Table<3,9>();

    libitem lib;
    lib.readFile("item.txt");

    RecipeList rList;
    rList.readRecipeFile("Recipe");

    // Give give("BIRCH_PLANK", 10);
    // Give give2("STICK", 10);
    // give.Execute(inventory, lib);
    // give2.Execute(inventory, lib);

    // dest.push_back("C0");
    // dest.push_back("C1");
    // dest.push_back("C2");
    // Move move("I0",3,dest);
    // move.Execute(inventory,crafting);

    

    // crafting->show("C");
    // cout << endl;
    // inventory->show("I");

    cout << "Uji coba" << endl;
    while (true){
        cin >> command;
        if (command == "SHOW"){ //done
            crafting->show("C");
            cout << endl;
            inventory->show("I");
        }
        else if (command == "GIVE"){ //done
            cin >> itemName;
            cin >> itemQty;
            Give give(itemName, itemQty);
            give.Execute(inventory, lib);
        }
        else if (command == "DISCARD"){//done
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
        else if (command == "USE"){//add exception handling
            cin >> InvID;
            Use use(InvID);
            use.Execute(inventory);
        }
        else if (command == "CRAFT"){
            try{
                Recipe res = rList.checkCrafting(crafting);
                res.printRecipe();
            }   
            catch(string asdf){
                cout << asdf << endl;
            }
            //Craft craft;
            //craft.Execute();
        }
        else if (command == "EXPORT"){ //done
            cin >> fileName;
            Export exp(fileName);
            exp.Execute(inventory);
        }
        else if (command == "EXIT"){
            break;
        }
        else{
            cout << "Command Invalid" << endl;
        }
    }
};
