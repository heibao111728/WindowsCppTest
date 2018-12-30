#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand((unsigned)time(NULL));
    for (int i = 1; i <= 100; i++)
    {
        cout << rand() % 1000 << endl;
    }
    return 0;
}
