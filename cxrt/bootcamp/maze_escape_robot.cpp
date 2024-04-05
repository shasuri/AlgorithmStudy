#include <iostream>
#include <queue>

using namespace std;

#define MAXN (100)

struct space
{
    int h;
    int w;
    int time;
};

int W, H;                       // 가로, 세로 크기
int sw, sh, ew, eh;             // 출발 가로세로, 도착 가로세로 좌표
char map[MAXN + 10][MAXN + 10]; // 지도정보

queue<space> dst;

void InputData()
{
    cin >> W >> H;
    cin >> sw >> sh >> ew >> eh;
    sw--;
    sh--;
    ew--;
    eh--;
    for (int i = 0; i < H; i++)
    {
        cin >> &map[i][0];
    }
}

void printMap()
{
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}

bool isValidSpace(int h, int w)
{
    if (h < H && h > -1 && w < W && w > -1 && map[h][w] == '0')
    {
        return true;
    }
    return false;
}

int Solve()
{
    struct space s;

    dst.push({sh, sw, 0});

    s = dst.front();
    map[s.h][s.w] = 'v'; // this space is visited

    while (s.h != eh || s.w != ew)
    {
        // cout << s.h << s.w << s.time << endl;
        dst.pop();
        if (isValidSpace(s.h + 1, s.w)) // check up
        {
            dst.push({s.h + 1, s.w, s.time + 1});
            map[s.h + 1][s.w] = 'v';
        }

        if (isValidSpace(s.h - 1, s.w)) // check down
        {
            dst.push({s.h - 1, s.w, s.time + 1});
            map[s.h - 1][s.w] = 'v';
        }

        if (isValidSpace(s.h, s.w + 1)) // check right
        {
            dst.push({s.h, s.w + 1, s.time + 1});
            map[s.h][s.w + 1] = 'v';
        }

        if (isValidSpace(s.h, s.w - 1)) // check left
        {
            dst.push({s.h, s.w - 1, s.time + 1});
            map[s.h][s.w - 1] = 'v';
        }

        s = dst.front();
    }

    return s.time;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int ans = -1;
    InputData(); // 입력
    // printMap();
    ans = Solve();

    cout << ans << "\n"; // 출력
    return 0;
}