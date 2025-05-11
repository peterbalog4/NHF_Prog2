#ifndef KONYV_H_INCLUDED
#define KONYV_H_INCLUDED
#include "osszetevo.h"
#include "memtrace.h"
#include "recept.h"

// A k�nyv class t�rolja a recepteket �s �sszetev�ket.
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
    void save(std::ofstream& os);
    void load(std::ifstream& is);
    ~Konyv();
};

#endif // KONYV_H_INCLUDED
