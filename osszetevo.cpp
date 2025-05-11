#include "osszetevo.h"
#include <iostream>
#include <fstream>
#include "memtrace.h"
#include <string>
#include <cstring>
#include <sstream>
// Az Osszetevo class "alap" elemei NTS: Kész
// Konstruktorok
Osszetevo::Osszetevo() : nev("ures"),mertekegyseg("db"){}
Osszetevo::Osszetevo(std::string nev,std::string db) : nev(nev),mertekegyseg(db){}

// Getter függvények
std::string Osszetevo::GetNev() const{
    return nev;
}
std::string Osszetevo::GetMertekegyseg() const{
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
    if (!is.is_open()) {
        throw std::runtime_error("Nem sikerült megnyitni a fájlt:");
    }

    std::string line;
    if (std::getline(is, line)) {
        std::istringstream iss(line);
        std::string nev, mertekegyseg;

        std::getline(iss, nev, '|');
        std::getline(iss, mertekegyseg, '\n');

        return Osszetevo(nev, mertekegyseg);
    }

    throw std::runtime_error("Üres fájl vagy hibás formátum.");
}

//Operátor túlterhelések

std::ostream& operator<<(std::ostream& os, Osszetevo const& o) {
    os << o.GetNev() << "|" << o.GetMertekegyseg() << std::endl;
    return os;
}


bool Osszetevo::operator==(Osszetevo o){
    if(nev == o.nev && mertekegyseg == o.mertekegyseg){
        return true;
    }
    return false;
}
Osszetevo Osszetevo::operator=(Osszetevo o){
    if(*this == o){
        return *this;
    }
    nev = o.nev;
    mertekegyseg = o.mertekegyseg;
    return *this;
}

//Destruktor
Osszetevo::~Osszetevo(){

}
