// Include STL headers
#include <array>
#include <algorithm>
#include <vector>
#include <tuple>
#include <filesystem>

// Include other header files
#include "Item.hpp"
#include "command.hpp"
#include "Libitem.hpp"
#include "Recipe.hpp"

#ifndef _LIBRECIPE_HPP_
#define _LIBRECIPE_HPP_

class RecipeList : public Recipe {
    private:
        vector<Recipe> List;
    public:
        // default constructor, isinya 0
        RecipeList();
        // Fungsi untuk mengisi RecipeList
        void addRecipes(const Recipe newRecipe);
        // Fungsi untuk mendapatkan resep yang cocok untuk crafting
        bool checkPurePairTool(Table<3,3> *C);
        Recipe checkCrafting(Table<3,3> *C);
        void operator<<(const string& folder); //baca file
        vector<filesystem::path> getFilesinFolder (string folder);
        vector<string> splitString(string full);
        void showAll();
};

#endif // _LIBRECIPE_HPP_
