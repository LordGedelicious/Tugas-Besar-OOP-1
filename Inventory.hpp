// Ini bayangan gw pake STL Array dan Algorithms
#ifndef _INVENTORY_HPP_
#define _INVENTORY_HPP_

#include "Item.hpp"
#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

class Inventory {
    private:
        bool status = false; // Ini kalau belum diinsialisasi bakal false
        const int maxSize = 27;
        array<Item*, 27> InventoryList;
    public:
        // Default constructor, isi kosong dengan maksimum ukuran 27
        Inventory();
        // Tidak ada user-defined constructor, soalnya ya mau diisi gimana wkwkwk
        // Copy Constructor (jujur kyknya gaakan kepake karena cuma 1 wkwkwk)
        Inventory(const Inventory& other);
        // Delete Constructor (kepake di akhir pas "quit")
        ~Inventory();

        // Operator Overloading buat Nambah atau Ngurangin Item ke dalam InventoryList
        // By default langsung nambah sebuah item ke dalam InventoryList, atau langsung ngehilangin item dari InventoryList
        // Contoh : 
        // Inventory Inv; # Asumsi udah ada isinya
        // Inv += Tool("Diamond Pickaxe", 9); # Menambahkan satu Diamond Pickaxe dengan Durability 9 ke Inv
        // Inv -= NonTool("Diamond", 3); # Mengurangi jumlah Diamond pada Inv sebanyak 3 buah
        Inventory& operator+=(const Item& newItem);
        Inventory& operator-=(const Item& reducedItem);

        // Search Functions
        int findIndexByName(string nameQuery) const; // Mengembalikan indeks Item pada InventoryList berdasarkan nama
        int findIndexByItem(Item itemQuery) const; // Mengembalikan indeks Item pada InventoryList berdasarkan Item 

        // Manipulation Functions
        void addNonToolQuantityByName(int addedQuantity, string nonToolName);
        void addNonToolQuantityByIndex(int addedQuantity, int index);
        void decNonToolQuantityByName(int decreasedQuantity, string nonToolName);
        void decNonToolQuantityByIndex(int decreasedQuantity, int index);

        void addToolDurabilityByName(int addedDurability, string toolName);
        void addToolDurabilityByIndex(int addedDurability, int index);
        void decToolDurabilityByName(int decreasedDurability, string toolName);
        void decToolDurabilityByIndex(int decreasedDurability, int index);

        // Add/Delete Functions
        void addItems(Item& newItem);
        void deleteItems(Item& discardItem);

        // Print Functions
        void printItemStatusByIndex(int index) const;
        void printInventory() const;
};

#endif // _INVENTORY_HPP_