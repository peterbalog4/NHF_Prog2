#include "konyv.h"
#include <iostream>
#include "memtrace.h"
#include <cstring>

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

Konyv::Konyv(){}


//Kéne ide egy fasza bõvítõs template
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

Konyv::Konyv(std::istream is){}

Konyv::~Konyv(){}


