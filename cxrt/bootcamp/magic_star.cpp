#include <iostream>

using namespace std;

#define MAGIC 282
#define STAR_HAS_POINT 12
#define STAR_HAS_LINE 6
#define LINE_HAS_POINT 4
#define POINT_HAS_LINE 2

char map[5][10];
bool used[STAR_HAS_POINT];

const char BLANK = 'x';
const char OFFSET = 'A';

struct Point
{
    int r, c;
};

// find row and col by point index
const Point STAR_POINT[STAR_HAS_POINT] = {
    {0, 4},
    {1, 1},
    {1, 3},
    {1, 5},
    {1, 7},
    {2, 2},
    {2, 6},
    {3, 1},
    {3, 3},
    {3, 5},
    {3, 7},
    {4, 4}};

// point by line
const int STAR[STAR_HAS_LINE][LINE_HAS_POINT] = {
    {0, 2, 5, 7},
    {0, 3, 6, 10},
    {7, 8, 9, 10},
    {1, 2, 3, 4},
    {1, 5, 8, 11},
    {4, 6, 9, 11}};

// line by point
const int POINT_LINE[STAR_HAS_POINT][POINT_HAS_LINE] = {
    {0, 1},
    {3, 4},
    {0, 3},
    {1, 3},
    {3, 5},
    {0, 4},
    {1, 5},
    {0, 2},
    {2, 4},
    {2, 5},
    {1, 2},
    {4, 5}};

void InputData()
{
    for (int h = 0; h < 5; h++)
    {
        cin >> map[h];
    }
}

void OutputData()
{
    for (int h = 0; h < 5; h++)
    {
        cout << map[h] << endl;
    }
}

char intToChar(int i)
{
    return OFFSET + i;
}

int charToInt(char c)
{
    return c - OFFSET;
}

struct LineStatus
{
    int blankCount = 0;
    int lineSum = 0;

    LineStatus(int blankCount_, int lineSum_) : blankCount(blankCount_), lineSum(lineSum_) {}
};

LineStatus getLineStatus(int lineInd)
{
    int lineSum = 0;
    int blankCount = 0;
    for (int i = 0; i < LINE_HAS_POINT; i++)
    {
        int mapInd = STAR[lineInd][i];
        Point mapPoint = STAR_POINT[mapInd];
        char p = map[mapPoint.r][mapPoint.c];
        if (p == BLANK)
        {
            p = 0;
            blankCount++;
        }

        lineSum += p;
    }

    return {blankCount, lineSum};
}

bool isInsertable(int alpInd, int mapInd)
{
    if (used[alpInd])
    {
        return false;
    }

    const int *linesToCheck = POINT_LINE[mapInd];
    char alp = intToChar(alpInd);

    for (int i = 0; i < POINT_HAS_LINE; i++)
    {
        LineStatus lineStatus = getLineStatus(linesToCheck[i]);

        if (lineStatus.blankCount == 0)
        {
            return false;
        }

        if (lineStatus.blankCount == 1 &&
            alp + lineStatus.lineSum != MAGIC)
        {
            return false;
        }

        if (lineStatus.blankCount > 1 &&
            alp + lineStatus.lineSum >= MAGIC)
        {
            return false;
        }
    }

    return true;
}

void insertAlphabet(int alpInd, int mapInd)
{
    Point mapPoint = STAR_POINT[mapInd];
    map[mapPoint.r][mapPoint.c] = intToChar(alpInd);
    used[alpInd] = true;
}

void removeAlphabet(int alpInd, int mapInd)
{
    Point mapPoint = STAR_POINT[mapInd];
    map[mapPoint.r][mapPoint.c] = BLANK;
    used[alpInd] = false;
}

bool isAlreadyWritten(int mapInd)
{
    Point mapPoint = STAR_POINT[mapInd];
    return map[mapPoint.r][mapPoint.c] != BLANK;
}
void OutputLineSum(void);
bool dfs(int mapInd)
{
    if (mapInd >= STAR_HAS_POINT)
    {
        return true;
    }
    if (isAlreadyWritten(mapInd))
    {
        return dfs(mapInd + 1);
    }

    // if (map[0][4] == 'E')
    // {
    //     /* code */
    //     OutputData();
    //     OutputLineSum();
    // }

    for (int i = 0; i < STAR_HAS_POINT; i++)
    {
        if (isInsertable(i, mapInd))
        {
            insertAlphabet(i, mapInd);
            if (dfs(mapInd + 1))
            {
                return true;
            }
            removeAlphabet(i, mapInd);
        }
    }
    return false;
}

void scanUsedAlphabet()
{
    for (int i = 0; i < STAR_HAS_POINT; i++)
    {
        Point mapPoint = STAR_POINT[i];
        char alp = map[mapPoint.r][mapPoint.c];
        if (alp != BLANK)
        {
            used[charToInt(alp)] = true;
        }
    }
}

void Solve(void)
{
    scanUsedAlphabet();
    dfs(0);
}

void OutputLineSum(void)
{
    for (int i = 0; i < STAR_HAS_LINE; i++)
    {
        cout << getLineStatus(i).lineSum << " ";
    }
    cout << endl;
}

int main()
{
    InputData(); // 입력받는 부분

    // 여기서부터 작성
    Solve();

    OutputData(); // 출력하는 부분
    return 0;
}