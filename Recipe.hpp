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
        Item *RecipeContents[3][3];
        string RecipeResult;
        int IngredientsNeeded;
        bool isRecipeFull; // maksudnya menuhin semua kotak 3x3
        bool isRecipeRowFull; // maksudnya menuhin satu baris dari 3 baris yang ada
        bool isRecipeColumnFull; // maksudnya menuhin satu kolom dari 3 kolom yang ada
    public:
        // by default kosong, diisinya make fungsi lain
        Recipe();
        // Fungsi getter dan setter (basic)
        void updateRecipeFull();
        void updateRecipeRowFull();
        void updateRecipeColumnFull();
        void updateAllBoolean();
        void setRecipeResult(string newResult);
        string getRecipeResult() const;
        bool getIsRecipeFull() const;
        bool getIsRecipeRowFull() const;
        bool getIsRecipeColumnFull() const;
        Item* getIngredientByLocation(int row, int column) const;
        int getIngredientsNeeded() const;
        // Fungsi isi ItemDetails (agak complex dan harus nunggu confirm yang lain baru gw yakin implementasinya)
        void insertIngredient(int row, int column, Item* ingredient);
        // // Fungsi printer isi Recipe
        // void printRecipe();
};

#endif