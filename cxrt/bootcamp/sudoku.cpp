#include <iostream>
using namespace std;

#define MAXN (9)
#define BLANK 0

int sudoku[MAXN][MAXN];

int widthVisit[MAXN];
int heightVisit[MAXN];
int boxVisit[MAXN];

const int ALL_CLEARED = (1 << MAXN) - 1;

struct Point
{
    int r, c;
};

void InputData()
{
    for (int r = 0; r < MAXN; r++)
    {
        for (int c = 0; c < MAXN; c++)
        {
            cin >> sudoku[r][c];
        }
    }
}
void OutputData()
{
    for (int r = 0; r < MAXN; r++)
    {
        for (int c = 0; c < MAXN; c++)
        {
            cout << sudoku[r][c] << " ";
        }
        cout << endl;
    }
}

int getNum(Point p)
{
    return sudoku[p.r][p.c];
}
int getBoxInd(Point p)
{
    return (p.r / 3) * 3 + p.c / 3;
}

int getMask(int n)
{
    return 1 << (n - 1);
}

void visitHere(Point p, int n)
{
    if (n == BLANK)
    {
        return;
    }

    int visitMask = getMask(n);

    widthVisit[p.r] |= visitMask;
    heightVisit[p.c] |= visitMask;
    boxVisit[getBoxInd(p)] |= visitMask;

    sudoku[p.r][p.c] = n;
}

void revertHere(Point p, int n)
{
    int visitMask = getMask(n);

    widthVisit[p.r] ^= visitMask;
    heightVisit[p.c] ^= visitMask;
    boxVisit[getBoxInd(p)] ^= visitMask;

    sudoku[p.r][p.c] = BLANK;
}

bool isVisited(Point p, int n)
{
    int visitMask = getMask(n);

    return widthVisit[p.r] & visitMask ||
           heightVisit[p.c] & visitMask ||
           boxVisit[getBoxInd(p)] & visitMask;
}

Point getNextPoint(Point p)
{
    p.c++;
    if (p.c > 8)
    {
        p.r++;
        p.c %= 9;
    }

    return p;
}

bool dfs(Point p)
{
    if (p.r > 8)
    {
        return true;
    }

    if (getNum(p) != BLANK)
    {
        return dfs(getNextPoint(p));
    }

    // OutputData();
    // cout << endl;


    for (int n = 1; n <= MAXN; n++)
    {
        if (!isVisited(p, n))
        {
            visitHere(p, n);
            
            if (dfs(getNextPoint(p)))
            {
                return true;
            }

            revertHere(p, n);
        }
    }

    return false;
}

void scanVisit(void)
{
    for (int r = 0; r < MAXN; r++)
    {
        for (int c = 0; c < MAXN; c++)
        {
            Point p = {r, c};
            visitHere(p, getNum(p));
        }
    }
}

void Solve(void)
{
    scanVisit();

    dfs({0, 0});
}

int main()
{
    InputData(); // 입력받는 부분

    // 여기서부터 작성
    Solve();

    OutputData(); // 출력하는 부분
    // cout << getBoxInd({4,1}) << endl;

    // cout << (13 & ~4)<< endl;
    return 0;
}