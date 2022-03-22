#include "Recipe.hpp"

using namespace std;

Recipe::Recipe() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            this->RecipeContents[i][j] = new Item();
        }
    }
    this->RecipeResult = "";
    this->isRecipeFull = false;
    this->isRecipeRowFull = false;
    this->isRecipeColumnFull = false;
    this->IngredientsNeeded = 0;
}

void Recipe::updateRecipeFull() {
    // cek dulu semua slot 3x3 udah penuh atau belum, kalo udah penuh baru set ke true
    if (this->IngredientsNeeded == 9) {
        this->isRecipeFull = true;
    } else {
        this->isRecipeFull = false;
    }
}

void Recipe::updateRecipeRowFull() {
    // cek dulu jumlah slot yang keisi, kalo udah lebih dari 3 baru cek isi detailnya
    if (this->IngredientsNeeded < 3) {
        this->isRecipeRowFull = false;
    } else {
        bool isRowFull = false;
        int countExist;
        for (int i = 0; i <= 3; i++) {
            countExist = 0;
            for (int j = 0; j <= 3; j++) {
                if (this->RecipeContents[i][j]->getname() != "") {
                    countExist++;
                }
            }
            if (countExist == 3) {
                isRowFull = true;
            }
        }
        this->isRecipeRowFull = isRowFull;
    }
}

void Recipe::updateRecipeColumnFull() {
    // cek dulu jumlah slot yang keisi, kalo udah lebih dari 3 baru cek isi detailnya
    if (this->IngredientsNeeded < 3) {
        this->isRecipeColumnFull = false;
    } else {
        bool isColumnFull = false;
        int countExist;
        for (int i = 0; i <= 3; i++) {
            countExist = 0;
            for (int j = 0; j <= 3; j++) {
                if (this->RecipeContents[j][i]->getname() != "") {
                    countExist++;
                }
            }
            if (countExist == 3) {
                isColumnFull = true;
            }
        }
        this->isRecipeColumnFull = isColumnFull;
    }
}

void Recipe::updateAllBoolean() {
    this->updateRecipeFull();
    this->updateRecipeRowFull();
    this->updateRecipeColumnFull();
}

void Recipe::setRecipeResult(string newResult) {
    this->RecipeResult = newResult;
}

string Recipe::getRecipeResult() const {
    return this->RecipeResult;
}

bool Recipe::getIsRecipeFull() const {
    return this->isRecipeFull;
}

bool Recipe::getIsRecipeColumnFull() const {
    return this->isRecipeColumnFull;
}

bool Recipe::getIsRecipeRowFull() const {
    return this->isRecipeRowFull;
}

Item* Recipe::getIngredientByLocation(int row, int column) const {
    return this->RecipeContents[row][column];
}

int Recipe::getIngredientsNeeded() const {
    return this->IngredientsNeeded;
}

void Recipe::insertIngredient(int row, int column, Item* ingredient) {
    if (this->RecipeContents[row][column]->getname() == "") {
        this->RecipeContents[row][column] = ingredient;
        this->IngredientsNeeded ++;
        this->updateAllBoolean();
    }
}