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
    std::ifstream is1,is2;
    is1.open("osszetevok.txt");
    is2.open("receptek.txt");
    k.load(is1,is2);
    is1.close();
    is2.close();
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
                std:: cout << "1. Új összetevõ megadása \n" << "2. Összetevõ törlése\n" << "3. Összetevõk listája\n" << "4. Vissza\n" << "Választás:";
                std::cin >> idx;
                if(idx < 1 || idx > 4){
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
                case 4:{
                    van_e =true;
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
                    std::getline(std::cin >> std::ws, line);
                    leiras[i] = line;
                }
                Recept r(nev, mennyisegek, o_size, osszetevok, el_size, leiras);
                k.AddRecept(r);
                delete[] leiras;
                delete[] mennyisegek;
                delete[] osszetevok;
                break;
            }
            case 3:{
                std:: cout << "1. Recept módosítása \n" << "2. Recept törlése\n" << "3. Receptek listája\n" << "4. Vissza\n" << "Választás:";
                std::cin >> idx;
                if(idx < 1 || idx > 4){
                    throw "Index hiba!";
                }
                switch(idx){
                    case 1:{
                        std::cout << "Melyik receptet módosítsuk?" << std::endl;
                        k.ListReceptek();
                        int idx;
                        std::cin >> idx;
                        std::cout << "Mit módosítsunk? \n 1. Név\n 2. Összetevők\n 3. Leírás \n" << std::endl;
                        int idx2;
                        std::cin >> idx2;
                        if(idx2 < 1 || idx2 > 3){
                            throw "index hiba!";
                        }
                        switch(idx2){
                            case 1:{
                                std::cout << "Mi legyen az új név?" << std::endl;
                                std::string line;
                                std::getline(std::cin,line);
                                k.GetReceptek(idx).SetNev(line);
                                break;
                            }
                            case 2:{
                                std::cout << "Hozzáadjunk(1) vagy Töröljünk(2) összetevőt?" << std::endl;
                                int idx3;
                                std::cin >> idx3;
                                if(idx3 < 1 || idx3 > 2){
                                    throw "Index hiba!";
                                }
                                if(idx3 == 1){
                                    std::cout << "Hány darabot adjunk hozzá?"<< std::endl;
                                    int valasz;
                                    std::cin >> valasz;
                                    for(int i=0;i<valasz;i++){
                                        k.ListOsszetevok();
                                        std::cout << "Melyik összetevőt adjunk hozzá?"<< std::endl;
                                        int valasz2;
                                        std::cin >> valasz2;
                                        if(valasz2 > k.GetOMeret() || valasz2 < 1){
                                            throw "Index hiba!";
                                        }
                                        std::cout << "És mennyit?"<< std::endl;
                                        double m;
                                        std::cin >> m;
                                        k.GetReceptek(idx).AddOsszetevo(k.GetOsszetevok(valasz2),m);
                                    }
                                }
                                if(idx3 == 2){
                                    if(k.GetReceptek(idx).GetOSize() <= 1){
                                        std::cout << "Az utolsó összetevőt nem lehet törölni!";
                                        return;
                                    }
                                    std::cout << "Hány darabot töröljünk?" << std::endl;
                                    int valasz;
                                    std::cin >> valasz;
                                    for(int i=0;i<valasz;i++){
                                        k.GetReceptek(idx).ListOsszetevo();
                                        std::cout << "Melyiket töröljük?" <<std::endl;
                                        int valasz2;
                                        std::cin >> valasz2;
                                        k.GetReceptek(idx).RemoveOsszetevo(valasz2);
                                    }
                                }
                                break;
                            }
                            case 3:{
                                std::cout << "Hozzáadjunk(1) vagy Töröljünk(2) leírást?";
                                int idx3;
                                std::cin >> idx3;
                                if(idx3 < 1 || idx3 > 2){
                                    throw "Index hiba!";
                                }
                                if(idx3 == 1){
                                    std::cout << "Hány darabot adjunk hozzá?"<< std::endl;
                                    int valasz;
                                    std::cin >> valasz;
                                    for(int i=0;i<valasz;i++){
                                        std::string leiras;
                                        std::getline(std::cin,leiras);
                                        k.GetReceptek(idx).AddLeiras(leiras);
                                    }
                                }
                                if(idx3 == 2){
                                    if(k.GetReceptek(idx).GetELSize() <= 1){
                                        std::cout << "Az utolsó leírást nem lehet törölni!";
                                        return;
                                    }
                                    std::cout << "Hány darabot töröljünk?" << std::endl;
                                    int valasz;
                                    std::cin >> valasz;
                                    for(int i=0;i<valasz;i++){
                                        k.GetReceptek(idx).ListLeiras();
                                        std::cout << "Melyiket töröljük?" <<std::endl;
                                        int valasz2;
                                        std::cin >> valasz2;
                                        k.GetReceptek(idx).RemoveLeiras(valasz2);
                                    }
                                }
                                break;
                                }
                        }
                    }
                    case 2:{
                        if(k.GetOMeret() <= 1){
                            std::cout << "Az utolsó receptet nem lehet törölni!";
                            return;
                        }
                        k.ListReceptek();
                        std::cout << "Melyik receptet távolítsuk el?";
                        int idx;
                        std::cin >> idx;
                        k.RemoveRecept(idx);
                    }
                    case 3:{
                        k.ListReceptek();
                    }
                    case 4:{
                    van_e =true;
                    break;
                    }
                }
                break;
            }
            case 4:{
                std:: cout << "1. Keresés név szerint \n" << "2. Nincs ötletem\n" << "3. Vissza\n" << "Választás:";
                std::cin >> idx;
                if(idx < 1 || idx > 3){
                    throw "Index hiba!";
                }
                switch(idx){
                    case 1:{
                        std::cout << "Mi a keresett recept neve?" << std::endl;
                        std::string line;
                        std::cin.ignore();
                        std::getline(std::cin,line);
                        k.recept_nevvel(line);
                        break;
                    }
                    case 2:{
                        k.randomrecept();
                        break;
                    }
                    case 3:{
                        van_e = true;
                        break;
                    }
                }
                break;
            }
            case 5:
                std::ofstream os1, os2;
                os1.open("osszetevok.txt");
                os2.open("receptek.txt");
                k.save(os1,os2);
                os1.close();
                os2.close();
                van_e = false;
                break;
        }
    }
}
