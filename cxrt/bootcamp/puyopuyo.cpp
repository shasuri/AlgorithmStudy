#include <iostream>
#include <queue>

using namespace std;

#define MAXH (12)
#define MAXW (6)
#define DIR 4
#define MINPOP 4

char map[MAXH][MAXW + 1];

int dirH[] = {1, -1, 0, 0};
int dirW[] = {0, 0, 1, -1};

struct Puyo
{
    int h;
    int w;
    char color;

    Puyo() {}
    Puyo(int h_, int w_) : h(h_), w(w_)
    {
        color = map[h_][w_];
    }
};

void InputData()
{
    for (int i = 0; i < MAXH; i++)
    {
        cin >> &map[i][0];
    }
}

bool isPuyo(Puyo p)
{
    return p.color != '.';
}

bool isSamePuyo(Puyo p, char color)
{
    return p.h > -1 && p.h < MAXH &&
           p.w > -1 && p.w < MAXW &&
           p.color == color;
}

int getContBlank(Puyo point)
{
    int contBlank = 0;
    while (point.h < MAXH && !isPuyo(point))
    {
        contBlank++;
        point = {point.h - 1, point.w};
    }
    return contBlank;
}

void pullDownPuyo(Puyo pullStart, int contBlank)
{
    for (int i = 0; i < contBlank; i++)
    {
        map[pullStart.h - i][pullStart.w] =
            map[pullStart.h - i - contBlank][pullStart.w];

        map[pullStart.h - i - contBlank][pullStart.w] = '.';
    }
}

void fallPuyo(void)
{
    for (int w = MAXW - 1; w > -1; w--)
    {
        for (int h = MAXH - 1; h > -1; h--)
        {
            Puyo point = {h, w};
            if (!isPuyo(point))
            {
                int contBlank = getContBlank(point);
                if (h - contBlank < 0)
                {
                    break;
                }
                pullDownPuyo(point, contBlank);
            }
        }
    }
}

bool popPuyo(Puyo start)
{
    queue<Puyo> puyoQueue;
    queue<Puyo> blankQueue;

    bool visited[MAXH][MAXW];

    for (int h = 0; h < MAXH; h++)
    {
        for (int w = 0; w < MAXW; w++)
        {
            visited[h][w] = false;
        }
    }

    puyoQueue.push(start);
    blankQueue.push(start);
    visited[start.h][start.w] = true;

    int popPuyoCount = 1;

    while (!puyoQueue.empty())
    {
        Puyo curPuyo = puyoQueue.front();
        puyoQueue.pop();

        for (int i = 0; i < DIR; i++)
        {
            Puyo nextPuyo = {curPuyo.h + dirH[i], curPuyo.w + dirW[i]};

            if (isSamePuyo(nextPuyo, curPuyo.color) && !visited[nextPuyo.h][nextPuyo.w])
            {
                puyoQueue.push(nextPuyo);
                blankQueue.push(nextPuyo);
                visited[nextPuyo.h][nextPuyo.w] = true;

                popPuyoCount++;
            }
        }
    }

    if (popPuyoCount >= MINPOP)
    {
        while (!blankQueue.empty())
        {
            Puyo blank = blankQueue.front();
            blankQueue.pop();

            map[blank.h][blank.w] = '.';
        }

        return true;
    }

    return false;
}

int Solve(void)
{
    int chain = -1;
    bool isPopped;

    do
    {
        chain++;
        fallPuyo();

        isPopped = false;
        for (int h = 0; h < MAXH; h++)
        {
            for (int w = 0; w < MAXW; w++)
            {
                Puyo puyo = {h, w};
                if (isPuyo(puyo))
                {
                    isPopped |= popPuyo(puyo);
                }
            }
        }
    } while (isPopped);

    return chain;
}

int main()
{
    int T, t, ans = -1;
    cin >> T;
    for (t = 0; t < T; t++)
    {
        InputData(); // 입력받는 부분

        // 여기서부터 작성
        ans = Solve();

        cout << ans << endl; // 출력하는 부분
    }
    return 0;
}