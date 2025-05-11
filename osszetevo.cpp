#include "osszetevo.h"
#include <iostream>
#include <fstream>
#include "memtrace.h"
#include <string>
#include <cstring>
#include <sstream>
// Az Osszetevo class "alap" elemei NTS: K�sz
// Konstruktorok
Osszetevo::Osszetevo() : nev("ures"),mertekegyseg("db"){}
Osszetevo::Osszetevo(std::string nev,std::string db) : nev(nev),mertekegyseg(db){}

// Getter f�ggv�nyek
std::string Osszetevo::GetNev() const{
    return nev;
}
std::string Osszetevo::GetMertekegyseg() const{
    return mertekegyseg;
}

//Setter f�ggv�nyek

void Osszetevo::SetNev(std::string knev){
    nev = knev;
}

void Osszetevo::SetMertekegyseg(std::string kmertek){
    mertekegyseg = kmertek;
}


//RW f�ggv�nyek
void Osszetevo::WriteOsszetevo(std::ofstream& os){

    os << nev << "|" << mertekegyseg << std::endl;

}

Osszetevo Osszetevo::ReadOsszetevo(std::ifstream& is){
    if (!is.is_open()) {
        throw std::runtime_error("Nem siker�lt megnyitni a f�jlt:");
    }

    std::string line;
    if (std::getline(is, line)) {
        std::istringstream iss(line);
        std::string nev, mertekegyseg;

        std::getline(iss, nev, '|');
        std::getline(iss, mertekegyseg, '\n');

        return Osszetevo(nev, mertekegyseg);
    }

    throw std::runtime_error("�res f�jl vagy hib�s form�tum.");
}

//Oper�tor t�lterhel�sek

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
