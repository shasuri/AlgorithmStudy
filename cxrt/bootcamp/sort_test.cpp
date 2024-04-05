#include <iostream>
#include <algorithm>
using namespace std;
int main(void)
{
    int h[] = {4, 10, 1, 9};

    sort(&h[0], &h[4]);

    for (int i = 0; i < 4; i++)
    {
        cout << h[i] << '\n';
    }
}