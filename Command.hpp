#ifndef _COMMAND_HPP_
#define _COMMAND_HPP_

#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include "Table.hpp"
using namespace std;

class Give{
private:
    int qty;
    string name;
public:
    Give(string name, int qty);
    void Execute();
};

class Discard {
private:
    int qty;
    string InvId;
public:
    Discard(string InvId, int qty);
    void Execute();
};

class Move {
private:
    string src;
    int N;
    string* dest;
public:
    Move(string src, int N, string* dest);
    void Execute();
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
    void Execute();
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
