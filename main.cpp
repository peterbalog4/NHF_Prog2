#include <iostream>
#include "osszetevo.h"
#include "gtest_lite.h"
#include "memtrace.h"
#include "konyv.h"
#include "menu.h"
#include <windows.h>
//#include "test.h"
using namespace std;

int main()
{
    setlocale(LC_ALL,"");
    #if defined(WIN32) || defined(_WIN32) || defined(WIN64) || defined(_WIN64)
    SetConsoleCP(1250);
    SetConsoleOutputCP(1250);
    #endif
    Menu M;
    M.run();
    return 0;
}
