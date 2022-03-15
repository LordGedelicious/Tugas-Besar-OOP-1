#ifndef _ITEM_HPP_
#define _ITEM_HPP_

#include <iostream>
#include <string>

using namespace std;

class Item {
    protected:
        const int id;
        string name; // Rumus Dasarnya (material + tool/nontool name)
        string type; // "Tool" atau "NonTool"
    public:
        // Konstruktor default dari Item dengan nama dan type tertentu, by default jumlah nol.
        Item(string name, string type);
        // Operator Override untuk menambah dan mengurangi jumlah item
        virtual friend Item operator+(int addedQuantity, const Item& other);
        virtual friend Item operator-(int decreasedQuantity, const Item& other);
        // Getter and Setter Functions
        virtual int getID() const;
        virtual string getName() const;
        virtual void setName(string newName);
        // Getter dan Setter buat Type dibuat Pure Abstract Class juga soalnya dia dependen ke childnya
        virtual string getType() const = 0;
        virtual void setType(string newType) = 0;
        // Print Status of Item (dibuat PAC juga karena bakal dioverride childnya)
        virtual void printStatus() const = 0;
};

#endif