#include "Command.hpp"

bool checkID(string InvID){ //validasi ID
    string ID = InvID;
    int index;
    InvID.erase(0,1);
    index = stoi(InvID);
    if (ID[0] != 'I'){
        return false;
    }
    if (index < 0 || index > 26){
        return false;
    }
    return true;
};

int getSlotID(string InvID){ //ambil ID
    string ID;
    int index;
    ID = InvID.erase(0,1);
    index = stoi(ID);
    return index;
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
    this->InvID = InvID;
}
void Use::Execute(Table<3,9>* inventory){
    if (checkID(this->InvID)){
        inventory->useTool(getSlotID(InvID));
        cout << "Item used" << endl;
    }
    else{
        cout << "Masukan salah" << endl;
    }
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

bool Export::checkFilename(){
    regex b("(.*)(.txt)");
    if (!regex_match(this->fileName,b)){
        return false;
    }
    return true;
}

void Export::Execute(Table<3,9>* inventory){
    int row, col, val;
    string ItemId;
    if (checkFilename()){
        ofstream outfile(fileName);
        for (int i=0;i<27;i++){
            col = i % 9;
            row = i / 9;
            if (inventory->checkEmpty(row,col)){ //cek slot kosong
                outfile << "0:0" << endl;
            }
            else{
                ItemId = inventory->getItemId(row,col);
                if (inventory->checkTool(row,col)){
                    val = inventory->getDur(row,col);
                }
                else{
                    val = inventory->getQty(row,col);
                }
                outfile << ItemId << ":" << val << endl;
            }
        }
        outfile.close();
    }
    else{
        cout << "Masukan nama file salah" << endl;
    }
}
