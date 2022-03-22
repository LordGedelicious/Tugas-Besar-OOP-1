// Include STL headers
#include <array>
#include <algorithm>
#include <vector>
#include <tuple>

// Include other header files
#include "Item.hpp"
#include "command.hpp"
#include "Libitem.hpp"
#include "LibRecipe.hpp"

#ifndef _CRAFTING_HPP_
#define _CRAFTING_HPP_

class CraftingTable {
    // Karena gaada id disini, jadinya gini ya:
    // C0 -> [0][0], C1 -> [0][1], C2 -> [0][2]
    // C3 -> [1][0], C4 -> [1][1], C5 -> [1][2]
    // C6 -> [2][0], C7 -> [2][1], C8 -> [2][2]
    private:
        tuple<Item, int> slotTable; // Isinya Item dan jumlah itemnya
        slotTable *craftingTable[3][3]; // slot table 3x3
    public:
        // hanya dibuat default constructor, cctor, dan dtor. tidak ada user-defined constructor
        CraftingTable();
        CraftingTable(const CraftingTable & other);
        ~CraftingTable()
        // Fungsi getter dan setter, row dan column zero-based
        Item getItemByLocation(int row, int column) const;
        int getQtyByLocation(int row, int column) const;
        void addItemByLocation(int row, int column, Item newItem, int qty); // jumlah qty harus ada di inventory
        // Fungsi validasi awal isi CraftingTable (basic banget, tapi gw mikir ini bakal ngehemat waktu)
        bool isAllTools();
        bool isAllNonTools();
        // Fungsi mengembalikan array of tuple berisi type item dan posisi semua item di crafting table
        *tuple<string, int> whatIsWhere();
        void craftResults(); // Memanfaatkan returnToInventory
        // Fungsi menampilkan isi dari CraftingTable
        void printCraftingTable() const;
        // Fungsi untuk meletakkan barang di CraftingTable atau Inventory (menggunakan setItemByLocation)
        void putToCraftingTable(const Item& newItem, int row, int column);
        void returnToInventory(const Item& newItem, int row, int column);
        // Diasumsikan tidak butuh fungsi clear
};

#endif