#include "recept.h"



    /*std::string nev;
    double* mennyisegek;
    Osszetevo* osszetevok;
    std::string* leiras;*/

//Konstruktorok
Recept::Recept(): nev("ures"), mennyisegek(NULL),osszetevok(NULL),leiras(NULL){}

Recept(std::string knev,int m_size=0;double* kmennyisegek= NULL, int o_size=0, Osszetevo* kosszetevok = NULL,int el_size=0; std::string* kleiras = NULL);: nev(knev),mennyisegek(kmennyisegek),osszetevok(koszzetevok),leiras(kleiras), O_size(ko_size),m_size(km_size),el_size(kel_size){}

// Getterek

std::string GetNev(){
    return nev;
}

//Setterek

void SetNev(std::string knev){
    nev = knev;
}

// RW fgvk

void WriteRecept(std::ofstream& os){

}

Recept ReadRecept(std::ifstream& is){

}

//Összetevő kezelő fgvk

void AddOsszetevo(Osszetevo o){

}
void RemoveOsszetevo(int idx){

}
void ListOsszetevo(){

}

//Leírás kezelő fgvk

void AddLeiras(std::string leiras);
void RemoveLeiras(int idx);
void ListLeiras();

//Destruktor

~Recept();

// A receptek egyelõre WIP. Elõbb a könyvet és a fájlbaírást akarom megcsinálni.
