#include <iostream>
#include <queue>
using namespace std;

#define MAXFARM 52
#define COWS 26
#define MAXL 1001
#define MAXWALK 10000001

int P;

int pathMap[MAXFARM][MAXFARM];
int minWalked[MAXFARM];

char farm;
int sol;

int charToInt(char);
const int BARN = charToInt('Z');

struct Cow
{
    int id;
    int loc;
    int walked;
};
Cow minWalkedCow;

int charToInt(char c)
{
    if (c >= 'A' && c <= 'Z')
    {
        return c - 'A';
    }

    if (c >= 'a' && c <= 'z')
    {
        return c - 'a' + COWS;
    }

    return -1;
}

void InputData()
{
    char farm1, farm2;
    int f1, f2, len;

    cin >> P;

    for (int i = 0; i < P; i++)
    {
        cin >> farm1 >> farm2 >> len;
        f1 = charToInt(farm1);
        f2 = charToInt(farm2);

        if (f1 == -1 || f2 == -1)
        {
            cout << "Invalid" << endl;
            return;
        }

        pathMap[f1][f2] = min(len, pathMap[f1][f2]);
        pathMap[f2][f1] = min(len, pathMap[f2][f1]);
    }
}

void init(void)
{
    for (int i = 0; i < MAXFARM; i++)
    {
        for (int j = 0; j < MAXFARM; j++)
        {
            pathMap[i][j] = MAXL;
        }
    }

    for (int i = 0; i < MAXFARM; i++)
    {
        minWalked[i] = MAXWALK;
    }
}

bool isWalkable(Cow c, int dst)
{
    int src = c.loc;
    return pathMap[src][dst] != MAXL &&
           (c.walked + pathMap[src][dst]) < minWalked[dst];
}

void Solve(void)
{
    queue<Cow> walks;

    for (int i = 0; i < COWS - 1; i++) // except barn, Z
    {
        walks.push({i, i, 0});
    }

    Cow c;

    while (!walks.empty())
    {
        c = walks.front();
        walks.pop();

        for (int dst = 0; dst < MAXFARM; dst++)
        {
            if (c.loc != dst && isWalkable(c, dst))
            {
                if (dst == BARN)
                {
                    minWalkedCow = {c.id, BARN, c.walked + pathMap[c.loc][dst]};
                    minWalked[dst] = c.walked + pathMap[c.loc][dst];
                    continue;
                }

                walks.push({c.id, dst, c.walked + pathMap[c.loc][dst]});
                minWalked[dst] = c.walked + pathMap[c.loc][dst];
            }
        }
    }
}

int main()
{
    init();
    InputData(); // 입력받는 부분

    // 여기서부터 작성
    Solve();
    farm = minWalkedCow.id + 'A';
    sol = minWalkedCow.walked;

    cout << farm << " " << sol << endl; // 출력하는 부분
    return 0;
}