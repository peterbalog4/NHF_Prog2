#ifndef KONYV_H_INCLUDED
#define KONYV_H_INCLUDED
#include "osszetevo.h"
#include "memtrace.h"
#include "recept.h"

// A könyv class tárolja a recepteket és összetevõket.
class Konyv{

private:
    Osszetevo* all_osszetevo;
    Recept* receptek;
    static int o_meret;
    static int o_capacity;
    static int r_meret;
    static int r_capacity;


public:

    Konyv();
    void AddOsszetevo(Osszetevo o);
    void RemoveOsszetevo(int idx);
    void ListOsszetevok();
    void AddRecept(Recept r);
    void RemoveRecept(int idx);
    void ListReceptek();
    int GetOMeret();
    int GetOCapacity();
    int GetRMeret();
    int GetRCapacity();
    Osszetevo GetOsszetevok(int idx);
    Recept GetReceptek(int idx);
    void save(std::ofstream& os1,std::ofstream& os2);
    void load(std::ifstream& is1,std::ifstream& is2);
    void recept_nevvel(std::string kulcsszo);
    void randomrecept();
    ~Konyv();
};

#endif // KONYV_H_INCLUDED
