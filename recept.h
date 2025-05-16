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
public:
    Recept();
    Recept(std::string knev, double* kmennyisegek, int ko_size, Osszetevo* kosszetevok,int kel_size, std::string* kleiras);
    Recept(const Recept& r);
    std::string GetNev() const;
    int GetOSize() const;
    int GetELSize() const;
    double GetMennyiseg(int idx) const;
    Osszetevo GetOsszetevo(int idx) const;
    std::string GetLeiras(int idx) const;
    void SetNev(std::string knev);
    void WriteRecept(std::ofstream& os);
    Recept ReadRecept(std::ifstream& is);
    void AddOsszetevo(Osszetevo o, double m);
    void RemoveOsszetevo(int idx);
    void ListOsszetevo();
    void AddLeiras(std::string leiras);
    void RemoveLeiras(int idx);
    void ListLeiras();
    Recept& operator=(const Recept& r);
    //int sajatstoi(std::string line);
    //double sajatstod(std::string line);
    ~Recept();

};

std::ostream& operator<<(std::ostream& os, const Recept& r);

#endif // RECEPT_H_INCLUDED
