#ifndef OSSZETEVO_H_INCLUDED
#define OSSZETEVO_H_INCLUDED

#include <string>
#include "memtrace.h"
// Az összetevõ osztály objektumai alkotják majd az összetevõ listát.
class Osszetevo{

private:
    std::string nev;
    std::string mertekegyseg;
public:
    Osszetevo();
    Osszetevo(std::string nev,std::string db="db");
    std::string GetNev();
    std::string GetMertekegyseg();
    ~Osszetevo();

};

#endif // OSSZETEVO_H_INCLUDED
