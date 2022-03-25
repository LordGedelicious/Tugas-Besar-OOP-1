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

class RecipeList {
    private:
        vector<Recipe> List;
    public:
        // default constructor, isinya 0
        RecipeList();
        // Fungsi untuk mengisi RecipeList
        void addRecipes(const Recipe newRecipe);
        //cek apakah crafting berisi 2 tool yang sejenis
        bool checkPurePairTool(Table<3,3> *C);
        //cek apakah crafting bisa dilakukan
        Recipe checkCrafting(Table<3,3> *C);
        void operator<<(const string& folder); //baca file
        //fungsi untuk mendapatkan file di suatu folder
        vector<filesystem::path> getFilesinFolder (string folder);
        //pisahkan string yang dipisahkan dengan spasi
        vector<string> splitString(string full);
        //tampilkan semua resep
        void showAll();
};

#endif // _LIBRECIPE_HPP_
