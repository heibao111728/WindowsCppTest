#include <iostream>
#include "MyWinThread.h"


using namespace std;

int main()
{
    int i = 0;
    CMyWinTthread testThread;
    testThread.start();
    testThread.join();

    printf("in main thread !\n");

    return 0;
}