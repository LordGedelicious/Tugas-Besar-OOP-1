#ifndef _COMMAND_HPP_
#define _COMMAND_HPP_

#include <iostream>
#include <string>
using namespace std;

class Show{
public:
    Show();
    void Execute();
};

class Give{
private:
    int qty;
    string name;
public:
    Give(string name, int qty);
    void Execute();
};

class Discard{
private:
    int qty;
    string InvId;
public:
    Discard(string InvId, int qty);
    void Execute();
};

class Move{
private:
    string src;
    int N;
    string* dest;
public:
    Move(string src, int N, string* dest);
    void Execute();
};

class Use{
private:
    string InvId;
public:
    Use(string InvID);
    void Execute();
};

class Craft{
public:
    Craft();
    void Execute();
};

class Export{
private:
    string fileName;
public:
    Export(string fileName);
    void Execute();
};

#endif
