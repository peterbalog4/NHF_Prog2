#include <iostream>
#include "osszetevo.h"
#include "gtest_lite.h"
#include "memtrace.h"
#include "konyv.h"
#include "menu.h"
#ifndef WIN_32
#include <windows.h>
#endif








void Menu::run(){



    // A recepteskönyv és felépítése
    Konyv k;
    bool ready = true;
    char* str;
    // A konkrét menü
    while(ready){
        std::cout << "Koktélos Könyv\n" << "1. Összetevõk\n" << "2. Új recept\n" << "3. Receptek kezelése\n" << "4. Keresés\n" << "Választás:";
        std::cin >> idx;
        if(idx < 1 || idx > 4){
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
                        std::cout << "Next?";
                        std::cin >> str;
                        ready = backtomainmenu(str);
                        break;
                    }
                    case 2:
                        break;
                    case 3:
                        k.ListOsszetevo();
                        std::cout << "Next?";
                        std::cin >> str;
                        ready = backtomainmenu(str);
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
        }
    }
}

// Ellenőrzi a readyt.
bool Menu::backtomainmenu(char* str){
    for(int i=0;i<strlen(str);i++){
        str[i] = tolower(str[i]);
    }
    if(str == "igen"){
        return true;
    }
    return false;
}
