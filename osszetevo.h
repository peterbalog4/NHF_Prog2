#ifndef OSSZETEVO_H_INCLUDED
#define OSSZETEVO_H_INCLUDED

#include <string>
#include "memtrace.h"
// Az összetevõ osztály objektumai alkotják majd az összetevõ listát. NTS: Kész
class Osszetevo{

private:
    std::string nev;
    std::string mertekegyseg;
public:
    Osszetevo();
    Osszetevo(std::string nev,std::string db="db");
    std::string GetNev() const;
    std::string GetMertekegyseg() const;
    void SetNev(std::string knev);
    void SetMertekegyseg(std::string kmertek);
    void WriteOsszetevo(std::ofstream& os);
    Osszetevo ReadOsszetevo(std::ifstream& is);
    Osszetevo operator=(Osszetevo o);
    bool operator==(Osszetevo o);
    ~Osszetevo();

};

std::ostream& operator<<(std::ostream& os, const Osszetevo& o);
#endif // OSSZETEVO_H_INCLUDED
