#include <iostream>
#include "item.hpp"
#include "tool.hpp"
#include "nontool.hpp"
using namespace std;


template<class Base, class T>
bool instanceof(const T *ptr) {
   return dynamic_cast<const Base*>(ptr) != nullptr;
}
template<class T>
bool isTool(const T *ptr) {
    return instanceof<Tool>(ptr);
}

template<class T>
bool isNonTool(const T *ptr) {
    return instanceof<nonTool>(ptr);
}
