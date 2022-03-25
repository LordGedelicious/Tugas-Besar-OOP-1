#ifndef LIBITEM_HPP_
#define LIBITEM_HPP_

#include <iostream>
#include "Item.hpp"
#include "Tool.hpp"
#include "NonTool.hpp"
#include "BaseException.hpp"
#include <vector>
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

using namespace std;

class libitem {
    private:
    vector<Tool> tools;
    vector<NonTool> nontools;
    public:
    libitem();
    //Tambahkan item ke library item
    void addItem(int ID, string name, string type, string category);
    //Cari nontool di library dengan nama
    NonTool searchnontoolsbyname(string name) const;
    //Cari nontool di library dengan id
    NonTool searchnontoolsbyid(int id) const;
    //Cari tool di library dengan nama
    Tool searchtoolsbyname(string name) const;
    //Cari tool di library dengan id
    Tool searchtoolsbyid(int id) const;
    //cetak library item
    void printlibitem();
    void operator<<(const string& fileName); //baca file
};

#endif
