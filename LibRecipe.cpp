#include "LibRecipe.hpp"
#include "Recipe.hpp"

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
    for (int i=0; i<this->List.size(); i++) {
        if (this->List[i].checkRecipe(C) || (this->List[i]).mirrorY().checkRecipe(C)) {
            return this->List[i];
        }
    }
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