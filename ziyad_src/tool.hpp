#ifndef __TOOL_HPP__
#define __TOOL_HPP__
#include <string>
#include "item.hpp"
using namespace std;
class Tool : public item  {
    private:
    string Category;
    int Durability;

    public:
    Tool(int ID, string _Name, string _Category, int _Durability);
    Tool(Tool const &t, int Dur); // copy tool from tool different durability
    Tool(item const &i, int Durability); // copy tool from item
    int get_Durability();
    void set_Durability(int _Durability);
    Tool operator+(Tool const &n);
    void printInfo();
};



#endif