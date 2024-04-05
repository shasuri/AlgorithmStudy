#include <iostream>
#include <queue>

using namespace std;

#define MAXN (15)
int R, C;                     // 게임판 행(세로), 열(가로) 크기
char map[MAXN + 5][MAXN + 5]; // 게임판('#':벽, '.':빈공간, 'R':빨간구슬, 'B':파란구슬, 'H':목표구멍)

struct Marble
{
    int h;
    int w;

    bool operator==(Marble m)
    {
        return h == m.h && w == m.w;
    }
};

struct MarbleManager
{
    Marble red;
    Marble blue;
    int tilted; // tilted count
};

Marble redStart;
Marble blueStart;
Marble hole;

void InputData()
{
    cin >> R >> C;
    for (int r = 0; r < R; r++)
    {
        cin >> map[r];
        for (int c = 0; c < C; c++)
        {
            switch (map[r][c])
            {
            case 'R':
                redStart.h = r;
                redStart.w = c;
                break;

            case 'B':
                blueStart.h = r;
                blueStart.w = c;
                break;

            case 'H':
                hole.h = r;
                hole.w = c;
                break;

            default:
                break;
            }
        }
    }
}

int dirH[] = {1, -1, 0, 0};
int dirW[] = {0, 0, 1, -1};

Marble getTiltedLoc(Marble m, int h, int w)
{
    if (map[m.h + h][m.w + w] != '#')
    {
        m.h += h;
        m.w += w;
    }

    return m;
}

bool checkFailed(MarbleManager mm)
{
    return mm.tilted >= 10 ||
           mm.red == mm.blue ||
           mm.blue == hole;
}

int Solve(void)
{
    queue<MarbleManager> mmQueue;
    mmQueue.push({redStart, blueStart, 0});

    MarbleManager mm;

    while (!mmQueue.empty())
    {
        mm = mmQueue.front();
        mmQueue.pop();

        for (int i = 0; i < 4; i++)
        {
            Marble newRed = getTiltedLoc(mm.red, dirH[i], dirW[i]);
            Marble newBlue = getTiltedLoc(mm.blue, dirH[i], dirW[i]);

            if (newRed == hole)
            {
                return mm.tilted + 1;
            }

            MarbleManager newMM = {
                newRed,
                newBlue,
                mm.tilted + 1};

            if (checkFailed(newMM))
            {
                continue;
            }

            mmQueue.push(newMM);
        }
    }

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T, ans = -10;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        InputData(); // 입력

        // 여기서부터 작성
        ans = Solve();

        cout << ans << "\n"; // 출력
    }
    return 0;
}
