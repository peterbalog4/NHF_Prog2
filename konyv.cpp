#include "konyv.h"
#include "osszetevo.h"
#include "recept.h"
#include <iostream>
#include "memtrace.h"
#include <cstring>
#include <windows.h>
#include <fstream>
#include <random>

//static init
int Konyv::o_meret = 0;
int Konyv::o_capacity = 10;
int Konyv::r_meret = 0;
int Konyv::r_capacity = 10;

// Bővítő template
template <typename T>

T* Array(T* oldarray, int oldmeret){
    if (oldarray == nullptr) {
        return new T[oldmeret + 10];
    }
    T* newarray = new T[oldmeret+10];
    for(int i=0;i<oldmeret;i++){
        newarray[i] = oldarray[i];
    }
    delete[] oldarray;
    return newarray;
};

//Könyv class fgvk

//Konstruktor
Konyv::Konyv(){
    all_osszetevo = new Osszetevo[o_capacity];
    receptek = new Recept[r_capacity];
}

//Összetevő kezelő fgvk
void Konyv::AddOsszetevo(Osszetevo o){
    if(o_capacity <= o_meret){
        all_osszetevo = Array(all_osszetevo,o_capacity);
        o_capacity += 10;
    }
    all_osszetevo[o_meret++] = o;
}

void Konyv::RemoveOsszetevo(int idx){
    if(o_meret <= 1){
        std::cout << "Az utolsó receptet nem lehet törölni!";
        return;
    }
    idx--;
    if(idx >= o_meret || idx < 0) {
        throw "Hibás index!";
    }
    for(int i = idx; i < o_meret - 1; i++) {
        all_osszetevo[i] = all_osszetevo[i + 1];
    }
    o_meret--;
}

void Konyv::ListOsszetevok(){
    for(int i=0;i<o_meret;i++){
        std::cout << i+1 <<"." << all_osszetevo[i] << std::endl;
    }
}

//Könyv save-load függvények

void Konyv::save(std::ofstream& os1,std::ofstream& os2){
    os1 << o_meret << std::endl;
    for(int i=0;i<o_meret;i++){
        all_osszetevo[i].WriteOsszetevo(os1);
    }

    os2 << r_meret << std::endl;
    for(int i=0;i<r_meret;i++){
        receptek[i].WriteRecept(os2);
    }

}
void Konyv::load(std::ifstream& is1,std::ifstream& is2){
    is1 >> o_meret;
    is1.ignore();
    o_capacity = o_meret + 10-o_meret%10;
    delete[] all_osszetevo;
    all_osszetevo = new Osszetevo[o_capacity];
    for(int i=0;i<o_meret;i++){
        all_osszetevo[i].ReadOsszetevo(is1);
    }

    is2 >> r_meret;
    is2.ignore();
    r_capacity = r_meret + 10-r_meret%10;
    delete[] receptek;
    receptek = new Recept[r_capacity];
    for(int i=0;i<r_meret;i++){
        receptek[i].ReadRecept(is2);
    }
}

//Recept kezelő függvények
void Konyv::AddRecept(Recept r){
    if(r_capacity <= r_meret){
        receptek = Array(receptek,r_capacity);
        r_capacity += 10;
    }
    receptek[r_meret++] = r;
}
void Konyv::RemoveRecept(int idx) {
    if(r_meret <= 1){
        std::cout << "Az utolsó receptet nem lehet törölni!";
        return;
    }
    idx--;
    if(idx >= r_meret || idx < 0) {
        throw "Hibás index!";
    }
    for(int i = idx; i < r_meret - 1; i++) {
        receptek[i] = receptek[i + 1];
    }
    r_meret--;
}
void Konyv::ListReceptek(){
    for(int i=0;i<r_meret;i++){
        std::cout << i+1 << "." << receptek[i] << std::endl;
    }

}

//Getterek
int Konyv::GetOMeret() const{
    return o_meret;
}
int Konyv::GetOCapacity() const{
    return o_capacity;
}
int Konyv::GetRMeret() const{
    return r_meret;
}
int Konyv::GetRCapacity() const{
    return r_capacity;
}
Osszetevo Konyv::GetOsszetevok(int idx){
    return all_osszetevo[idx];
}
Recept Konyv::GetReceptek(int idx){
    return receptek[idx];
}


// Random generátor | A random generátor nem az én munkám, teljes egészében az internetről szereztem. Kérem ne értékeljék, de szükséges a randomrecept működéséhez.

int randomInRange(int min, int max) {
    // Create a random device for seeding
    std::random_device rd;

    // Initialize a Mersenne Twister random number generator
    std::mt19937 gen(rd());

    // Define distribution (inclusive range from min to max)
    std::uniform_int_distribution<int> distribution(min, max);

    // Generate and return random number
    return distribution(gen);
}



// Kereső fgvk.

void Konyv::recept_nevvel(std::string kulcsszo){

    int count;
    for(int i=0;i<r_meret;i++){
        if(receptek[i].GetNev() == kulcsszo){
            std::cout << receptek[i] << std::endl;
            count++;
        }
    }
    if(count < 1){
        std::cout << "Nincs ilyen recept!";
    }
}

void Konyv::randomrecept(){

std::cout << receptek[randomInRange(0,r_meret-1)];

}

//Destruktor
Konyv::~Konyv(){
    delete[] all_osszetevo;
    delete[] receptek;

}


