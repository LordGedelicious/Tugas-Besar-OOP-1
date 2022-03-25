#include "Item.hpp"
#include "NonTool.hpp"
#include "Tool.hpp"
#include "Exception/BaseException.hpp"
#include <math.h>
#include <fstream>

#ifndef _TABLE_HPP_
#define _TABLE_HPP_

template <int maxrow, int maxcol>
class Table {
    private:
        Item*** item;
    public:
        // Table constructor
        Table() {
            this->item = new Item**[maxrow];
            for (int i = 0; i < maxrow; i++) {
                this->item[i] = new Item*[maxcol];
                for (int j = 0; j < maxcol; j++) {
                    this->item[i][j] = new NonTool();
                }
            }
        }

        // Table destructor
        ~Table() {
            delete[] item;
        }

        // Mengembalikan index dari kolom tabel yang kosong
        int getEmptyCol(int row) {
            int j = 0;
            while (j < maxcol && !this->item[row][j]->isEmpty()) {
                j++;
            }
            return j;
        }

        // Mengembalikan index dari baris tabel yang kosong
        int getEmptyRow() {
            int i = 0;
            while (i < maxrow && this->getEmptyCol(i) == maxcol) {
                i++;
            }
            return i;
        }

        // Mengembalikan pointer Item pada baris ke-i dan kolom ke-j
        Item* getItem(int i, int j) {
            return this->item[i][j];
        }

        // Mengubah value pointer Item pada baris ke-i dan kolom ke-j
        void setItem(Item *item, int i, int j) {
            this->item[i][j] = item;
        }

        // Menghapus seluruh isi tabel
        void clearAll() {
            for (int i = 0; i < maxrow; i++) {
                for (int j = 0; j < maxcol; j++) {
                    if (!this->item[i][j]->isEmpty()) {
                        delete this->item[i][j];
                        this->item[i][j] = new NonTool();
                    }
                }
            }
        }

        /*Implementasi Command SHOW
        Berfungsi menampilkan tabel */
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

        /* Implementasi Command GIVE
        Menambahkan NonTool ke tabel */
        void give(NonTool *nt) {
            int x, y, quantity, i, j;
            bool flag = false;
            i = 0;
            while (i < maxrow && !flag) {
                j = 0;
                while (j < maxcol && !flag) {
                    if (this->item[i][j]->getid() == nt->getid() && !this->item[i][j]->isFull()) {
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
                } else {
                    throw new InventoryFullException();
                }
            }
            delete nt;
        }

        /* Implementasi Command CRAFT
        Menambahkan Tool ke tabel setelah crafting */
        void give(Tool *t) {
            int x = getEmptyRow();
            if (x != maxrow) {
                int y = getEmptyCol(x);
                delete this->item[x][y];
                this->item[x][y] = new Tool(t->getid(), t->getname(), t->gettype(), t->getdurability());
                delete t;
            } else {
                throw new InventoryFullException();
            }
        }

        /* Implementasi Command DISCARD
        Menghapus NonTool sejumlah count pada id yang dipilih */
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
                } else {
                    if (j == maxcol) {
                        j = 0;
                        i++;
                    }
                }
            }

            if (this->item[i][j]->isEmpty()) {
                throw new DiscardInvalidException(k);
            } else {
                if (this->item[i][j]->getquantity() >= count) {
                    this->item[i][j]->substract(count);
                    if (this->item[i][j]->isEmpty()) {
                        delete this->item[i][j];
                        this->item[i][j] = new NonTool();
                    }
                } else {
                    throw new DiscardInvalidException(k);
                }
            }
        }

        /* Implementasi Command MOVE
        Berfungsi memindahkan pointer item dari tabel inventory ke tabel craft */
        void moveToCraft(int ID1, int ID2, Table<3, 3> *craft) {
            int idx1 = 0;
            int i = 0;
            int j = 0;
            while (i < maxrow && idx1 != ID1) {
                j = 0;
                while (j < maxcol && idx1 != ID1) {
                    j++;
                    idx1++;
                }
                
                if (idx1 != ID1) {
                    i++;
                } else {
                    if (j == maxcol) {
                        j = 0;
                        i++;
                    }
                }
            }

            int idx2 = 0;
            int k = 0;
            int l = 0;
            while (k < 3 && idx2 != ID2) {
                l = 0;
                while (l < 3 && idx2 != ID2) {
                    l++;
                    idx2++;
                }
                
                if (idx2 != ID2) {
                    k++;
                } else {
                    if (l == 3) {
                        l = 0;
                        k++;
                    }
                }
            }

            if (!this->item[i][j]->isEmpty()) {
                if (craft->getItem(k,l)->isEmpty()) {
                    delete craft->getItem(k,l);
                    if (this->item[i][j]->isNonTool()) {
                        this->item[i][j]->substract(1);
                        NonTool *nt = new NonTool(this->item[i][j]->getid(), this->item[i][j]->getname(), this->item[i][j]->gettype(), 1);                        
                        craft->setItem(nt, k, l);
                        if (this->item[i][j]->isEmpty()) {
                            delete this->item[i][j];
                            this->item[i][j] = new NonTool();
                        }
                    } else {
                        Tool *t = new Tool(this->item[i][j]->getid(), this->item[i][j]->getname(), this->item[i][j]->gettype(), this->item[i][j]->getdurability());
                        craft->setItem(t, k, l);
                        delete this->item[i][j];
                        this->item[i][j] = new NonTool();
                    }
                } else {
                    throw new NotEmptySlotException('C', idx2);
                }
            } else {
                throw new EmptySlotException('I', idx1);
            }
        }

        /* Implementasi Command MOVE
        Berfungsi menggabungkan dua NonTool yang sama */
        void stackNonTool(int sID1, int sID2)
        {
            int i1,i2,j1,j2;
            i1 = sID1/9;
            j1 = sID1%9;
            i2 = sID2/9;
            j2 = sID2%9;

            if (!item[i2][j2]->isEmpty()) {
                if (item[i1][j1]->getid() == item[i2][j2]->getid()) {
                    if (item[i1][j1]->isNonTool()) {
                        int q1 = item[i1][j1]->getquantity();
                        int q2 = item[i2][j2]->getquantity();
                        int moveq = min((64-q2), q1);
                        item[i1][j1]->substract(moveq);
                        item[i2][j2]->add(moveq);
                    }
                    else {
                        throw new NotNonToolException(item[i1][j1]);
                    }
                }
                else {
                    throw new ItemInvalidException(item[i1][j1], item[i2][j2]);
                }
            } else {
                if (item[i1][j1]->isNonTool()) {
                    item[i2][j2] = new NonTool(item[i1][j1]->getid(), item[i1][j1]->getname(), item[i1][j1]->gettype(), item[i1][j1]->getquantity());
                    delete item[i1][j1];
                } else {
                    throw new NotNonToolException(item[i1][j1]);
                }
            }
        }

        /* Implementasi Command MOVE
        Berfungsi memindahkan pointer item dari tabel craft ke tabel inventory */
        void moveToInventory(int ID1, int ID2, Table<3, 9> *inventory) {
            int idx1 = 0;
            int i = 0;
            int j = 0;
            while (i < maxrow && idx1 != ID1) {
                j = 0;
                while (j < maxcol && idx1 != ID1) {
                    j++;
                    idx1++;
                }
                
                if (idx1 != ID1) {
                    i++;
                } else {
                    if (j == maxcol) {
                        j = 0;
                        i++;
                    }
                }
            }

            int idx2 = 0;
            int k = 0;
            int l = 0;
            while (k < 3 && idx2 != ID2) {
                l = 0;
                while (l < 9 && idx2 != ID2) {
                    l++;
                    idx2++;
                }
                
                if (idx2 != ID2) {
                    k++;
                } else {
                    if (l == 9) {
                        l = 0;
                        k++;
                    }
                }
            }

            if (!this->item[i][j]->isEmpty()) {
                if (this->item[i][j]->isNonTool()) {
                    if (inventory->getItem(k,l)->isEmpty()) {
                        this->item[i][j]->substract(1);
                        NonTool *nt = new NonTool(this->item[i][j]->getid(), this->item[i][j]->getname(), this->item[i][j]->gettype(), 1);
                        delete inventory->getItem(k,l);
                        inventory->setItem(nt, k, l);
                    } else {
                        if (inventory->getItem(k,l)->isFull()) {
                            throw new NotEmptySlotException('C',idx2);
                        } else {
                            if (inventory->getItem(k,l)->getid() == this->item[i][j]->getid()) {
                                this->item[i][j]->substract(1);
                                inventory->getItem(k,l)->add(1);
                            } else {
                                throw new ItemInvalidException(getItem(k,l), item[i][j]);
                            }
                        }
                    }

                    if (this->item[i][j]->isEmpty()) {
                        delete this->item[i][j];
                        this->item[i][j] = new NonTool();
                    }
                } else {
                    if (inventory->getItem(k,l)->isEmpty()) {
                        Tool *t = new Tool(this->item[i][j]->getid(), this->item[i][j]->getname(), this->item[i][j]->gettype(), this->item[i][j]->getdurability());
                        delete inventory->getItem(k,l);
                        inventory->setItem(t, k, l);
                        delete this->item[i][j];
                        this->item[i][j] = new NonTool();
                    } else {
                        throw new EmptySlotException('C',getItem(k,l)->getid());
                    }
                }
            } else {
                throw new EmptySlotException('I', idx1);
            }
        }

        /* Implementasi Command USE
        Berfungsi menggunakan Tool */
        void useTool(int slotID) // COMMAND 7
        {
            int k = 0;
            int i = 0;
            int j = 0;
            while (i < maxrow && k != slotID) {
                j = 0;
                while (j < maxcol && k != slotID) {
                    j++;
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
                throw new NotToolException(item[i][j]);
            }
        }

        /* Implementasi Command Export
        Berfungsi melakukan export dari inventory ke dalam file */
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