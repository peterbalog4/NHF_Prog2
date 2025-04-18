#ifndef KONYV_H_INCLUDED
#define KONYV_H_INCLUDED
#include "osszetevo.h"

class Konyv{

private:
    Osszetevo* all_osszetevo;



public:

    Konyv();
    AddOsszetevo(Osszetevo o);
    RemoveOsszetevo(int idx);
    Konyv(Osszetevo* o_lista);
    ~Konyv();
};

#endif // KONYV_H_INCLUDED
