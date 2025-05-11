#include <iostream>
#include "osszetevo.h"
#include "gtest_lite.h"
#include "memtrace.h"
#include "konyv.h"
#include "menu.h"
#if defined(WIN32) || defined(_WIN32) || defined(WIN64) || defined(_WIN64)
#include <windows.h>
#endif








void Menu::run(){



    // A recepteskönyv és felépítése
    Konyv k;
    std::ifstream is;
    is.open("osszetevok.txt");
    k.load(is);
    is.close();
    bool van_e = true;
    // A konkrét menü
    while(van_e){
        std::cout << "Koktélos Könyv\n" << "1. Összetevõk\n" << "2. Új recept\n" << "3. Receptek kezelése\n" << "4. Keresés\n" << "5. Kilépés\n" <<"Választás:";
        std::cin >> idx;
        if(idx < 1 || idx > 5){
            throw "Index hiba!";
        }
        switch(idx) {

            case 1:{
                std:: cout << "1. Új összetevõ megadása \n" << "2. Összetevõ törlése\n" << "3. Összetevõk listája\n" << "Választás:";
                std::cin >> idx;
                if(idx < 1 || idx > 3){
                    throw "Index hiba!";
                }
            switch(idx){

                case 1:{
                    Osszetevo o;
                    std::string nev,mertek;
                    std::cout << "Mi legyen az összetevõ neve?";
                    std::cin >> nev;
                    o.SetNev(nev);
                    std::cout << "Mi legyen az összetevõ mértékegysége?";
                    std::cin >> mertek;
                    o.SetMertekegyseg(mertek);
                    k.AddOsszetevo(o);
                    break;
                }
                case 2:{
                    int idx;
                    k.ListOsszetevok();
                    std::cout << "Melyik összetevőt szeretnéd törölni?" << std::endl;
                    std::cin >> idx;
                    k.RemoveOsszetevo(idx);
                    break;
                }
                case 3:{
                    k.ListOsszetevok();
                    break;
                }
            }
            break;
            }

            case 2:{
                std::cout << "Mi legyen a recept neve?" << std::endl;
                std::string nev;
                std::getline(std::cin >> std::ws, nev);

                std::cout << "Hány darab összetevőt szeretnél?" << std::endl;
                int o_size;
                std::cin >> o_size;
                if(o_size <= 0){
                    throw "hibás index!";
                }
                Osszetevo* osszetevok;
                double* mennyisegek;
                osszetevok = new Osszetevo[o_size];
                mennyisegek = new double[o_size];

                for(int i=0;i<o_size;i++){
                    k.ListOsszetevok();
                    std::cout << "Milyen összetevő kerüljön bele?" << std::endl;
                    int idx2;
                    std::cin >> idx2;
                    osszetevok[i] = k.GetOsszetevok(idx2);
                    std::cout << "Mennyi kerüljön bele?" << std::endl;
                    double m;
                    std::cin >> m;
                    mennyisegek[i] = m;
                }
                std::cout << "Hány lépésből álljon a leírás?" << std::endl;
                int el_size;
                std::cin >> el_size;
                if(el_size <= 0){
                    throw "hibás index!";
                }
                std::string* leiras = new std::string[el_size];
                for(int i=0;i<el_size;i++){
                    std::cout << "Mi legyen a leírás " << i+1 << ". lépése?" << std::endl;
                    std::string line;
                    //fflush(stdin);
                    std::getline(std::cin >> std::ws, line);
                    leiras[i] = line;
                }
                Recept r(nev,mennyisegek,o_size,osszetevok,el_size,leiras);
                delete[] leiras;
                delete[] mennyisegek;
                delete[] osszetevok;
                k.AddRecept(r);
                break;
            }
            case 3:{
                std:: cout << "1. Recept módosítása \n" << "2. Recept törlése\n" << "3. Receptek listája\n" << "Választás:";
                std::cin >> idx;
                break;
            }
            case 4:{
                std:: cout << "1. Keresés név szerint \n" << "2. Nincs ötletem\n" << "Választás:";
                std::cin >> idx;
                break;
            }
            case 5:
                std::ofstream os;
                os.open("osszetevok.txt");
                k.save(os);
                os.close();
                van_e = false;
        }
    }
}
