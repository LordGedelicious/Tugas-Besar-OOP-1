#include "Item.hpp"
#include "NonTool.hpp"
#include "Tool.hpp"
#include <math.h>
#include <fstream>

#ifndef _TABLE_HPP_
#define _TABLE_HPP_

template <int maxrow, int maxcol>
class Table {
    private:
        Item*** item;
    public:
        Table() {
            this->item = new Item**[maxrow];
            for (int i = 0; i < maxrow; i++) {
                this->item[i] = new Item*[maxcol];
                for (int j = 0; j < maxcol; j++) {
                    this->item[i][j] = new NonTool();
                }
            }
        }

        ~Table() {
            delete[] item;
        }

        int getEmptyCol(int row) {
            int j = 0;
            while (j < maxcol && !this->item[row][j]->isEmpty()) {
                j++;
            }
            return j;
        }

        int getEmptyRow() {
            int i = 0;
            while (i < maxrow && this->getEmptyCol(i) == maxcol) {
                i++;
            }
            return i;
        }

        void show(string id) {
            int k = 0;
            for (int i = 0; i < maxrow; i++) {
                for (int j = 0; j < maxcol; j++) {
                    cout << "[";
                    if (this->item[i][j]->isEmpty()) {
                        cout << id;
                        if (k < 10) {
                            cout << " ";
                        }
                        cout << k;
                    } else {
                        cout << this->item[i][j]->getname() << " ";
                        if (this->item[i][j]->isTool()) {
                            cout << this->item[i][j]->getdurability();
                        } else {
                            cout << this->item[i][j]->getquantity();
                        }
                    }
                    cout << "]";

                    if (j == maxcol - 1) {
                        cout << endl;
                    } else {
                        cout << " ";
                    }
                    k++;
                }
            }
        }

        void give(NonTool *nt) {
            int x, y, quantity, i, j;
            bool flag = false;
            i = 0;
            while (i < maxrow && !flag) {
                j = 0;
                while (j < maxcol && !flag) {
                    if (this->item[i][j]->getname() == nt->getname() && !this->item[i][j]->isFull()) {
                        flag = true;
                        x = i;
                        y = j;
                    } else {
                        j++;
                    }
                }
                
                if (!flag) {
                    i++;
                }
            }
            
            if (flag) {
                quantity = this->item[x][y]->getquantity();
                this->item[x][y]->add(nt->getquantity());
                if (quantity + nt->getquantity() > nt->getmaxquantity()) {
                    nt->substract(nt->getmaxquantity() - quantity);
                } else {
                    nt->substract(nt->getquantity());
                }

            }
            while (nt->getquantity() > 0) {
                x = getEmptyRow();
                if (x != maxrow) {
                    y = getEmptyCol(x);
                    delete this->item[x][y];
                    this->item[x][y] = new NonTool(nt->getid(), nt->getname(), nt->gettype(), 0);
                    this->item[x][y]->add(nt->getquantity());
                    if (nt->getquantity() > nt->getmaxquantity()) {
                        nt->substract(nt->getmaxquantity());
                    } else {
                        nt->substract(nt->getquantity());
                    }
                }
            }
            delete nt;
        }

        void discard(int id, int count) {
            int k = 0;
            int i = 0;
            int j = 0;
            while (i < maxrow && k != id) {
                j = 0;
                while (j < maxcol && k != id) {
                    j++;
                    k++;
                }
                
                if (k != id) {
                    i++;
                }
            }

            if (this->item[i][j]->isEmpty()) {
                // throw error
            } else {
                if (this->item[i][j]->getquantity() >= count) {
                    this->item[i][j]->substract(count);
                    if (this->item[i][j]->isEmpty()) {
                        delete this->item[i][j];
                        this->item[i][j] = new NonTool();
                    }
                } else {
                    // throw error
                }
            }
        }

        void useTool(int slotID) // COMMAND 7
        {
            int k = 0;
            int i = 0;
            int j = 0;
            while (i < maxrow && k != slotID) {
                j = 0;
                while (j < maxcol && k != slotID) {
                    k++;
                }
                
                if (k != slotID) {
                    i++;
                }
            }

            // IF FOUND
            if (this->item[i][j]->isTool()) {
                Tool *t = (Tool *) this->item[i][j];
                t->use();
                if (t->isDestroyed()) {
                    delete this->item[i][j];
                    this->item[i][j] = new NonTool(); //NT or Item
                }
                


            }
            else {
                //throw exception not a tool
            }
            
        }

        void stackNonTool(int sID1, int sID2)  // COMMAND 5
        {
            bool flag1 = false;
            bool flag2 = false;
            int i = 0;
            int j = 0;
            int k = 0;
            int i1, j1, i2, j2;

            while (i < maxrow && (!flag1 || !flag2)) {
                j = 0;
                while (j < maxrow && (!flag1 || !flag2)) {
                    if (sID1 == k) {
                        flag1 = true;
                        i1 = i;
                        j1 = j;
                    }
                    if (sID2 == k) {
                        flag2 = true;
                        i2 = i;
                        j2 = j;
                    }
                    k++;
                }
            }

            if (item[i1][j1]->getid() == item[i2][j2]->getid()) {
                if (item[i1][i2]->isNonTool()) {
                    int q1 = item[i1][j1]->getquantity();
                    int q2 = item[i2][j2]->getquantity();
                    int moveq = max((64-q2), q1);
                    item[i1][j1]->substract(moveq);
                    item[i2][j2]->add(moveq);

                }
                else {
                    //exception not a nontool
                }

            }
            else {
                //exception tidak sama item
            }
        }

        void exportFile(string filename) {
            int ItemId, val;
            ofstream outfile(filename);
            for (int i = 0; i < maxrow; i++) {
                for (int j = 0; j < maxcol; j++) {
                    if (this->item[i][j]->isEmpty()){ //cek slot kosong
                        outfile << "0:0" << endl;
                    }
                    else {
                        ItemId = this->item[i][j]->getid();
                        if (this->item[i][j]->isTool()){
                            val = this->item[i][j]->getdurability();
                        }
                        else{
                            val = this->item[i][j]->getquantity();
                        }
                        outfile << ItemId << ":" << val << endl;
                    }
                }
            }
            outfile.close();
        }
};

#endif