#include <iostream>
using namespace std;
#define MAXN (10)
int N;                       // 빌딩개수(장소개수)
int A[MAXN + 10][MAXN + 10]; //[빌딩][장소]=비용

int minCost = 1000;

void InputData()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> A[i][j];
        }
    }
}

bool isUsed(int groundIndex, int usedGround)
{
    return usedGround & (1 << groundIndex);
}

int useGround(int groundToUse, int usedGround)
{
    return usedGround + (1 << groundToUse);
}

void dfs(int building, int usedGround, int cost)
{
    if (cost > minCost)
    {
        return;
    }

    if (building >= N)
    {
        if (cost < minCost)
        {
            minCost = cost;
        }

        return;
    }
    for (int groundIndex = 0; groundIndex < N; groundIndex++)
    {
        if (isUsed(groundIndex, usedGround))
        {
            continue;
        }
        dfs(building + 1, useGround(groundIndex, usedGround), cost + A[building][groundIndex]);
    }

    return;
}

int Solve(void)
{
    dfs(0, 0, 0);

    return minCost;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int ans = -1;
    InputData(); // 입력

    // 여기서부터 작성
    ans = Solve();
    cout << ans << "\n"; // 출력
    return 0;
}