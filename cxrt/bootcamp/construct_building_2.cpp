#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN (10)
#define INF 1000

int N;
int cost[MAXN + 10][MAXN + 10];
int solpath[MAXN + 10]; // 답 경로

void InputData()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> cost[i][j];
        }
    }
}
void OutputData(int sol)
{
    cout << sol << endl;
    for (int i = 0; i < N; i++)
    {
        cout << solpath[i] << " ";
    }
    cout << endl;
}

int constructHere(int status, int here)
{
    return status | (1 << here);
}

bool isConstructed(int status, int where)
{
    return status & (1 << where);
}

int minCost = INF;
int dfs(int depth, int constructStatus, int curCost)
{
    if (depth >= N)
    {
        if (curCost < minCost)
        {
            minCost = curCost;
            return true;
        }
        return false;
    }

    int tmpIndex = -1;
    bool updated = false;
    for (int i = 0; i < N; i++)
    {
        if (!isConstructed(constructStatus, i))
        {
            if (dfs(depth + 1,
                    constructHere(constructStatus,
                                  i),
                    curCost + cost[depth][i]))
            {
                solpath[depth] = i + 1;
                updated = true;
            }
        }
    }

    return updated;
    
}

int Solve(void)
{
    int curCost, tmpIndex;
    for (int i = 0; i < N; i++)
    {
        if(dfs(1, constructHere(0, i), cost[0][i])){
            tmpIndex = i;
        };
    }
    solpath[0] = tmpIndex + 1;
    return minCost;
}

int main()
{
    int ans = -1;

    InputData(); // 입력받는 부분

    // 여기서부터 작성
    ans = Solve();

    OutputData(ans); // 출력하는 부분
    return 0;
}