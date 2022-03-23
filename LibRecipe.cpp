#include "LibRecipe.hpp"
#include "Recipe.hpp"

RecipeList::RecipeList() {
    this->List = new Recipe[this->maxSize];
    this->currentSize = 0;
}

RecipeList::RecipeList(const RecipeList& other) {
    this->List = other.List;
    this->currentSize = other.currentSize;
}

RecipeList::~RecipeList() {}

Recipe RecipeList::getRecipe(int index) const {
    // TODO : Error Handling
    if (index < this->currentSize) {
        return this->List[index];
    }
}

// void RecipeList::addRecipes(const Recipe newRecipe) {
//     if (this->currentSize < this->maxSize) {
//         this->List[this->currentSize] = newRecipe;
//         this->currentSize ++;
//     }
// }

Recipe RecipeList::checkCrafting(Table<3,3> C) {
    for (int i=0; i<currentSize; i++) {
        if (this->List[i].checkRecipe(C)) {
            return this->List[i];
        }
    }
}