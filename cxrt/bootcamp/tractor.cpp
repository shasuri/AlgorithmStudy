#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

#define MAXN 500
#define MAX_COST 1000001

int N;
int grids[MAXN][MAXN];
int halfOver;
bool visited[MAXN][MAXN];

// bool groupMap[MAXN * MAXN][MAXN * MAXN];

int minCost = MAX_COST;
int maxCost = 0;
int maxDiff;

int minTract = MAX_COST;

struct Tractor
{
    int h;
    int w;
    int initialD;
} groupStart[MAXN * MAXN];

void InputData()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> grids[i][j];
            minCost = min(minCost, grids[i][j]);
            maxCost = max(maxCost, grids[i][j]);
        }
    }

    halfOver = ((N * N) + 1) / 2;
    maxDiff = maxCost - minCost;
}

bool isTractable(Tractor t, int diff)
{
    return t.h > -1 && t.h < N &&
           t.w > -1 && t.w < N &&
           abs(grids[t.h][t.w] - t.initialD) <= diff;
}

void initVisited(void)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            visited[i][j] = false;
        }
    }
}

int dirH[] = {1, -1, 0, 0};
int dirW[] = {0, 0, 1, -1};

int groupCount = 0;

void recordGroup(void)
{
    initVisited();

    for (int h = 0; h < N; h++)
    {
        for (int w = 0; w < N; w++)
        {
            if (!visited[h][w])
            {
                queue<Tractor> tractQueue;
                tractQueue.push({h, w, grids[h][w]});
                groupStart[groupCount++] = {h, w, grids[h][w]};
                visited[h][w] = true;

                while (!tractQueue.empty())
                {
                    Tractor t = tractQueue.front();
                    tractQueue.pop();

                    for (int i = 0; i < 4; i++)
                    {
                        Tractor n = {t.h + dirH[i], t.w + dirW[i], t.initialD};
                        if (isTractable(n, 0))
                        {
                            if (!visited[n.h][n.w])
                            {
                                visited[n.h][n.w] = true;
                                tractQueue.push(n);
                            }
                        }
                    }
                }
            }
        }
    }
}

bool tractGrids(int diff)
{
    for (int i = 0; i < groupCount; i++)
    {
        initVisited();

        queue<Tractor> tractQueue;
        Tractor start = groupStart[i];
        tractQueue.push(start);
        visited[start.h][start.w] = true;

        int tractCount = 1;

        while (!tractQueue.empty())
        {
            Tractor t = tractQueue.front();
            tractQueue.pop();

            for (int i = 0; i < 4; i++)
            {
                Tractor n = {t.h + dirH[i], t.w + dirW[i], t.initialD};
                if (isTractable(n, diff))
                {
                    if (!visited[n.h][n.w])
                    {
                        visited[n.h][n.w] = true;
                        tractCount++;
                        if (tractCount >= halfOver)
                        {
                            return true;
                        }

                        tractQueue.push(n);
                    }
                }
            }
        }
    }

    return false;
}

int Solve(void)
{
    recordGroup();

    int low = 0;
    int high = maxDiff;
    int mid;

    while (low <= high)
    {
        mid = (high + low) / 2;

        if (tractGrids(mid))
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}

int main()
{
    int ans = -1;

    InputData(); // 입력받는 부분

    // 여기서부터 작성
    ans = Solve();
    cout << ans << endl; // 출력하는 부분
    return 0;
}
