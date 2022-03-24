#ifndef _COMMAND_HPP_
#define _COMMAND_HPP_

#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <vector>
#include "Table.hpp"
#include "Libitem.hpp"
#include "LibRecipe.hpp"
using namespace std;

class Give{
private:
    int qty;
    string name;
public:
    Give(string name, int qty);
    void Execute(Table <3,9> *inventory, libitem lib);
};

class Discard {
private:
    int qty;
    string InvId;
public:
    Discard(string InvId, int qty);
    void Execute(Table <3,9> *inventory);
};

class Move {
private:
    string src;
    int N;
    vector<string> dest;
public:
    Move(string src, int N, vector<string> dest);
    void Execute(Table <3,9> *inventory, Table <3,3> *crafting);
};

class Use {
private:
    string InvID;
public:
    Use(string InvID);
    void Execute(Table<3,9>* inventory);
};

class Craft {
public:
    Craft();
    void Execute(Table <3,3> *crafting, Table <3,9> *inventory, RecipeList rList, libitem lib);
};

class Export {
private:
    string fileName;
    Table<3,9> inventory;
public:
    Export(string fileName);
    bool checkFilename();
    void Execute(Table<3,9>* inventory);
};

#endif
