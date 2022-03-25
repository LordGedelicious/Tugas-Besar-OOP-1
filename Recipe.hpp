// Include STL headers
#include <array>
#include <algorithm>
#include <vector>
#include <tuple>
#include <string>
#include <iostream>

// Include other header files
#include "Item.hpp"
#include "Command.hpp"
#include "Libitem.hpp"

#ifndef _RECIPE_HPP_
#define _RECIPE_HPP_

using namespace std;

class Recipe {
    private:
        string **RecipeContents;
        string RecipeResult;
        int resultQty;
        int rowSize;
        int colSize;
        const int maxRowSize = 3;
        const int maxColumnSize = 3;
    public:
        Recipe();
        // Fungsi getter dan setter (basic)
        void setRecipeResult(string newResult);
        string getRecipeResult() const;
        void setResultQty(int newQty);
        int getResultQty() const;
        void setRowSize (int rowSize);
        int getRowSize() const;
        void setColSize (int colSize);
        int getColSize() const;

        string getIngredientByLocation(int row, int column) const;
        // Fungsi isi ItemDetails (agak complex dan harus nunggu confirm yang lain baru gw yakin implementasinya)
        void insertIngredient(int row, int column, string ingredient);
        // Fungsi printer isi Recipe
        void printRecipe();
        // Fungsi untuk cek apakah resep cocok
        bool checkRecipe(Table<3,3> *C);
        // Fungsi untuk mirror resep thdp sumbu y
        Recipe mirrorY();
};

#endif