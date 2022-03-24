#include "Recipe.hpp"

using namespace std;

Recipe::Recipe(){
    this->RecipeResult = "-";
    this->resultQty = 0;
    this->rowSize = 0;
    this->colSize = 0;
    this->RecipeContents = new string*[this->maxRowSize];
    for (int i = 0; i < this->maxRowSize; i++) {
        this->RecipeContents[i] = new string[this->maxColumnSize];
    }
}

void Recipe::setRecipeResult(string newResult) {
    this->RecipeResult = newResult;
}

string Recipe::getRecipeResult() const {
    return this->RecipeResult;
}

void Recipe::setResultQty(int newQty){
    this->resultQty = newQty;
}

int Recipe::getResultQty() const{
    return this->resultQty;
}

void Recipe::setRowSize (int rowSize){
    this->rowSize = rowSize;
}

int Recipe::getRowSize() const{
    return this->rowSize;
}

void Recipe::setColSize (int colSize){
    this->colSize = colSize;
}

int Recipe::getColSize() const{
    return this->colSize;
}

string Recipe::getIngredientByLocation(int row, int column) const {
    return this->RecipeContents[row][column];
}

void Recipe::insertIngredient(int row, int column, string ingredient) {
    this->RecipeContents[row][column] = ingredient;
}

void Recipe::printRecipe(){
    cout << this->RecipeResult << " " << this->resultQty << endl;
    cout << this->rowSize << "x" << this->colSize << endl;
    for (int i=0;i<this->rowSize;i++){
        for (int j=0;j<this->colSize;j++){
            cout << this->RecipeContents[i][j];
            if (j < this->colSize-1){
                cout << " ";
            }
        }
        cout << endl;
    }
}

bool Recipe::checkRecipe(Table<3,3> *C) {
    int i=0;
    int j=0;
    bool found = false;
    bool flag = false;
    bool same = true;
    string CraftItemName;
    string CraftItemType;
    string RecipeItem;

    int a, b;


    while (!found && i<=(3 - this->getRowSize())) {
        j = 0;
        while (!found && j<=(3- this->getColSize())) {
            // cek apakah sesuai
            a = 0;
            same = true;
            while (same && a<(this->getRowSize())) {
                b = 0;
                while (same && b<(this->getColSize())) {
                    CraftItemName = C->getItem(i+a, j+b)->getname();
                    CraftItemType = C->getItem(i+a, j+b)->gettype();
                    RecipeItem = getIngredientByLocation(a, b);
                    if (RecipeItem == "PLANK" || RecipeItem == "LOG" || RecipeItem == "STONE") {

                        // is a type
                        if (RecipeItem.compare(CraftItemType) == 0) {
                            // still same

                        }
                        else {
                            // not same
                            same = false;

                        }
                    }
                    else {
                        // is not a type

                        if (RecipeItem.compare(CraftItemName) == 0) {
                            // still same

                        }
                        else {
                            // not same
                            same = false;

                        }
                    }

                    if (same) {
                        // check if all others are null item
                        found = true;
                        int x = 0;
                        int y = 0;
                        while (x<3 && found) {
                            y = 0;
                            while (y<3 && found) {
                                if (x>=i && x<i+getRowSize() && y>=j && y<j+getColSize()) {
                                    // OKAY

                                }
                                else {
                                    CraftItemName = C->getItem(x, y)->getname();
                                    if (CraftItemName.compare("-") != 0) {

                                        found = false;
                                    } 
                                    else {
                                        // OKAY

                                    }
                                }
                                y++;
                            }
                            x++;
                        }
                    }
                    
                    b++;
                }
                a++;
            }


            j++;
        }
        i++;
    }

    return found;
}

Recipe Recipe::mirrorY() {
    Recipe tempR;
    string tempI;
    for (int i=0; i<this->getRowSize(); i++) {
        for (int j=0; j<this->getColSize(); j++) {
            tempI = this->getIngredientByLocation(i, j);
            tempR.insertIngredient(i, (this->getColSize()-j-1), tempI);
        }
    }
    return tempR;
}
