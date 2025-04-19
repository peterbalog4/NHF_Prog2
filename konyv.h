#ifndef KONYV_H_INCLUDED
#define KONYV_H_INCLUDED
#include "osszetevo.h"
#include "memtrace.h"

// A k�nyv class t�rolja a recepteket �s �sszetev�ket.
class Konyv{

private:
    Osszetevo* all_osszetevo;
    static int o_meret;
    static int o_capacity;


public:

    Konyv();
    void AddOsszetevo(Osszetevo o);
    void RemoveOsszetevo(int idx);
    void ListOsszetevo();
    Konyv(std::istream is);
    int GetOMeret();
    ~Konyv();
};

#endif // KONYV_H_INCLUDED
