#include "Recipe.hpp"

using namespace std;

Recipe::Recipe() {
    this->RecipeContents = new ItemDetails[3][3]; // soalnya cuma bisa keisi sama 9 item doang, dalam bentuk 3x3
    this->RecipeResult = NULL;
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
                if (this->RecipeContents[i][j] != NULL) {
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
                if (this->RecipeContents[j][i] != NULL) {
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

void Recipe::setRecipeResult(string newResult) {
    this->RecipeResult = newResult;
}

string getRecipeResult() const {
    return this->RecipeResult;
}

bool getIsRecipeFull() const {
    return this->isRecipeFull;
}

bool getIsRecipeColumnFull() const {
    return this->isRecipeColumnFull;
}

bool getIsRecipeRowFull() const {
    return this->isRecipeRowFull;
}

Item getIngredientByLocation(int row, int column) const {
    ItemDetails target = this->RecipeContents[row][column];
    return std::get<3>(target);
}

int getIngredientsNeeded() const {
    return this->IngredientsNeeded;
}