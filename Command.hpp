#ifndef _COMMAND_HPP_
#define _COMMAND_HPP_

#include <iostream>
#include <string>
using namespace std;

class Command{
public:
    Command();
    virtual void Execute() = 0;
};

class Show : public Command{
public:
    Show();
    void Execute();
};

class Give : public Command{
private:
    int qty;
    string name;
public:
    Give(string name, int qty);
    void Execute();
};

class Discard : public Command{
private:
    int qty;
    string InvId;
public:
    Discard(string InvId, int qty);
    void Execute();
};

class Move : public Command{
private:
    string src;
    int N;
    string* dest;
public:
    Move(string src, int N, string* dest);
    void Execute();
};

class Use : public Command{
private:
    string InvId;
public:
    Use(string InvID);
    void Execute();
};

class Craft : public Command{
public:
    Craft();
    void Execute();
};

class Export : public Command{
private:
    string fileName;
public:
    Export(string fileName);
    void Execute();
};

#endif
