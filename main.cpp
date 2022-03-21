#include <iostream>
#include <string>
#include "Table.hpp"
#include "Command.hpp"
using namespace std;

int main(){
    int slotID;
    string command, fileName, InvID;
    Table <3,3> *crafting = new Table<3,3>();
    Table <3,9> *inventory = new Table<3,9>();

    cout << "Uji coba" << endl;
    while (true){
        cin >> command;
        if (command == "SHOW"){ //done
            crafting->show("C");
            inventory->show("I");
        }
        else if (command == "GIVE"){
            Give give("name", 7);
            give.Execute();
        }
        else if (command == "DISCARD"){
            Discard discard("test", 5);
            discard.Execute();
        }
        else if (command == "MOVE"){
            cout << "placeholder" << endl;
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
};
