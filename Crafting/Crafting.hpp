#ifndef CRAFTING_HPP
#define CRAFTING_HPP

#include "../Tool/LibItem2.hpp"
#include <map>


class LibRecipe {
private:
    recipe* r;
};

template <class T, int m, int n>
class recipe {
private:
    map<string,int> ingredients;
    string variable_name[m][n];
    T ItemOut;
public:
    recipe();
};

#endif