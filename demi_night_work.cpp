#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(int t, int u)
{
    return t > u;
}

long long solution(int n, vector<int> works)
{
    long long answer = 0;

    int worksSize = works.size();

    sort(works.begin(), works.end(), cmp);

    for (auto i : works)
    {
        cout << i << endl;
    }

    return answer;
}
