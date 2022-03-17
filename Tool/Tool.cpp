#include "Tool.hpp"

Tool::Tool() : Item() {
    this->durability = 0;
}

Tool::Tool(int id,string name, string type, int durability) : Item(id ,name, type, "Tool") {
    this->durability = durability;
}

void Tool::printDetail() const{
    cout << "id: " << this->id << endl << "name: " << this->name << endl << "type:" << this->type << endl << "Durabilty: "<< this->durability << endl;
}