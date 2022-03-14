#ifndef __NONTOOL_HPP__
#define __NONTOOL_HPP__
#include <string>
#include "item.hpp"
using namespace std;
class nonTool : public item  {
    protected:
    int Quantity;

    public:
    nonTool(int ID, string _Name, string _Type, int _Quantity);
    nonTool(nonTool const &n, int Qty); // copy nontool different quantity
    nonTool(item const &i, int Qty);
    int get_Quantity();
    void set_Quantity(int _Quantity);
    nonTool operator+(nonTool const &n);
    void printInfo();
};



#endif