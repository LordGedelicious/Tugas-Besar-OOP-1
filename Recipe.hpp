// Include STL headers
#include <array>
#include <algorithm>
#include <vector>
#include <tuple>
#include <string>

// Include other header files
#include "Item.hpp"
#include "command.hpp"
#include "Libitem.hpp"

#ifndef _RECIPE_HPP_
#define _RECIPE_HPP_

using namespace std;

class Recipe {
    private:
        NonTool **RecipeContents;
        string RecipeResult;
        int resultQty;
        int rowSize;
        int colSize;
        const int maxRowSize = 3;
        const int maxColumnSize = 3;
    public:
        // by default cuma diisi sama rowSize sama columnSize, diisinya make fungsi lain
        Recipe(int rowSize, int colSize);
        // Fungsi getter dan setter (basic)
        void setRecipeResult(string newResult);
        string getRecipeResult() const;
        void setResultQty(int newQty);
        int getResultQty() const;
        Item getIngredientByLocation(int row, int column) const;
        // Fungsi isi ItemDetails (agak complex dan harus nunggu confirm yang lain baru gw yakin implementasinya)
        void insertIngredient(int row, int column, string ingredient, libitem library);
        // Fungsi printer isi Recipe
        // void printRecipe();
};

#endif