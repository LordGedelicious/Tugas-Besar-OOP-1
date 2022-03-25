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
#include "Exception/BaseException.hpp"
using namespace std;

class Command{
public:
    virtual void printMessage() = 0;
};

class Give : public Command{
private:
    int qty;
    string name;
public:
    Give(string name, int qty);
    void Execute(Table <3,9> *inventory, libitem lib);
    void printMessage();
};

class Discard : public Command{
private:
    int qty;
    string InvId;
public:
    Discard(string InvId, int qty);
    void Execute(Table <3,9> *inventory);
    void printMessage();
};

class Move : public Command{
private:
    string src;
    int N;
    vector<string> dest;
public:
    Move(string src, int N, vector<string> dest);
    void Execute(Table <3,9> *inventory, Table <3,3> *crafting);
    void printMessage();
};

class Use : public Command{
private:
    string InvID;
public:
    Use(string InvID);
    void Execute(Table<3,9>* inventory);
    void printMessage();
};

class Craft : public Command{
public:
    Craft();
    void Execute(Table <3,3> *crafting, Table <3,9> *inventory, RecipeList rList, libitem lib);
    void printMessage();
};

class Export : public Command{
private:
    string fileName;
    Table<3,9> inventory;
public:
    Export(string fileName);
    bool checkFilename();
    void Execute(Table<3,9>* inventory);
    void printMessage();
};

#endif
