#include "tool.hpp"
#include <string>
#include <iostream>
using namespace std;

Tool::Tool(int _ID, string _Name, string _Type, int _Durability) : item(_ID, _Name, _Type) {
    this->Durability = _Durability;
}
Tool::Tool(Tool const &t, int Dur) : item(t) {
    this->Durability = Dur;
}
Tool::Tool(item const &i, int Dur) : item(i) {
    this->Durability = Dur;
}
int Tool::get_Durability() {
    return this->Durability;
}
void Tool::set_Durability(int _Durability) {
    this->Durability = _Durability;
}
Tool Tool::operator+(Tool const &t) {
    Tool tRet = t;
    if (this->get_ID() == t.ID) {
    tRet.Durability = t.Durability + this->Durability;
    }
    return tRet;

}
void Tool::printInfo() {
    cout << "ID: " << get_ID() << endl;
    cout << "Name: " << get_Name() << endl;
    cout << "Type: " << get_Type() << endl;
    cout << "Durability: " << get_Durability() << endl;
}