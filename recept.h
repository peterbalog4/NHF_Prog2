#ifndef RECEPT_H_INCLUDED
#define RECEPT_H_INCLUDED
#include "osszetevo.h"
#include <string>
#include "memtrace.h"
class Recept{

private:
    std::string nev;
    double* mennyisegek;
    Osszetevo* osszetevok;
    std::string* leiras;
    int o_size;
    int el_size;
    int m_size;
public:
    Recept();
    Recept(std::string knev,int km_size=0;double* kmennyisegek= NULL, int ko_size=0, Osszetevo* kosszetevok = NULL,int kel_size=0; std::string* kleiras = NULL);
    std::string GetNev();
    void SetNev(std::string knev);
    void WriteRecept(std::ofstream& os);
    Recept ReadRecept(std::ifstream& is);
    void AddOsszetevo(Osszetevo o);
    void RemoveOsszetevo(int idx);
    void ListOsszetevo();
    void AddLeiras(std::string leiras);
    void RemoveLeiras(int idx);
    void ListLeiras();
    ~Recept();

};

#endif // RECEPT_H_INCLUDED
