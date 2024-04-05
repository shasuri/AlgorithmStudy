#include <iostream>
#include <queue>
using namespace std;
#define MAXN (100)
int N, M;                  // 지하철역수, 목적역
int S[MAXN + 2][MAXN + 2]; //[s][e]=시간

#define INF (1 << 30)
int visited[MAXN + 2];
int path[MAXN + 2];
queue<int> que;

int BFS()
{
    for (int i = 1; i <= N; i++)
    {
        visited[i] = INF;
        path[i] = 0;
    }
    que = {};
    que.push(1);
    visited[1] = 0;
    path[1] = 0;
    while (!que.empty())
    {
        int cur = que.front();
        que.pop();
        for (int e = 2; e <= N; e++)
        {
            int ntime = visited[cur] + S[cur][e];
            if (visited[e] <= ntime)
                continue;
            que.push(e);
            visited[e] = ntime;
            path[e] = cur;
        }
    }
    return visited[M];
}

void PRT(int m)
{
    if (m == 0)
        return;
    PRT(path[m]);
    cout << m << " ";
}
void OutputData(int ans)
{
    cout << ans << "\n";
    PRT(M);
    cout << "\n";
}

void InputData()
{
    cin >> N >> M;
    for (int s = 1; s <= N; s++)
    {
        for (int e = 1; e <= N; e++)
        {
            cin >> S[s][e];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    InputData();
    int ans = BFS();
    OutputData(ans);
    return 0;
}

/**************************************************************
    Problem: 1174
    Language: C++
    Result: Accepted
    Time:2 ms
    Memory:2288 kb
****************************************************************/