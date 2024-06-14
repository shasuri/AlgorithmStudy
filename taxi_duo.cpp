#include <string>
#include <vector>

using namespace std;

const int MAXN = 200;

int way[MAXN][MAXN];

int sway[MAXN];
int away[MAXN];
int bway[MAXN];

int nodes;

int solution(int n, int s, int a, int b, vector<vector<int>> fares)
{
    int answer = 0;
    int src, dst, cost;
    nodes = n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                way[i][j] = 0;
            }
            else
            {
                way[i][j] = -1;
            }
        }
    }

    for (auto fare : fares)
    {
        src = fare[0];
        dst = fare[1];
        cost = fare[2];
        way[src - 1][dst - 1] = cost;
        way[dst - 1][src - 1] = cost;
    }

    for (int i = 0; i < n; i++)
    {
        sway[i] = way[s - 1][i];
        away[i] = way[a - 1][i];
        bway[i] = way[b - 1][i];
    }

    dfs(s - 1);
    return answer;
}

void dfs(int start)
{
    for (int i = 0; i < nodes; i++)
    {
        if (way[start][i] == -1)
        {
            continue;
        }
        
        if (sway[i] > sway[start] + way[start][i])
        {
            sway[i] = sway[start] + way[start][i];
            dfs(i);
        }
    }
}