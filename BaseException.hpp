#ifndef __BASE_EXCEPTION_HPP__
#define __BASE_EXCEPTION_HPP__

#include <iostream>
#include "LibItem.hpp"
using namespace std;

class BaseException {
protected: 
    string expType;
public:
    BaseException();
    string getExpType() const;
    virtual void printMessage() = 0;
};

class InventoryFullException : public BaseException {
    public:
        InventoryFullException();
        void printMessage() override;
};

class ItemNotFoundException : public BaseException {
    private:
        int id;
        string name;
    public:
        ItemNotFoundException(string name);
        ItemNotFoundException(int id);
        void printMessage() override;
};

class DiscardInvalidException : public BaseException {
    private:
        int slotID;
    public:
        DiscardInvalidException(int slotID);
        void printMessage() override;
};

class NotNonToolException : public BaseException {
    private:
        Item* falseItem;
    public:
        NotNonToolException(Item* failItem);
        void printMessage() override;
};

class NotToolException : public BaseException {
    private:
        Item* falseItem;
    public:
        NotToolException(Item* failItem);
        void printMessage() override;
};

class ItemInvalidException : public BaseException {
    private:
        Item* srcItem;
        Item* destItem;
    public:
        ItemInvalidException(Item* srcItem, Item* destItem);
        void printMessage() override;
};

class NotEmptySlotException : public BaseException {
    private:
        int slotID;
        char type;
    public:
        NotEmptySlotException(char type, int slotID);
        void printMessage() override;
};

class EmptySlotException : public BaseException {
    private:
        int slotID;
        char type;
    public:
        EmptySlotException(char type, int slotID);
        void printMessage() override;
};

class CraftingInvalidException : public BaseException {
    public:
        CraftingInvalidException();
        void printMessage() override;
};
#endif