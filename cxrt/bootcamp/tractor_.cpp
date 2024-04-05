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

bool isTractable(Tractor t)
{
    return t.h > -1 && t.h < N &&
           t.w > -1 && t.w < N;
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

bool tractGrids(int diff)
{
    initVisited();
    // for (int i = 0; i < groupCount; i++)
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!visited[i][j])
            {

                queue<Tractor> tractQueue;
                // Tractor start = groupStart[i];
                Tractor start = {i, j, grids[i][j]};
                tractQueue.push(start);
                visited[start.h][start.w] = true;

                int tractCount = 1;
                while (!tractQueue.empty())
                {
                    Tractor t = tractQueue.front();
                    tractQueue.pop();

                    for (int i = 0; i < 4; i++)
                    {
                        Tractor n = {t.h + dirH[i], t.w + dirW[i], 0};
                        if (isTractable(n))
                        {
                            n.initialD = grids[n.h][n.w];
                            if (abs(n.initialD - t.initialD) <= diff)
                            {
                                if (!visited[n.h][n.w])
                                {
                                    visited[n.h][n.w] = true;
                                    // cout << n.h << " , " << n.w << endl;
                                    tractCount++;
                                    if (tractCount >= halfOver)
                                    {
                                        // cout << tractCount << halfOver << endl;
                                        return true;
                                    }

                                    tractQueue.push(n);
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return false;
}

int Solve(void)
{
    // recordGroup();

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
