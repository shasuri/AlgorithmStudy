#include <iostream>
using namespace std;

int A[5 + 10][5 + 10];
int B[25 + 10];

int checker[12];
int board = 0; // check by bit

struct space
{
    int y;
    int x;
} map[26];

int getXBase(void)
{
    return (1 << 5) - 1;
}

int getYBase(void)
{
    int yBase = 0;

    for (int i = 0; i < 5; i++)
    {
        yBase |= (1 << (5 * i));
    }
    // cout << yBase << endl;
    return yBase;
}

int getSpiral(void)
{
    int spiral = 0;

    for (int i = 0; i < 5; i++)
    {
        spiral |= (1 << (6 * i));
    }

    return spiral;
}

int getRevSpiral(void)
{
    int revSpiral = 0;
    int base = (1 << 4);

    for (int i = 0; i < 5; i++)
    {
        revSpiral |= (base << (4 * i));
    }

    return revSpiral;
}

void setChecker(void)
{
    int indexBase = 0;

    int xBase = getXBase();

    for (int i = 0; i < 5; i++)
    {
        checker[indexBase + i] = xBase << (5 * i);
        // cout << checker[indexBase + i] << endl;
    }

    int yBase = getYBase();

    indexBase += 5;
    for (int i = 0; i < 5; i++)
    {
        checker[indexBase + i] = yBase << i;
    }

    checker[10] = getSpiral();
    checker[11] = getRevSpiral();
    
}

void InputData()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> A[i][j];
            map[A[i][j]] = {i, j};
        }
    }
    for (int i = 0; i < 25; i++)
    {
        cin >> B[i];
    }
}

void checkSpace(int n)
{
    int y = map[n].y;
    int x = map[n].x;

    board |= 1 << ((y * 5) + x);

    // cout << y << " , " << x << endl;
    // cout << "board : " << board << endl;
}

bool checkTripleBingo(void)
{
    int bingoCount = 0;
    for (int i = 0; i < 12; i++) // check all bingo patterns
    {

        if ((board & checker[i]) == checker[i])
        {
            // cout << "checks : " << (board & checker[i]) << endl;
            bingoCount++;
        }
    }

    if (bingoCount > 2)
    {
        return true;
    }
    return false;
}

int Solve(void)
{
    setChecker();
    for (int i = 0; i < 25; i++)
    {
        checkSpace(B[i]);

        if (i > 10) // minimum bingo checks
        {
            // cout << i << endl;
            if (checkTripleBingo())
            {
                return i + 1;
            }
        }
    }

    return 25;
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
