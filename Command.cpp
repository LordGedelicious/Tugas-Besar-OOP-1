#include "Command.hpp"

bool checkID(string InvID){ //validasi ID inventory
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
}

bool checkCraftId(string CrafID){ //validasi ID crafting
    string ID = CrafID;
    int index;
    CrafID.erase(0,1);
    index = stoi(CrafID);
    if (ID[0] != 'C'){
        return false;
    }
    if (index < 0 || index > 8){
        return false;
    }
    return true;
}

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

void Give::Execute(Table <3,9> *inventory, libitem lib){
    NonTool* nontool;
    Tool* tool;
    try{
        NonTool nt = lib.searchnontoolsbyname(this->name);
        nontool = new NonTool(nt.getid(), nt.getname(), nt.gettype(), this->qty);
        inventory->give(nontool);
        cout << "Give berhasil" << endl;
    }
    catch (BaseException* e1){ //gataudah ini bener ato belom
        if (e1->getExpType() == "ItemNF") {
            try{
                Tool t = lib.searchtoolsbyname(this->name);
                for (int i=0;i<this->qty;i++){
                    tool = new Tool(t.getid(), t.getname(), t.gettype(), 10);
                    inventory->give(tool);
                }
                cout << "Give berhasil" << endl;
            }
            catch (BaseException* e2){
                e2->printMessage();
            }
        } else {
            e1->printMessage();
        }
    }
}

//Discard
Discard::Discard(string InvId, int qty){
    this->InvId = InvId;
    this->qty = qty;
}

void Discard::Execute(Table <3,9> *inventory){
    try {
        if (checkID(this->InvId)){
            
            inventory->discard(getSlotID(this->InvId),this->qty);
            cout << "Discard berhasil" << endl;

        }
        else{
            cout << "Masukan salah" << endl;
        }
    } catch (BaseException* e) {
        e->printMessage();
    }
}

//Move
Move::Move(string src, int N, vector<string> dest){
    this->src = src;
    this->N = N;
    this->dest = dest;
}

void Move::Execute(Table <3,9> *inventory, Table <3,3> *crafting){
    char src = this->src[0];
    char dest = this->dest[0][0];
    try {
        if (src == 'I' && dest == 'I'){ //stack
            if (checkID(this->src) && checkID(this->dest[0])){
                inventory->stackNonTool(getSlotID(this->src),getSlotID(this->dest[0]));
                cout << "Stack berhasil" << endl;
            }
            else{
                cout << "Masukan salah" << endl;
            }
        }
        else if(src == 'I' && dest == 'C'){
            if (checkID(this->src) && checkCraftId(this->dest[0])){
                for (int i=0;i<this->N;i++){
                    inventory->moveToCraft(getSlotID(this->src), getSlotID(this->dest[i]), crafting);
                }
                cout << "Move inventory to craft" << endl;
            }
            else{
                cout << "Masukan salah" << endl;
            }
        }
        else if(src == 'C' && dest == 'I'){ //move from craft to ivnen
            if (checkCraftId(this->src) && checkID(this->dest[0])){
                crafting->moveToInventory(getSlotID(this->src), getSlotID(this->dest[0]), inventory);
                cout << "Move craft to inventory" << endl;
            }
            else{
                cout << "Masukan salah" << endl;
            }
        }
        else{
            cout << "masukan salah" << endl;
        }
    }
    catch (BaseException* e) {
        e->printMessage();
    }
}

//Use
Use::Use(string InvID){
    this->InvID = InvID;
}

void Use::Execute(Table<3,9>* inventory){
    try {
        if (checkID(this->InvID)){
            inventory->useTool(getSlotID(InvID));
            cout << "Item used" << endl;
        }
        else{
            cout << "Masukan salah" << endl;
        }
    } catch (BaseException* e) {
        e->printMessage();
    }
}

//Craft
Craft::Craft(){    
}

void Craft::Execute(Table <3,3> *crafting, Table <3,9> *inventory, RecipeList rList, libitem lib){
    try{
        Recipe newRes = rList.checkCrafting(crafting);
        if (newRes.getColSize() == -999){
            Tool* tool;
            Tool t = lib.searchtoolsbyname(newRes.getRecipeResult());
            tool = new Tool(t.getid(), t.getname(), t.gettype(), newRes.getResultQty());
            inventory->give(tool);
        }
        else{
            Give give(newRes.getRecipeResult(), newRes.getResultQty());
            give.Execute(inventory, lib);
        }
        crafting->clearAll();
    }
    catch(BaseException* e){
        e->printMessage();
    }
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
    int row, col, val, ItemId;
    if (checkFilename()){
        inventory->exportFile(fileName);
        cout << "Export berhasil" << endl;
    }
    else{
        cout << "Masukan nama file salah" << endl;
    }
}
