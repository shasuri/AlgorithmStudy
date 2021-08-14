#include <string>
#include <vector>
using namespace std;

vector<int> getPi(string p)
{
    int m = (int)p.size(), j = 0;
    vector<int> pi(m, 0);
    for (int i = 1; i < m; i++)
    {
        while (j > 0 && p[i] != p[j])
            j = pi[j - 1];
        if (p[i] == p[j])
            pi[i] = ++j;
    }
    return pi;
}

// 출처: https://bowbowbow.tistory.com/6 [멍멍멍]