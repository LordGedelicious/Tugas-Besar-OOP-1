#include "Command.hpp"

//Command
Command::Command(){
}

//Show
Show::Show(){
}

void Show::Execute(){
    cout << "Show" << endl;
}

//Give
Give::Give(string name, int qty){
    this->name = name;
    this->qty = qty;
}

void Give::Execute(){
    cout << "Give" << endl;
}

//Discard
Discard::Discard(string InvId, int qty){
    this->InvId = InvId;
    this->qty = qty;
}

void Discard::Execute(){
    cout << "Discard" << endl;
}

//Move
Move::Move(string src, int N, string* dest){
    this->src = src;
    this->N = N;
    this->dest = dest;
}

void Move::Execute(){
    cout << "Move" << endl;
}

//Use
Use::Use(string InvID){
    this->InvId = InvID;
}
void Use::Execute(){
    cout << "Use" << endl;
}

//Craft
Craft::Craft(){    
}

void Craft::Execute(){
    cout << "Craft" << endl;
}

//Export
Export::Export(string fileName){
    this->fileName = fileName;
}

void Export::Execute(){
    cout << "Export" << endl;
}
