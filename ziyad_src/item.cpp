#include "item.hpp"

item::item() : ID(0) {
    this->Name = "-";
    this->Type = "-";
}

item::item(int ID, string Name, string type) : ID(ID) {
    this->Name = Name;
    this->Type = type;
}
item::item(item const &i) : ID(i.ID) {
    this->Name = i.Name;
    this->Type = i.Type;
}
int item::get_ID() {
    return this->ID;
}
string item::get_Name() {
    return this->Name;
}
string item::get_Type() {
    return this->Type;
}
void item::operator=(item const &i) {
    this->ID = i.ID;
    this->Name = i.Name;
    this->Type = i.Type;
}


bool item::operator==(item const &i) {
    return i.ID == this->ID;
}

void item::printInfo() {
    cout << "ID: " << get_ID() << endl;
    cout << "Name: " << get_Name() << endl;
    cout << "Type: " << get_Type() << endl;
}