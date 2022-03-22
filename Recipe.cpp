#include "Recipe.hpp"

using namespace std;

Recipe::Recipe(int rowSize, int colSize) {
    this->RecipeResult = "";
    this->RecipeContents = new NonTool*[this->maxRowSize];
    for (int i = 0; i < this->maxRowSize; i++) {
        this->RecipeContents[i] = new NonTool[this->maxColumnSize];
    }
}

void Recipe::setRecipeResult(string newResult) {
    this->RecipeResult = newResult;
}

string Recipe::getRecipeResult() const {
    return this->RecipeResult;
}

Item Recipe::getIngredientByLocation(int row, int column) const {
    return this->RecipeContents[row][column];
}

void Recipe::insertIngredient(int row, int column, string ingredient, libitem library) {
    if (this->RecipeContents[row][column].getname() == "") {
        NonTool target = library.searchnontoolsbyname(ingredient);
        this->RecipeContents[row][column] = target;
    }
}