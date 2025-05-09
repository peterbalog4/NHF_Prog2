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
    // A konkrét menü

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
                case 2:
                    break;
                case 3:
                    break;
                }
                break;
            }
        case 2:{
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
            break;
    }
}
