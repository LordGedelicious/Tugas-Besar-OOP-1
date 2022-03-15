#include "Item.hpp"

#ifndef _NON_TOOL_HPP_
#define _NON_TOOL_HPP_

class NonTool : public Item {
    private:
        int quantity;
        const int maxbufferSize = 64;
    public:
        // Konstruktor NonTool default dengan nama dan jumlah tertentu (type sudah pasti "NonTool")
        NonTool(string name, int quantity);
        // Operator Overloading untuk Mengurangi dan Menambah Jumlah NonTool
        NonTool friend operator+(int addedQuantity, const NonTool& other);
        NonTool friend operator-(int removedQuantity, const NonTool& other);
        // Getter and Setter Functions
        int getID() const;
        string getName() const;
        void setName(string newName);
        // Getter dan Setter buat Type dibuat Pure Abstract Class soalnya dia dependen ke childnya
        string getType() const;
        void setType(string newType);
        // Print Status of NonTool
        void printStatus() const;
};

#endif