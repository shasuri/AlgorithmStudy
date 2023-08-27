
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
#define MAX_COLOR 1000000007

/*
 * Complete the 'solution' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY cost
 *  2. INTEGER x
 */
int getReduced(long long color)
{
    return color % MAX_COLOR;
}

int dnc(int d)
{
    long long result = 1;
    long long c = 2;
    cout << "d\tc\tresult" << endl;
    while (d > 0)
    {
        cout << d << "\t" << c << "\t" << result << endl;
        if (d & 1)
        {
            result *= c;
            result = getReduced(result);
        }
        c *= c;
        c = getReduced(c);
        d >>= 1;
    }
    return (int)result;
}

int main(void)
{
    cout << dnc(457) << endl;
}