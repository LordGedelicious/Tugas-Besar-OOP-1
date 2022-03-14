#include "nontool.hpp"
#include <iostream>
#include <string>
using namespace std;


nonTool::nonTool(int _ID, string _Name, string _Type, int _Quantity) : item(_ID, _Name, _Type) {
    this->Quantity = _Quantity;
}

nonTool::nonTool(nonTool const &n, int Qty) : item(n) {
    this->Quantity = Qty;
}
nonTool::nonTool(item const &i, int Qty) : item(i) {
    this->Quantity = Qty;
}


int nonTool::get_Quantity() {
    return this->Quantity;
}
void nonTool::set_Quantity(int _Quantity) {
    this->Quantity = _Quantity;
}



nonTool nonTool::operator+(nonTool const &n) {
    nonTool nRet = n;
    if (this->get_ID() == n.ID) {
    nRet.Quantity = n.Quantity + this->Quantity;
    }
    return nRet;
    // else exception
    

}
void nonTool::printInfo() {
    cout << "ID: " << get_ID() << endl;
    cout << "Name: " << get_Name() << endl;
    cout << "Type: " << get_Type() << endl;
    cout << "Quantity: " << get_Quantity() << endl;
}