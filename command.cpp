#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include "command.hpp"
using namespace std;

void Show(){
    cout << "SHOW" << endl;
    //Tampilin inventory + crafting
};

void Give(){
    string name;
    int qty;
    cin >> name;
    //cek nama benar ato nga
    cin >> qty;
    //cek qty bener ato g
    cout << "Give" << endl;
};

void Discard(){
    string InvID;
    int qty;
    cin >> InvID;
    cin >> qty;
    if (!CheckInvID(InvID)){
        cout << "Masukan salah" << endl;
        return;
    }
    cout << "Discard" << endl;
    //cek ada barang ato g
    //cek qty (harus samadengan lebih kecil curretn quantity)
};

void Move(){
    string src, dest;
    string destList[9];
    int N;
    cin >> src;
    cin >> N;
    if (!CheckInvID(src)){
        cout << "Masukan salah" << endl;
        return;
    }
    if (N > 9){
        cout << "Masukan salah" << endl;
        return;
    }
    for (int i=0;i<N;i++){
        cin >> dest;
        if (dest[0] != 'I' && dest[0] != 'C'){
            cout << "Masukan salah" << endl;
            return;
        }
        destList[i] = dest;
    }
    cout << "MOVE" << endl;
    //move stuff
};

void Use(){
    string InvID;
    cin >> InvID;
    if (!CheckInvID(InvID)){
        cout << "Masukan salah" << endl;
        return;
    }
    //periksa barang tool atau bukan
    cout << "Barang digunakan" << endl;
};

void Craft(){
    cout << "CRAFT" << endl;
    //lakukan craft
    //-periksa inventory cukup ato g
    //-masukkan item yang dicraft ke inventory
    //-hapus barang yang digunakan untuk craft
};

void Export(){
    string fileName;
    regex b("(.*)(.txt)");
    cin >> fileName;
    if (!regex_match(fileName,b)){
        cout << "Masukan salah" << endl;
        return;
    }
    ofstream outfile(fileName);
    for (int i=0;i<27;i++){
        //get itemID
        //get quantity
        outfile << "0:0" << endl;
    }
    outfile.close();
};

bool CheckInvID(string InvID){
    string ID;
    int index;
    ID = InvID.erase(0,1);
    index = stoi(ID);
    if (InvID[0] != 'I' && InvID[0] != 'C'){
        return false;
    }
    if (index < 0 || index > 26){
        return false;
    }
    return true;
};