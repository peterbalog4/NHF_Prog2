#ifndef OSSZETEVO_H_INCLUDED
#define OSSZETEVO_H_INCLUDED

#include <string>
#include "memtrace.h"
// Az �sszetev� oszt�ly objektumai alkotj�k majd az �sszetev� list�t.
class Osszetevo{

private:
    std::string nev;
    std::string mertekegyseg;
public:
    Osszetevo();
    Osszetevo(std::string nev,std::string db="db");
    std::string GetNev();
    std::string GetMertekegyseg();
    void SetNev(std::string knev);
    void SetMertekegyseg(std::string kmertek);
    void WriteOsszetevo(std::ofstream& os);
    Osszetevo ReadOsszetevo(std::ifstream& is);
    ~Osszetevo();

};

#endif // OSSZETEVO_H_INCLUDED
