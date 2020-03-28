#include <iostream>
#include <windows.h>

#include "ThreadContainer.h"

int main()
{
    thread_container container;

    container.start();
    Sleep(20 * 1000);
    container.stop();

    getchar();
    return 0;
}