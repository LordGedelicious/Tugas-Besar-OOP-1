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
    private:
        tuple<Item*, int> slotTable; // Isinya Item dan jumlah itemnya
        slotTable *craftingTable[3][3]; // slot table 3x3
    public:
        // hanya dibuat default constructor. tidak ada user-defined constructor
        CraftingTable();
        // Fungsi getter dan setter
        Item getItemByLocation(int row, int column) const;
        int getQtyByLocation(int row, int column) const;
        void setItemByLocation(int row, int column, Item* item); // by default, jumlahnya 1 dan harus ada di inventory
        void setItemByLocation(int row, int column, Item* item, int qty); // jumlah qty harus ada di inventory
        // Fungsi validasi awal isi CraftingTable (basic banget, tapi gw mikir ini bakal ngehemat waktu)
        bool isAllTools();
        bool isAllNonTools();
        // Fungsi mengembalikan array of tuple berisi type item dan posisi semua item di crafting table
        *tuple<string, int> whatIsWhere();
        Item* craftResults();
};

#endif