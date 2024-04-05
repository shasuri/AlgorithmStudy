#include <iostream>
using namespace std;
#define MAXN 101

int w, h, n;

struct Point
{
    int y, x;

    int operator-(Point p)
    {
        return abs(y - p.y) + abs(x - p.x);
    }
} stores[MAXN];

Point patrol;

Point getPoint(int dir, int len)
{
    int y, x;
    switch (dir)
    {
    case 1: // North
        y = 0;
        x = len;
        break;
    case 2: // South
        y = h;
        x = len;
        break;
    case 3: // West
        y = len;
        x = 0;
        break;
    case 4: // East
        y = len;
        x = w;
        break;
    }

    return {y, x};
}

void InputData()
{
    int dir, len;
    cin >> w >> h;
    cin >> n;
    for (int i = 0; i < n + 1; i++)
    {
        cin >> dir >> len;
        stores[i] = getPoint(dir, len);
    }

    patrol = stores[n];
}

int Solve(void)
{
    int distSum = 0;
    for (int i = 0; i < n; i++)
    {
        Point store = stores[i];

        int dist = patrol - store;

        if (abs(store.y - patrol.y) == h) // NS Opponent
        {
            dist += min(store.x, patrol.x) * 2;
        }

        if (abs(store.x - patrol.x) == w) // WE Opponent
        {
            dist += min(store.y, patrol.y) * 2;
        }

        if (dist > h + w)
        {
            dist = (h + w) * 2 - dist;
        }

        distSum += dist;
    }

    return distSum;
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