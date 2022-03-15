#include "Item.hpp"

#ifndef _TABLE_HPP_
#define _TABLE_HPP_

template <class T, int maxrow, int maxcol>
class Table {
    private:
        T** item;
        int roweff;
        int coleff;
    public:
        Table() {
            this->item = new T*[maxrow];
            for (int i = 0; i < maxrow; i++) {
                this->item[i] = new T[maxcol];
            }
            this->roweff = 0;
            this->coleff = 0;
        }

        ~Table() {
            delete[] item;
        }

        void show(string id) {
            int k = 0;
            for (int i = 0; i < maxrow; i++) {
                for (int j = 0; j < maxcol; j++) {
                    cout << "[" << id;
                    if (k < 10) {
                        cout << " ";
                    }
                    cout << k << "]";

                    if (j == maxcol - 1) {
                        cout << endl;
                    } else {
                        cout << " ";
                    }
                    k++;
                }
            }
        }

        
};

#endif