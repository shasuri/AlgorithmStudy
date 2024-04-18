#include <string>
#include <vector>
#include <iostream>

using namespace std;

const char BASE_NUM = '0';
const char BASE_ALP = 'A';

string solution(int n, int t, int m, int p);
string makeBaseString(int n, int len);
string intToNString(int i, int n);
char toAlpNum(int i);
string getTubeString(string &base, int cycle, int members, int seq);

string solution(int n, int t, int m, int p)
{

    p--;
    string base = makeBaseString(n, (t - 1) * m + p);

    string tube = getTubeString(base, t, m, p);

    return tube;
}

string makeBaseString(int n, int len)
{

    string base;

    int i = 0;

    while (base.length() <= len)
    {
        base.append(intToNString(i, n));
        i++;
    }

    // cout << '\n' << base << '\n';

    return base;
}

string intToNString(int i, int n)
{
    string nStr;
    do
    {
        nStr.insert(nStr.begin(), toAlpNum(i % n));
        i /= n;
    } while (i >= 1);

    // cout << nStr << " + ";
    return nStr;
}

char toAlpNum(int i)
{
    if (i >= 10)
    {
        return static_cast<char>(BASE_ALP + i - 10);
    }
    else
    {
        return static_cast<char>(BASE_NUM + i);
    }
}

string getTubeString(string &base, int cycle, int members, int seq)
{
    string tube;

    for (int i = 0; i < cycle; i++)
    {
        tube.push_back(base[members * i + seq]);
    }
    // cout << tube << '\n';
    return tube;
}
