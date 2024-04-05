#include <iostream>
#include <queue>

using namespace std;

#define MAXN (50)
#define DIR 4

int R, C; // 지도 세로, 가로 크기
char map[MAXN + 1][MAXN + 1];
int stepMap[MAXN][MAXN];
/* step map guide
    0       : flood starts, *
    1 ~ INF : flood time
    -1      : artist start, S
    -2      : artist visited
    -3      : rock space, X
    251     : beaver's den, D
    252     : blank space, .
*/

struct Point
{
    int h;
    int w;
    int step = 0;

    bool operator==(Point p)
    {
        return h == p.h && w == p.w;
    }

    Point() {}
    Point(int h_, int w_, int step_) : h(h_), w(w_), step(step_) {}
};

Point artist;
Point beaverDen;
queue<Point> floodQueue;

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
            case 'S': // artist start
                artist.h = r;
                artist.w = c;
                stepMap[r][c] = -1;
                break;

            case 'D': // beaver's den
                beaverDen.h = r;
                beaverDen.w = c;
                stepMap[r][c] = 251;
                break;

            case '.': // blank space
                stepMap[r][c] = 252;
                break;

            case 'X': // rock space
                stepMap[r][c] = -3;
                break;

            case '*': // flood starts
                floodQueue.push({r, c, 0});
                stepMap[r][c] = 0;
                break;

            default:
                break;
            }
        }
    }
}

int dirH[] = {1, -1, 0, 0};
int dirW[] = {0, 0, 1, -1};

bool isInBoundary(Point p)
{
    return p.h > -1 && p.h < R &&
           p.w > -1 && p.w < C;
}

bool isFloodable(Point f)
{
    return isInBoundary(f) &&
           stepMap[f.h][f.w] == 252; // only flood to blank space
}

void simulFlood(void)
{
    Point f;
    while (!floodQueue.empty())
    {
        f = floodQueue.front();
        floodQueue.pop();

        for (int i = 0; i < DIR; i++)
        {
            Point newF = {f.h + dirH[i], f.w + dirW[i], f.step + 1};
            if (isFloodable(newF))
            {
                stepMap[newF.h][newF.w] = newF.step;
                floodQueue.push(newF);
            }
        }
    }
}

void artistVisitHere(Point p)
{
    stepMap[p.h][p.w] = -2;
}

bool isArtistVisitable(Point a)
{
    return isInBoundary(a) &&
           a.step < stepMap[a.h][a.w];
}

int moveArtist(void)
{
    queue<Point> moveQueue;
    moveQueue.push(artist);
    artistVisitHere(artist);

    Point a;

    while (!moveQueue.empty())
    {
        a = moveQueue.front();
        moveQueue.pop();

        for (int i = 0; i < DIR; i++)
        {
            Point newA = {a.h + dirH[i], a.w + dirW[i], a.step + 1};

            if (isArtistVisitable(newA))
            {
                if (newA == beaverDen)
                {
                    return newA.step;
                }

                artistVisitHere(newA);
                moveQueue.push(newA);
            }
        }
    }

    return -1; // KAKTUS
}

void printMap(void)
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cout << stepMap[i][j] << " ";
            if (stepMap[i][j] < 10 && stepMap[i][j] > -1)
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}

int Solve(void)
{
    simulFlood();
    // printMap();
    return moveArtist();
}

int main()
{
    int T, ans = -1;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++)
    {
        InputData(); // 입력 받는 부분
        // 여기서부터 작성

        ans = Solve();
        if (ans == -1)
            cout << "KAKTUS" << endl; // 출력 하는 부분
        else
            cout << ans << endl;
    }
    return 0;
}