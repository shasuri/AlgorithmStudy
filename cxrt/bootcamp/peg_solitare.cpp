#include <iostream>
#include <algorithm>

using namespace std;

#define MAXH (5)
#define MAXW (9)
#define MAX_PIN 8
#define DIR 4

const char PIN = 'o';
const char OFFSET = '0';

char map[MAXH + 2][MAXW + 2];
int solremain, solmove;

struct Pin
{
    int h = 0;
    int w = 0;
    bool removed;

    Pin() {}
    Pin(int h_, int w_) : h(h_), w(w_)
    {
        removed = false;
    }
};

struct GameBoard
{
    int pinCount = 0;
    Pin pins[MAX_PIN];
};
void printBoard(void);
void InputData()
{
    for (int h = 0; h < MAXH; h++)
    {
        cin >> &map[h][0];
    }
}

GameBoard getGameBoard(void)
{
    GameBoard gb;

    // init
    for (int i = 0; i < MAX_PIN; i++)
    {
        gb.pins[i].removed = true;
    }

    for (int h = 0; h < MAXH; h++)
    {
        for (int w = 0; w < MAXW; w++)
        {
            if (map[h][w] == PIN)
            {
                map[h][w] = OFFSET + gb.pinCount;
                gb.pins[gb.pinCount++] = {h, w};
            }
        }
    }

    return gb;
}

int minRemain, minMove;
GameBoard gb;

bool isInBoundary(Pin u)
{
    return u.h > -1 && u.h < MAXH &&
           u.w > -1 && u.w < MAXW;
}

bool isSpace(Pin u)
{
    return isInBoundary(u) &&
           map[u.h][u.w] == '.';
}

bool isWall(Pin u)
{
    return isInBoundary(u) &&
           map[u.h][u.w] == '#';
}

bool isPin(Pin u)
{
    return isInBoundary(u) &&
           map[u.h][u.w] >= '0' &&
           map[u.h][u.w] <= '7';
}

int getPinInd(Pin p)
{
    return map[p.h][p.w] - OFFSET;
}

int dirH[] = {1, -1, 0, 0};
int dirW[] = {0, 0, 1, -1};

bool isMovable(Pin unknown, int dirInd)
{
    if (!isPin(unknown) ||
        gb.pins[getPinInd(unknown)].removed)
    {
        return false;
    }

    Pin next = {unknown.h + dirH[dirInd], unknown.w + dirW[dirInd]};

    return isSpace(next);
}

void movePin(int mv, int rm, int dirInd)
{
    map[h][w] = '.';
    gb.pins[mv] = {gb.pins[rm].h + dirH[dirInd], gb.pins[rm].w + dirW[dirInd]};
    map[h][w] = mv + OFFSET;

    map[gb.pins[rm].h][gb.pins[rm].w] = '.';
    gb.pins[rm].removed = true;

    gb.pinCount--;
}

void revertPin(int mv, int rm, int dirInd)
{
    map[gb.pins[mv].h][gb.pins[mv].w] = '.';
    gb.pins[mv] = {gb.pins[rm].h - dirH[dirInd], gb.pins[rm].w - dirW[dirInd]};
    map[gb.pins[mv].h][gb.pins[mv].w] = mv + OFFSET;

    map[gb.pins[rm].h][gb.pins[rm].w] = rm + OFFSET;
    gb.pins[rm].removed = false;

    gb.pinCount++;
}

void dfs(int moveCount)
{
    if (gb.pinCount == 1)
    {
        // printBoard(moveCount);

        if (minRemain == 1)
        {
            minMove = min(minMove, moveCount);
        }
        else if (minRemain > 1)
        {
            minRemain = 1;
            minMove = moveCount;
        }
        return;
    }

    bool isMoved = false;

    for (int m = 0; m < MAX_PIN; m++)
    {
        if (gb.pins[m].removed)
        {
            continue;
        }

        for (int i = 0; i < DIR; i++)
        {
            Pin u = {gb.pins[m].h + dirH[i],
                     gb.pins[m].w + dirW[i]};

            if (isMovable(u, i))
            {
                isMoved = true;
                oo.int mvInd = m;
                int rmInd = getPinInd(u);

                movePin(mvInd, rmInd, i);
                dfs(moveCount + 1);
                revertPin(mvInd, rmInd, i);
            }
        }
    }

    if (!isMoved)
    {
        // printBoard(moveCount);

        if (minRemain > gb.pinCount)
        {
            minRemain = gb.pinCount;
            minMove = moveCount;
        }
        else if (minRemain == gb.pinCount)
        {
            minMove = min(minMove, moveCount);
        }
    }
}

void printBoard(int moveCount)
{
    for (int h = 0; h < MAXH; h++)
    {
        for (int w = 0; w < MAXW; w++)
        {
            cout << map[h][w];
        }
        cout << endl;
    }
    cout << gb.pinCount << moveCount << endl;
}

void Solve(void)
{
    minRemain = MAX_PIN;
    minMove = MAX_PIN * MAXH * MAXW;

    gb = getGameBoard();

    dfs(0);
}

int main()
{
    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        InputData(); // 입력받는 부분

        // 여기서부터 작성
        Solve();

        solremain = minRemain;
        solmove = minMove;

        cout << solremain << " " << solmove << endl; // 출력하는 부분
    }
    return 0;
}
