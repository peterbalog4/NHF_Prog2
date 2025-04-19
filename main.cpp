#include <iostream>
#include "osszetevo.h"
#include "gtest_lite.h"
#include "memtrace.h"
#include "konyv.h"
#include "menu.h"
//#include "test.h"

#if defined(WIN32) || defined(_WIN32) || defined(WIN64) || defined(_WIN64)
//SetConsoleCP(1250);
//SetConsoleOutputCP(1250);
#endif

using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    Menu M;
    M.run();
    return 0;
}
