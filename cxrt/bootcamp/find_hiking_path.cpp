#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

#define MAXN (102)
#define INF 2500001
#define DIR 4

int N;      // 산크기
int eh, ew; // 목적지 위치 세로, 가로

int map[MAXN][MAXN];
int minCosts[MAXN][MAXN];

struct Point
{
    int h;
    int w;
    int height = 0;
    int cost = 0;

    Point() {}
    Point(int h_, int w_) : h(h_), w(w_)
    {
        height = map[h_][w_];
    }
};

queue<Point> path;

void InputData()
{
    cin >> N;
    cin >> eh >> ew;
    for (int h = 1; h <= N; h++)
    {
        for (int w = 1; w <= N; w++)
        {
            cin >> map[h][w];
        }
    }
}

void initMinCosts(void)
{
    for (int i = 0; i <= N + 1; i++)
    {
        for (int j = 0; j <= N + 1; j++)
        {
            minCosts[i][j] = INF;
        }
    }
}

void visitThisPoint(Point p)
{
    minCosts[p.h][p.w] = p.cost;
}

int dirH[] = {1, -1, 0, 0};
int dirW[] = {0, 0, 1, -1};

bool isInMountain(Point p)
{
    return p.h > -1 && p.h < N + 2 &&
           p.w > -1 && p.w < N + 2;
}

int getMovingCost(Point cur, Point next)
{
    if (cur.height == next.height)
    {
        return 0;
    }

    if (cur.height > next.height)
    {
        return cur.height - next.height;
    }

    if (cur.height < next.height)
    {
        return pow(next.height - cur.height, 2);
    }
}

int getPointMinCost(Point p)
{
    return minCosts[p.h][p.w];
}

bool isEndPoint(Point p)
{
    return p.h == eh && p.w == ew;
}

void Solve(void)
{
    initMinCosts();

    Point start = {0, 0};
    path.push(start);
    visitThisPoint(start);

    Point cur;

    while (!path.empty())
    {
        cur = path.front();
        path.pop();

        for (int i = 0; i < DIR; i++)
        {
            Point next = {cur.h + dirH[i], cur.w + dirW[i]};
            if (!isInMountain(next))
            {
                continue;
            }

            next.cost = cur.cost + getMovingCost(cur, next);

            if (next.cost < getPointMinCost(next))
            {
                visitThisPoint(next);
                if (isEndPoint(next))
                {
                    continue;
                }
                path.push(next);
            }
        }
    }
}

int main()
{
    int ans = -1;
    InputData(); // 입력 받는 부분

    // 여기서부터 작성
    Solve();
    ans = minCosts[eh][ew];
    cout << ans << endl; // 출력하는 부분
    return 0;
}
