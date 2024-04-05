#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

#define MAXN 100
#define MAXL 1000001

int N, M;

int pathMap[MAXN + 1][MAXN + 1];
int visited[MAXN + 1];
int originalPath[MAXN + 1];

const int HOME = 1;
int BARN;

struct Block
{
    int id;
    int walked;
};

queue<Block> roadBlock;

void InputData()
{
    cin >> N >> M;

    int block1, block2, len;

    for (int i = 0; i < M; i++)
    {
        cin >> block1 >> block2 >> len;

        pathMap[block1][block2] = len;
        pathMap[block2][block1] = len;
    }
    BARN = N;
}

bool isWalkable(Block b, int dst)
{
    int src = b.id;

    return dst != HOME &&
           src != dst &&
           pathMap[src][dst] != 0 &&
           visited[dst] > b.walked + pathMap[src][dst];
}

void walkToFarm(bool recordPath)
{
    roadBlock.push({1, 0});

    Block b;

    while (!roadBlock.empty())
    {
        b = roadBlock.front();
        roadBlock.pop();

        for (int dst = 1; dst <= N; dst++)
        {
            if (isWalkable(b, dst))
            {
                visited[dst] = b.walked + pathMap[b.id][dst];
                roadBlock.push({dst, visited[dst]});
                if (recordPath)
                {
                    originalPath[dst] = b.id;
                }
                // cout << dst << " : " << visited[dst] << endl;
            }
        }
    }
}

void initVisited(void)
{
    for (int i = 0; i <= MAXN; i++)
    {
        visited[i] = MAXL * MAXN;
    }
}

int Solve(void)
{
    walkToFarm(true);

    int dst = BARN;
    int src = originalPath[dst];

    int originalBarnWalk = visited[BARN];
    int maxDiff = 0;

    while (dst != 1)
    {
        initVisited();

        int originalLen = pathMap[src][dst];

        pathMap[src][dst] *= 2;
        pathMap[dst][src] *= 2;

        walkToFarm(false);
        maxDiff = max(maxDiff, visited[BARN] - originalBarnWalk);

        pathMap[src][dst] = originalLen;
        pathMap[dst][src] = originalLen;

        dst = src;
        src = originalPath[dst];
    }

    return maxDiff;
}

int main()
{
    int ans = -1;

    initVisited();

    InputData(); // 입력받는 부분
    // 여기서부터 작성
    ans = Solve();

    cout << ans << endl; // 출력하는 부분
    return 0;
}