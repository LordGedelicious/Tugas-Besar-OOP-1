#include "pch.h"
#include "LibRecipe.hpp"
#include "Recipe.hpp"
#include <math.h>

using std::filesystem::directory_iterator;

RecipeList::RecipeList() {
}

void RecipeList::addRecipes(const Recipe newRecipe) {
    this->List.push_back(newRecipe);
}

bool RecipeList::checkPurePairTool(Table<3,3> *C){
    bool pair = true;
    bool pure = true;
    bool found = false;
    string toolName;
    int toolCount = 0;
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            if (C->getItem(i,j)->isNonTool()){
                pure = false;
                break;
            }
            if (C->getItem(i,j)->isTool()){
                if (!found){
                    toolName = C->getItem(i,j)->getname();
                    toolCount += 1;
                }
                else{
                    if (C->getItem(i,j)->getname() != toolName){
                        pure = false;
                        break;
                    }
                    toolCount += 1;
                }
            }
        }
    }
    if (toolCount != 2){
        pair = false;
    }
    return pair && pure;
}

Recipe RecipeList::checkCrafting(Table<3,3>* C) {
    //CRAFT TOOL
    Recipe newRes;
    string name;
    bool found = false;
    int dur1, dur2, dur;
    if (checkPurePairTool(C)){
        for (int i=0;i<3;i++){
            for (int j=0;j<3;j++){
                if (C->getItem(i,j)->isTool()){
                    if (!found){
                        found = true;
                        name = C->getItem(i,j)->getname();
                        dur1 = C->getItem(i,j)->getdurability();
                    }
                    else{
                        dur2 = C->getItem(i,j)->getdurability();
                    }
                }
            }
        }
        dur = min(10, dur2 + dur1);
        newRes.setRecipeResult(name);
        newRes.setResultQty(dur);
        newRes.setColSize(-999);
        return newRes;
    }

    // CHECK FOR NONTOOL CRAFT
    for (int i=0; i<this->List.size(); i++) {
        if (this->List[i].checkRecipe(C) || (this->List[i]).mirrorY().checkRecipe(C)) {
            return this->List[i];
        }
    }

    throw new CraftingInvalidException();
}

vector<filesystem::path> RecipeList::getFilesinFolder(string folder){
    vector<filesystem::path> files;
    for (const auto & file : directory_iterator(folder)){
        files.push_back(file.path());
    }
    return files;
}

vector<string> RecipeList::splitString(string full){
    string space_delimiter = " ";
    vector<string> words{};

    size_t pos = 0;
    while ((pos = full.find(space_delimiter)) != string::npos) {
        words.push_back(full.substr(0, pos));
        full.erase(0, pos + space_delimiter.length());
    }
    words.push_back(full);
    return words;
}

void RecipeList::operator<<(const string& folder){
    string str;
    vector<string> ingredients;
    vector<filesystem::path> files = getFilesinFolder(folder);

    for (int i=0;i<files.size();i++){
        string filename{files[i].u8string()};
        ifstream file(filename);
        Recipe newRes;
        if (file.is_open()){
            getline(file,str,' ');
            newRes.setRowSize(stoi(str));
            getline(file,str);
            newRes.setColSize(stoi(str));
            for (int i=0;i<newRes.getRowSize();i++){
                getline(file,str);
                ingredients = splitString(str);
                for (int j=0;j<ingredients.size();j++){
                    newRes.insertIngredient(i,j,ingredients[j]);
                }
            }
            getline(file,str,' ');
            newRes.setRecipeResult(str);
            getline(file,str);
            newRes.setResultQty(stoi(str));
        }
        addRecipes(newRes);
    }
}

void RecipeList::showAll(){
    for (int i=0;i<this->List.size();i++){
        this->List[i].printRecipe();
        cout << endl;
    }
}
