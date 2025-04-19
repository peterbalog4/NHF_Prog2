#include "osszetevo.h"
#include <iostream>
#include <fstream>
#include "memtrace.h"
#include <string>
#include <cstring>
// Az Osszetevo class "alap" elemei

// Konstruktorok
Osszetevo::Osszetevo() : nev("ures"),mertekegyseg("db"){}
Osszetevo::Osszetevo(std::string nev,std::string db) : nev(nev),mertekegyseg(db){}

// Getter függvények
std::string Osszetevo::GetNev(){
    return nev;
}
std::string Osszetevo::GetMertekegyseg(){
    return mertekegyseg;
}

//Setter függvények

void Osszetevo::SetNev(std::string knev){
    nev = knev;
}

void Osszetevo::SetMertekegyseg(std::string kmertek){
    mertekegyseg = kmertek;
}


//RW függvények
void Osszetevo::WriteOsszetevo(std::ofstream& os){

    os << nev << "|" << mertekegyseg << std::endl;
}

Osszetevo Osszetevo::ReadOsszetevo(std::ifstream& is){

    Osszetevo o;
    //is >> o.nev >> "|" >> o.mertekegyseg >> std::endl;
    //if(o.nev == NULL){
    //    return nullptr;
    //}
    return o;
}


//Destruktor
Osszetevo::~Osszetevo(){

}
