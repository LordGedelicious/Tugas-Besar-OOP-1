// Include STL headers
#include <array>
#include <algorithm>
#include <vector>
#include <tuple>

// Include other header files
#include "Item.hpp"
#include "command.hpp"
#include "Libitem.hpp"
#include "Recipe.hpp"

#ifndef _LIBRECIPE_HPP_
#define _LIBRECIPE_HPP_

class RecipeList : public Recipe {
    private:
        Recipe *List;
        int currentSize;
        const int maxSize = 100;
    public:
        // default constructor, isinya 0
        RecipeList();
        // cctor
        RecipeList(const RecipeList &other);
        // dtor
        ~RecipeList();
        // Fungsi getter
        Recipe getRecipe(int index) const;
        // Fungsi untuk mengisi RecipeList
        void addRecipes(const Recipe newRecipe);
};

#endif // _LIBRECIPE_HPP_