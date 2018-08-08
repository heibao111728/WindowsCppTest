#include <iostream>
#include "MyWinThread.h"


using namespace std;

int main()
{
    int i = 0;
    CMyWinTthread testThread1("thread1");
    CMyWinTthread testThread2("thread2");

    testThread1.setValue(1);
    testThread2.setValue(2);

    testThread1.start();
    testThread2.start();

    Sleep(1 * 1000);
    testThread1.SetThreadName("thread1");
    testThread2.SetThreadName("thread2");

    testThread1.join();
    testThread2.join();

    printf("in main thread !\n");

    return 0;
}