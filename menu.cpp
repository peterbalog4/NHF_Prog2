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



    // A receptesk�nyv �s fel�p�t�se
    Konyv k;
    // A konkr�t men�

    std::cout << "Kokt�los K�nyv\n" << "1. �sszetev�k\n" << "2. �j recept\n" << "3. Receptek kezel�se\n" << "4. Keres�s\n" << "5. Kil�p�s\n" <<"V�laszt�s:";
    std::cin >> idx;
    if(idx < 1 || idx > 5){
        throw "Index hiba!";
    }
    switch(idx) {

        case 1:{
            std:: cout << "1. �j �sszetev� megad�sa \n" << "2. �sszetev� t�rl�se\n" << "3. �sszetev�k list�ja\n" << "V�laszt�s:";
            std::cin >> idx;
            if(idx < 1 || idx > 3){
            throw "Index hiba!";
            }
            switch(idx){

                case 1:{
                    Osszetevo o;
                    std::string nev,mertek;
                    std::cout << "Mi legyen az �sszetev� neve?";
                    std::cin >> nev;
                    o.SetNev(nev);
                    std::cout << "Mi legyen az �sszetev� m�rt�kegys�ge?";
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
            std:: cout << "1. Recept m�dos�t�sa \n" << "2. Recept t�rl�se\n" << "3. Receptek list�ja\n" << "V�laszt�s:";
            std::cin >> idx;
            break;
        }
        case 4:{
            std:: cout << "1. Keres�s n�v szerint \n" << "2. Nincs �tletem\n" << "V�laszt�s:";
            std::cin >> idx;
            break;
        }
        case 5:
            break;
    }
}
