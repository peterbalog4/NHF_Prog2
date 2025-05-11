#include "konyv.h"
#include "osszetevo.h"
#include <iostream>
#include "memtrace.h"
#include <cstring>
#include <windows.h>
#include <fstream>

//static init
int Konyv::o_meret = 0;
int Konyv::o_capacity = 0;

// Bővítő template
template <typename T>

T* Array(T* oldarray, int oldmeret){
    T* newarray = new T[oldmeret+10];
    for(int i=0;i<oldmeret;i++){
        newarray[i] = oldarray[i];
    }
    delete[] oldarray;
    return newarray;
};

//Könyv class fgvk

//Konstruktor
Konyv::Konyv(){}

//Összetevő kezelő fgvk
void Konyv::AddOsszetevo(Osszetevo o){
    if(o_capacity <= o_meret){
        all_osszetevo = Array(all_osszetevo,o_capacity);
        o_capacity += 10;
    }
    all_osszetevo[o_meret++] = o;
}

void Konyv::RemoveOsszetevo(int idx){
    idx--;
    if(idx > o_meret){
        throw "Hibás index!";
    }
    for(int i=0;i<o_meret;i++){
        if(i < idx){
            continue;
        }
        if(i > idx){
            all_osszetevo[i-1] = all_osszetevo[i];
        }
    }
}

void Konyv::ListOsszetevok(){
    for(int i=0;i<o_meret;i++){
        std::cout << all_osszetevo[i];
    }
}

//Könyv save-load függvények

void Konyv::save(std::ofstream& os){
    os << o_meret << std::endl;
    for(int i=0;i<o_meret;i++){
        all_osszetevo[i].WriteOsszetevo(os);
    }

}
void Konyv::load(std::ifstream& is){
    is >> o_meret;
    is.ignore();
    o_capacity = o_meret + 10-o_meret%10;
    all_osszetevo = new Osszetevo[o_capacity];
    for(int i=0;i<o_meret;i++){
        all_osszetevo[i].ReadOsszetevo(is);
    }
}
//Destruktor
Konyv::~Konyv(){
    delete[] all_osszetevo;

}


