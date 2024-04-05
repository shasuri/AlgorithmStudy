#include <iostream>
#include <utility>

using namespace std;

#define MAXW (20)
#define INF 40000

int N; // 도로의 개수
int W; // 사건의 개수

struct Point
{
    int r, c; // 세로, 가로
    Point(){};
    Point(int r_, int c_) : r(r_), c(c_){};
};

Point pos[MAXW + 10]; // 사건 좌표

void InputData()
{
    cin >> N;
    cin >> W;
    for (int i = 0; i < W; i++)
    {
        cin >> pos[i].r >> pos[i].c;
        pos[i].r--;
        pos[i].c--;
    }
}

int getDist(Point t, Point u)
{
    return abs(t.c - u.c) + abs(t.r - u.r);
}

int minMoved = INF;

void dfs(int caseInd, pair<Point, Point> policePair, int moved)
{
    if (moved >= minMoved)
    {
        return;
    }
    
    if (caseInd > W - 1)
    {
        minMoved = moved;
        return;
    }

    Point curCase = pos[caseInd];

    dfs(caseInd + 1,
        make_pair(curCase, policePair.second),
        moved + getDist(curCase, policePair.first));

    dfs(caseInd + 1,
        make_pair(policePair.first, curCase),
        moved + getDist(curCase, policePair.second));
}

void Solve(void)
{
    pair<Point, Point> policePair =
        make_pair(Point(0, 0), Point(N - 1, N - 1));

    dfs(0, policePair, 0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int ans = -1;
    InputData(); // 입력받는 부분

    // 여기서부터 작성
    Solve();
    ans = minMoved;
    cout << ans << "\n"; // 출력하는 부분
    return 0;
}