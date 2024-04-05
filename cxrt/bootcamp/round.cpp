#include <iostream>
using namespace std;

#define MAXN ((int)1e4)
#define MAX_FARM 100
#define DIR 4

int N;
int X[MAXN + 10];
int Y[MAXN + 10];

int farm[MAX_FARM][MAX_FARM];
bool visited[MAX_FARM][MAX_FARM];

int dirH[] = {1, -1, 0, 0};
int dirW[] = {0, 0, 1, -1};

struct holeChecker{
    bool isHole;
    int holeRound = 0;
};

void InputData()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> X[i] >> Y[i];
        X[i]--;
        Y[i]--;
    }

    for (int i = 0; i < N; i++)
    {
        farm[Y[i]][X[i]] = 1; // grass
    }
}

void initFarm(void)
{
    for (int i = 0; i < MAX_FARM; i++)
    {
        for (int j = 0; j < MAX_FARM; j++)
        {
            farm[i][j] = 0; // no grass
            visited[i][j] = false;
        }
    }
}

bool isInFarm(int h, int w)
{
    return h > -1 && h < MAX_FARM &&
           w > -1 && w < MAX_FARM;
}

bool isValidSpace(int h, int w)
{
    return h > -1 && h < MAX_FARM &&
           w > -1 && w < MAX_FARM &&
           !visited[h][w] &&
           farm[h][w] == 0;
}

bool checkIsHole(int h, int w)
{
    bool isHole = true;
    int newH = h;
    int newW = w;

    bool isBlocked;
    for (int i = 0; i < DIR; i++)
    {
        isBlocked = false;
        newH = h;
        newW = w;

        while (isInFarm(newH, newW))
        {
            newW += dirW[i];
            newH += dirH[i];

            if (farm[newH][newW] == 1)
            {
                isBlocked = true;
                break;
            }
        }

        isHole &= isBlocked;

        if (!isHole)
        {
            break;
        }
    }

    return isHole;
}

int getHoleRound(int h, int w)
{
    int holeRound = 0;
    for (int i = 0; i < DIR; i++)
    {
        int newH = h + dirH[i];
        int newW = w + dirW[i];

        if (isInFarm(newH, newW))
        {
            if (farm[newH][newW] == 1)
            {
                holeRound++;
            }
        }
    }

    return holeRound;
}

int getRound(int h, int w)
{
    int round = 0;

    for (int i = 0; i < DIR; i++)
    {
        int newH = h + dirH[i];
        int newW = w + dirW[i];

        if (isInFarm(newH, newW))
        {
            if (farm[newH][newW] == 0)
            {
                round++;
            }
        }
        else
        {
            round++;
        }
    }

    return round;
}

holeChecker floodFill(int h, int w)
{
    bool isHole = true;
    int holeRound = 0;

    visited[h][w] = true;

    for (int i = 0; i < DIR; i++)
    {
        int newH = h + dirH[i];
        int newW = w + dirW[i];

        if (isValidSpace(newH, newW))
        {
            // cout << h << " : " << w << endl;
            holeChecker hc = floodFill(newH, newW);
            holeRound += hc.holeRound;
            isHole &= hc.isHole;
        }
    }

    if (isHole)
    {
        isHole &= checkIsHole(h, w);
    }
    
    if (isHole)
    {
        holeRound += getHoleRound(h, w);
    }
    
    holeChecker rhc;
    rhc.isHole = isHole;
    rhc.holeRound = holeRound;

    return rhc;
}

int findHole(void)
{
    int holeRound = 0;
    for (int h = 0; h < MAX_FARM; h++)
    {
        for (int w = 0; w < MAX_FARM; w++)
        {

            if (!visited[h][w] && farm[h][w] == 0)
            {
                holeChecker hc = floodFill(h, w);
                if (hc.isHole)
                {
                    holeRound += hc.holeRound;
                }
                
            }
            visited[h][w] = true;
        }
    }

    return holeRound;
}

int getGrassRound(void)
{
    int grassRound = 0;
    for (int i = 0; i < N; i++)
    {
        grassRound += getRound(Y[i], X[i]);
    }

    return grassRound;
}

int Solve(void)
{
    return getGrassRound() - findHole();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int ans = -1;
    InputData(); // 입력받는 부분

    // 여기서부터 작성

    cout << Solve() << "\n"; // 출력하는 부분
    return 0;
}