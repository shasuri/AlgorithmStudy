#include <iostream>
using namespace std;
#define MAXN (12)
int N;                       // 대회수
int A[MAXN + 10][MAXN + 10]; //[출발][도착]=항공료

int minCost = 1200;

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

bool isUnvisitable(int src, int dst)
{
    return A[src][dst] == 0;
}

bool isVisited(int dst, int visited)
{
    return visited & (1 << dst);
}

int visitHere(int dst, int visited)
{
    return visited + (1 << dst);
}

bool isAllVisited(int visited)
{
    return visited == ((1 << N) - 1);
}

int getCostToHome(int src)
{
    return A[src][0];
}

void dfs(int src, int cost, int visited)
{
    if (cost > minCost)
    {
        return;
    }

    if (isAllVisited(visited))
    {
        if (isUnvisitable(src, 0)) // Cannot get back home.
        {
            return;
        }

        int allCost = cost + getCostToHome(src); // Include cost to get back home.
        if (minCost > allCost)
        {
            minCost = allCost;
        }
        return;
    }

    for (int dst = 1; dst < N; dst++)
    {
        if (isUnvisitable(src, dst) || isVisited(dst, visited))
        {
            continue;
        }

        dfs(dst, cost + A[src][dst], visitHere(dst, visited));
    }

    return;
}

int Solve(void)
{
    dfs(0, 0, 1); // Home is already visited.

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