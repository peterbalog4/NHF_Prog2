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
    int o_meret;
    int o_capacity;
    int r_meret;
    int r_capacity;


public:

    Konyv();
    void AddOsszetevo(Osszetevo o);
    void RemoveOsszetevo(int idx);
    void ListOsszetevok();
    void AddRecept(Recept r);
    void RemoveRecept(int idx);
    void ListReceptek();
    int GetOMeret() const;
    int GetOCapacity() const;
    int GetRMeret() const;
    int GetRCapacity() const;
    Osszetevo GetOsszetevok(int idx);
    Recept GetReceptek(int idx);
    void save(std::ofstream& os1,std::ofstream& os2);
    void load(std::ifstream& is1,std::ifstream& is2);
    void recept_nevvel(std::string kulcsszo);
    void randomrecept();
    ~Konyv();
};

#endif // KONYV_H_INCLUDED
