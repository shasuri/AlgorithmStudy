#include <iostream>
#include <time.h>

using namespace std;

long long bin(int n, int k)
{
    if (k == 0 || n == k)
        return 1;
    else
        return bin(n - 1, k - 1) + bin(n - 1, k);
}

int main(int argc, char **argv)
{
    clock_t start, end;
    start = clock();
    cout << bin(45, 10);
    end = clock();

    cout << endl
         << (double)(end - start) << " ms" << endl;
    return 0;
}