#include "LibRecipe.hpp"
#include "Recipe.hpp"
#include <math.h>

using std::filesystem::directory_iterator;

RecipeList::RecipeList() {
}

// RecipeList::RecipeList(const RecipeList& other) {
//     this->List = other.List;
//     this->currentSize = other.currentSize;
// }

// RecipeList::~RecipeList() {}

// Recipe RecipeList::getRecipe(int index) const {
//     // TODO : Error Handling
//     if (index < this->currentSize) {
//         return this->List[index];
//     }
// }

void RecipeList::addRecipes(const Recipe newRecipe) {
    this->List.push_back(newRecipe);
}

Recipe RecipeList::checkCrafting(Table<3,3>* C) {
    // CHECK FOR NONTOOL CRAFT
    for (int i=0; i<this->List.size(); i++) {
        if (this->List[i].checkRecipe(C) || (this->List[i]).mirrorY().checkRecipe(C)) {
            return this->List[i];
        }
    }
    // CHECK FOR TOOL CRAFT
    int toolCount = 0;
    bool valid = true;
    int curID;
    string RecName;
    int RecDur = 0;

    int i=0;
    int j=0;
    while (valid && i<3) {
        j=0;
        while (valid && j<3) {
            if ((C->getItem(i,j)->getname()).compare("-") != 0) {
                // NOT NULL
                if (C->getItem(i,j)->isNonTool()) {
                    // not a tool
                    valid = false;
                }
                else {
                    // a tool
                    if (toolCount == 0) {
                        curID = C->getItem(i,j)->getid();
                        RecName = C->getItem(i,j)->getname();
                        RecDur += C->getItem(i,j)->getdurability();
                    }
                    else {
                        if (curID != C->getItem(i,j)->getid()) {
                            valid = false;
                        }
                        else {
                            RecDur += C->getItem(i,j)->getdurability();
                            toolCount++;
                        }
                    }
                }
            }
            j++;
        }
        i++;
    }

    // if (valid && toolCount == 2) {
    //     RecDur = min(RecDur, 10);
    //     Recipe ret = Recipe();
    //     ret.setResultQty(RecDur);
    //     ret.setRecipeResult(RecName);
    //     cout << "THIS IS A TOOL" << endl;
    //     return ret;
    // }


    string lempar = "Astaga";
    throw lempar;
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

void RecipeList::readRecipeFile (string folder){
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