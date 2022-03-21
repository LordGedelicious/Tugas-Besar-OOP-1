#include <iostream>
#include <string>
#include "Command.hpp"
using namespace std;

int main(){
    string command;
    while (true){
        cin >> command;
        if (command == "SHOW"){
            Show show;
            show.Execute();
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
        else if (command == "USE"){
            Use use("adsf");
            use.Execute();
        }
        else if (command == "CRAFT"){
            Craft craft;
            craft.Execute();
        }
        else if (command == "EXPORT"){
            Export exp("test");
            exp.Execute();
        }
        else if (command == "EXIT"){
            break;
        }
        else{
            cout << "Command Invalid" << endl;
        }
    }
};
