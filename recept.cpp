#include "recept.h"
#include "osszetevo.h"
#include <fstream>
#include <sstream>
#include <iostream>

//Konstruktorok
Recept::Recept(): nev("ures"), mennyisegek(NULL),osszetevok(NULL),leiras(NULL){}

Recept::Recept(std::string knev, double* kmennyisegek, int ko_size, Osszetevo* kosszetevok, int kel_size, std::string* kleiras) : nev(knev), o_size(ko_size), el_size(kel_size)
{
    mennyisegek = new double[o_size];
    for (int i = 0; i < o_size; ++i)
        mennyisegek[i] = kmennyisegek[i];

    osszetevok = new Osszetevo[o_size];
    for (int i = 0; i < o_size; ++i)
        osszetevok[i] = kosszetevok[i];

    leiras = new std::string[el_size];
    for (int i = 0; i < el_size; ++i)
        leiras[i] = kleiras[i];
}

Recept::Recept(const Recept& r) {
        nev = r.nev;
        o_size = r.o_size;
        el_size = r.el_size;

        mennyisegek = new double[o_size];
        for (int i = 0; i < o_size; i++)
            mennyisegek[i] = r.mennyisegek[i];

        osszetevok = new Osszetevo[o_size];
        for (int i = 0; i < o_size; i++)
            osszetevok[i] = r.osszetevok[i];

        leiras = new std::string[el_size];
        for (int i = 0; i < el_size; i++)
            leiras[i] = r.leiras[i];
    }

// Getterek

std::string Recept::GetNev() const{
    return nev;
}
int Recept::GetOSize() const{
    return o_size;
}
int Recept::GetELSize() const{
    return el_size;
}
double Recept::GetMennyiseg(int idx) const{
    return mennyisegek[idx];
}
std::string Recept::GetLeiras(int idx) const{
    return leiras[idx];
}
Osszetevo Recept::GetOsszetevo(int idx) const{
    return osszetevok[idx];
}

//Setterek

void Recept::SetNev(std::string knev){
    nev = knev;
}

// RW fgvk

void Recept::WriteRecept(std::ofstream& os){
    os << nev << "|" << o_size << "|"<< el_size << "|";
    for(int i=0; i<o_size; i++){
        os << osszetevok[i].GetNev() << ";" << osszetevok[i].GetMertekegyseg();
        os<< ",";
    }
    os << "|";
    for(int i=0; i<o_size; i++){
        os << mennyisegek[i];
        os<< ",";
    }
    os << "|";
    for(int i=0; i<el_size; i++){
        os << leiras[i];
        os<< ",";
    }
    os << std::endl;
}

Recept Recept::ReadRecept(std::ifstream& is){
    if (!is.is_open()) {
        throw std::runtime_error("Nem sikerült megnyitni a fájlt:");
    }

    std::string line;
    if (std::getline(is, line)) {

        std::istringstream iss(line);

        std::string o_size_str, el_size_str;

        std::getline(iss, nev, '|');
        std::getline(iss, o_size_str, '|');
        std::getline(iss, el_size_str, '|');

        o_size = std::stoi(o_size_str);
        el_size = std::stoi(el_size_str);

        mennyisegek = new double[o_size];
        osszetevok = new Osszetevo[o_size];
        leiras = new std::string[el_size];

        std::string line2;
        std::string line3;
        std::string line4;
        std::getline(iss, line2, '|');
        std::getline(iss, line3, '|');
        std::getline(iss, line4, '|');

        std::istringstream iss2(line2);
        std::istringstream iss3(line3);
        std::istringstream iss4(line4);

        for(int i=0; i<o_size;i++){
            std::string o;
            std::getline(iss2, o, ',');
            std::istringstream iss_o(o);
            std::string nev, mertekegyseg;
            std::getline(iss_o,nev,';');
            std::getline(iss_o,mertekegyseg);

            osszetevok[i].SetNev(nev);
            osszetevok[i].SetMertekegyseg(mertekegyseg);
        }

        for(int i=0; i<o_size;i++){
            std::string value;
            std::getline(iss3, value, ',');
            mennyisegek[i] = std::stod(value);
        }

        for (int i = 0; i < el_size; i++) {
            std::getline(iss4, leiras[i], ',');
        }
        return *this;
    }

    throw std::runtime_error("Üres fájl vagy hibás formátum.");
}

//Összetevő kezelő fgvk

void Recept::AddOsszetevo(Osszetevo o, double m){

    Osszetevo* uj_osszetevok = new Osszetevo[o_size + 1];
    double* uj_mennyisegek = new double[o_size + 1];

    for(int i = 0; i < o_size; i++){
        uj_osszetevok[i] = osszetevok[i];
        uj_mennyisegek[i] = mennyisegek[i];
    }

    uj_osszetevok[o_size] = o;
    uj_mennyisegek[o_size] = m;

    delete[] osszetevok;
    delete[] mennyisegek;

    osszetevok = uj_osszetevok;
    mennyisegek = uj_mennyisegek;

    o_size++;
}
void Recept::RemoveOsszetevo(int idx){
    if(o_size <= 1){
        std::cout << "Az utolsó összetevőt nem lehet törölni!";
        return;
    }
    idx--;
    if(idx < 0 || idx >= o_size){
        throw "Hibás index!";
    }

    Osszetevo* uj_osszetevok = new Osszetevo[o_size - 1];
    double* uj_mennyisegek = new double[o_size - 1];

    for(int i = 0; i < idx; i++){
        uj_osszetevok[i] = osszetevok[i];
        uj_mennyisegek[i] = mennyisegek[i];
    }

    for(int i = idx + 1; i < o_size; i++){
        uj_osszetevok[i - 1] = osszetevok[i];
        uj_mennyisegek[i - 1] = mennyisegek[i];
    }

    delete[] osszetevok;
    delete[] mennyisegek;
    osszetevok = uj_osszetevok;
    mennyisegek = uj_mennyisegek;

    o_size--;
}
void Recept::ListOsszetevo(){
    for(int i = 0; i < o_size; i++){
        std::cout << osszetevok[i];

    }
}

//Leírás kezelő fgvk

void Recept::AddLeiras(std::string uj_leiras){
    if(el_size <= 1){
        std::cout << "Az utolsó leirást nem lehet törölni!";
        return;
    }
    std::string* uj_leirasok = new std::string[el_size + 1];

    for(int i = 0; i < el_size; i++){
        uj_leirasok[i] = leiras[i];
    }

    uj_leirasok[el_size] = uj_leiras;

    delete[] leiras;
    leiras = uj_leirasok;

    el_size++;
}
void Recept::RemoveLeiras(int idx){
    idx--;
    if(idx < 0 || idx >= el_size){
        throw "Hibás index!";
    }

    std::string* uj_leirasok = new std::string[el_size - 1];

    for(int i = 0; i < idx; i++){
        uj_leirasok[i] = leiras[i];
    }

    for(int i = idx + 1; i < el_size; i++){
        uj_leirasok[i - 1] = leiras[i];
    }

    delete[] leiras;
    leiras = uj_leirasok;

    el_size--;
}

void Recept::ListLeiras(){
    std::cout << "Elkészítési lépések:" << std::endl;
    for(int i = 0; i < el_size; i++){
        std::cout << i + 1 << ". " << leiras[i] << std::endl;
    }
}

//Operátorok

std::ostream& operator<<(std::ostream& os, const Recept& r){
    os << r.GetNev()<< std::endl;
    os << "_____________________________" << std::endl;
    for(int i=0;i<r.GetOSize();i++){
        os << i+1 << ". összetevő: ";
        os << r.GetOsszetevo(i).GetNev() << r.GetMennyiseg(i) << r.GetOsszetevo(i).GetMertekegyseg() << std::endl;
    }
    os << "_____________________________"<< std::endl;
    for(int i=0;i<r.GetELSize();i++){
        os << i+1 << ". lépés: ";
        os << r.GetLeiras(i) << std::endl;
    }
    return os;
}

Recept& Recept::operator=(const Recept& r) {
    if (this == &r) {
        return *this;
    }

    delete[] mennyisegek;
    delete[] osszetevok;
    delete[] leiras;

    nev = r.nev;
    o_size = r.o_size;
    el_size = r.el_size;

    mennyisegek = new double[o_size];
    for (int i = 0; i < o_size; ++i) {
        mennyisegek[i] = r.mennyisegek[i];
    }

    osszetevok = new Osszetevo[o_size];
    for (int i = 0; i < o_size; ++i) {
        osszetevok[i] = r.osszetevok[i];
    }

    leiras = new std::string[el_size];
    for (int i = 0; i < el_size; ++i) {
        leiras[i] = r.leiras[i];
    }

    return *this;
}
//Destruktor

Recept::~Recept(){
    delete [] osszetevok;
    delete [] leiras;
    delete [] mennyisegek;
}
