#include "Item.hpp"

#ifndef _TOOL_HPP_
#define _TOOL_HPP_

class Tool : public Item {
    private:
        int durability;
    public:
        // Konstruktor Tool default dengan nama dan durability tertentu (type sudah pasti "Tool")
        Tool(string name, int durability);
        // Operator Override untuk Menambah dan Mengurangi Durability Tool
        Tool friend operator+(int addedDurability, const Tool& other);
        Tool friend operator-(int reducedDurability, const Tool& other);
        // Getter and Setter Functions
        int getID() const;
        string getName() const;
        void setName(string newName);
        string getType() const;
        void setType(string newType);
        int getDurability() const;
        void setDurability(int newDurability);
        // Print Status of Tool
        void printStatus() const;
};

#endif