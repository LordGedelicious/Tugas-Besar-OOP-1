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
        printMessage();
    }
    catch (BaseException* e1){
        if (e1->getExpType() == "ItemNF") {
            try{
                Tool t = lib.searchtoolsbyname(this->name);
                for (int i=0;i<this->qty;i++){
                    tool = new Tool(t.getid(), t.getname(), t.gettype(), 10);
                    inventory->give(tool);
                }
                printMessage();
            }
            catch (BaseException* e2){
                e2->printMessage();
            }
        } else {
            e1->printMessage();
        }
    }
}

void Give::printMessage(){
    cout << this->name << " berhasil diberikan" << endl;
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
            printMessage();

        }
        else{
            cout << "Masukan salah" << endl;
        }
    } catch (BaseException* e) {
        e->printMessage();
    }
}

void Discard::printMessage(){
    cout << "Barang berhasil dibuang" << endl;
};

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
                printMessage();
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
                printMessage();
            }
            else{
                cout << "Masukan salah" << endl;
            }
        }
        else if(src == 'C' && dest == 'I'){ //move from craft to ivnen
            if (checkCraftId(this->src) && checkID(this->dest[0])){
                crafting->moveToInventory(getSlotID(this->src), getSlotID(this->dest[0]), inventory);
                printMessage();
            }
            else{
                cout << "Masukan salah" << endl;
            }
        }
        else{
            cout << "Masukan salah" << endl;
        }
    }
    catch (BaseException* e) {
        e->printMessage();
    }
}

void Move::printMessage(){
    char src = this->src[0];
    char dest = this->dest[0][0];
    
    if (src == 'I' && dest == 'I'){
        cout << "Barang berhasil ditumpuk" << endl;
    }
    else if(src == 'I' && dest == 'C'){
        cout << "Barang berhasil dipindahkan ke slot crafting" << endl;
    }
    else if(src == 'C' && dest == 'I'){
        cout << "Barang berhasil dipindahkan ke inventory" << endl;
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
            printMessage();
        }
        else{
            cout << "Masukan salah" << endl;
        }
    } catch (BaseException* e) {
        e->printMessage();
    }
}

void Use::printMessage(){
    cout << "Tool berhasil digunakan" << endl;
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
            NonTool* nontool;
            NonTool nt = lib.searchnontoolsbyname(newRes.getRecipeResult());
            nontool = new NonTool(nt.getid(), nt.getname(), nt.gettype(), newRes.getResultQty());
            inventory->give(nontool);
        }
        crafting->clearAll();
        printMessage();
    }
    catch(BaseException* e){
        e->printMessage();
    }
}

void Craft::printMessage(){
    cout << "Crafting berhasil" << endl;
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
        printMessage();
    }
    else{
        cout << "Masukan nama file salah" << endl;
    }
}

void Export::printMessage(){
    cout << "Export berhasil" << endl;
}