#include "logger.h"
#include <stdio.h>

int main()
{
    LOG("hello\n");
    LOG("%s", "hello ---------\n");
    int a = 3;

    LOG("a = %d\n", a);
}