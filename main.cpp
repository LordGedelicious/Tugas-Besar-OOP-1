#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iterator>
#include <vector>
#include <algorithm>
#include "Recipe.hpp"
#include "Table.hpp"
#include "Command.hpp"
#include "Libitem.hpp"
#include "LibRecipe.hpp"
using namespace std;

vector<string> splitString(string full){
    string space_delimiter = " ";
    vector<string> words{};

    size_t pos = 0;
    while ((pos = full.find(space_delimiter)) != string::npos) {
        words.push_back(full.substr(0, pos));
        full.erase(0, pos + space_delimiter.length());
    }
    words.push_back(full);
    return words;
}

int main(){
    int slotID, itemQty, N;
    string command, fileName, InvID, itemName, src, x;
    vector<string> dest;
    Table <3,3> *crafting = new Table<3,3>();
    Table <3,9> *inventory = new Table<3,9>();

    libitem lib;
    lib.readFile("item.txt");

    //UNTUK COBA CRAFTING
    vector<string> ingredients;

    string str;
    ifstream file("DIAMOND_PICKAXE.txt");
    Recipe stick;
    if (file.is_open()){
        getline(file,str,' ');
        stick.setRowSize(stoi(str));
        getline(file,str);
        stick.setColSize(stoi(str));
        for (int i=0;i<stick.getRowSize();i++){
            getline(file,str);
            ingredients = splitString(str);
            for (int j=0;j<ingredients.size();j++){
                stick.insertIngredient(i,j,ingredients[j]);
            }
        }
        getline(file,str,' ');
        stick.setRecipeResult(str);
        getline(file,str);
        stick.setResultQty(stoi(str));
    }
    stick.printRecipe();

    RecipeList rList;
    rList.addRecipes(stick);

    

    /*
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
            Craft craft;
            craft.Execute();
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
    */
};
