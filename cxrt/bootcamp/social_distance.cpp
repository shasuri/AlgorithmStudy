#include <iostream>
#include <algorithm>

using namespace std;

#define MAXNM ((int)1e5)
#define MAXGRASS ((long long)1e18)
int N, M; // 소마리수, 잔디구간 개수

struct Grass
{
    long long start;
    long long end;

    bool operator<(Grass g)
    {
        return start < g.start;
    }
} area[MAXNM + 1];

long long maxGrass = 0;
long long minGrass = MAXGRASS;

void InputData()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> area[i].start >> area[i].end;
        minGrass = min(minGrass, area[i].start);
        maxGrass = max(maxGrass, area[i].end);
    }
}

long long getMid(long long t, long long u)
{
    return (t + u) / 2;
}

bool isSettable(long long dist)
{
    long long lastLoc = minGrass; // start

    int g = 0;
    // cout << dist << " : ";

    for (int i = 0; i < N - 1; i++)
    {
        // cout << lastLoc << " ";
        while (g < M && lastLoc + dist > area[g].end) // over
        {
            g++;
        }

        if (g >= M)
        {
            return false;
        }

        if (lastLoc + dist >= area[g].start &&
            lastLoc + dist <= area[g].end) // in
        {
            lastLoc += dist;
        }
        else if (lastLoc + dist < area[g].start) // not enough
        {
            lastLoc = area[g].start;
        }

    }
    // cout << endl;

    return true;
}

long long Solve(void)
{
    if (N == 2)
    {
        return maxGrass - minGrass;
    }

    sort(area, area + M);

    long long low = 1;
    long long high = (maxGrass - minGrass) / (N - 1);
    long long mid;

    while (low <= high)
    {
        mid = getMid(low, high);

        if (isSettable(mid))
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return high; 
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long ans = -1;
    InputData(); // 입력받는 부분

    // 여기서부터 작성
    ans = Solve();

    cout << ans << "\n"; // 출력하는 부분
    return 0;
}