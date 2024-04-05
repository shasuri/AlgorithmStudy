#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int N;              // 히스토그램수

struct Pil
{
    int ind;
    long long h;
    int popped = 0;
} histogram[100000];

stack<Pil> hStk;

bool InputData()
{
    cin >> N;
    if (N == 0)
        return false;

    for (int i = 0; i < N; i++)
    {
        histogram[i].ind = i;
        cin >> histogram[i].h;
    }
    return true;
}

long long Solve(void)
{
    long long maxArea = 0;
    long long h;
    long long minH = 1000000001;

    for (int i = 0; i < N; i++)
    {
        Pil pil = histogram[i];
        h = pil.h;

        minH = min(h, minH);

        if (hStk.empty())
        {
            hStk.push(pil);
            maxArea = max(maxArea, h);
            continue;
        }

        while (!hStk.empty() && hStk.top().h > h)
        {
            maxArea = max(maxArea, hStk.top().h * (i - hStk.top().ind));
            pil.ind = hStk.top().ind;
            // pil.popped++;
            hStk.pop();
        }

        // maxArea = max(maxArea, (pil.popped + 1) * h);
        hStk.push(pil);
    }

    // int popCount = 0;
    while (!hStk.empty())
    {
        maxArea = max(maxArea, hStk.top().h * (N - hStk.top().ind));
        hStk.pop();
    }

    maxArea = max(maxArea, minH * N);

    return maxArea;
}

int main()
{
    long long ans = -1;
    while (InputData())
    { // 입력받는 부분

        ans = Solve();

        cout << ans << "\n"; // 출력하는 부분
    }
    return 0;
}