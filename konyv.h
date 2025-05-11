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


public:

    Konyv();
    void AddOsszetevo(Osszetevo o);
    void RemoveOsszetevo(int idx);
    void ListOsszetevok();
    void AddRecept(Recept r);
    void RemoveRecept(int idx);
    void ListReceptek();
    Konyv(std::istream is);
    int GetOMeret();
    int GetOCapacity();
    void save(std::ofstream& os);
    void load(std::ifstream& is);
    ~Konyv();
};

#endif // KONYV_H_INCLUDED
