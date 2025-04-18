#include "osszetevo.h"
#include <iostream>

#include <string>
// Az Osszetevo class "alap" elemei

Osszetevo::Osszetevo() : nev("ures"),mertekegyseg("db"){}
Osszetevo::Osszetevo(std::string nev,std::string db) : nev(nev),mertekegyseg(db){}
std::string Osszetevo::GetNev(){
    return nev;
}
std::string Osszetevo::GetMertekegyseg(){
    return mertekegyseg;
}

Osszetevo::~Osszetevo(){

}
