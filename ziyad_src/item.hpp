#ifndef __ITEM_HPP__
#define __ITEM_HPP__
#include <string>
#include <iostream>
using namespace std;
class item {
    protected:
    int ID;
    string Name;
    string Type;

    public:
    item();
    item(int ID, string _Name, string Type);
    item(item const &i);
    int get_ID();
    string get_Name();
    string get_Type();
    void operator=(item const &i);
    bool operator==(item const &i);
    virtual void printInfo();
};



#endif