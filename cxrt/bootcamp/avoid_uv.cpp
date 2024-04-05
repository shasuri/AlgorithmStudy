#include <iostream>
#include <queue>

using namespace std;
#define MAXN (100)
int N;                          // 가로, 세로 크기
char map[MAXN + 10][MAXN + 10]; // 지도정보
int minDamage[MAXN + 10][MAXN + 10];

struct Space
{
    int h;
    int w;
    int damaged;
};

queue<Space> spaceQueue;

void InputData()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> &map[i][0];
    }
}
void initMinDist(void)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            minDamage[i][j] = 901;
        }
    }
}

int charToInt(char c)
{
    return c - '0';
}

bool checkValidSpace(int h, int w)
{
    return h > -1 && h < N &&
           w > -1 && w < N;
}

void moveFourDir(Space s)
{
    int hdir[] = {1, -1, 0, 0};
    int wdir[] = {0, 0, 1, -1};
    int nextH, nextW, nextDamage;
    for (int i = 0; i < 4; i++)
    {
        nextH = s.h + hdir[i];
        nextW = s.w + wdir[i];
        
        if (checkValidSpace(nextH, nextW))
        {
            nextDamage = s.damaged + charToInt(map[nextH][nextW]);
            if (minDamage[nextH][nextW] > nextDamage)
            {
                minDamage[nextH][nextW] = nextDamage;
                spaceQueue.push({nextH, nextW, nextDamage});
            }
        }
    }
}

void Solve(void)
{
    spaceQueue.push({0, 0, charToInt(map[0][0])});
    struct Space s;

    while (!spaceQueue.empty())
    {
        s = spaceQueue.front();
        moveFourDir(s);
        spaceQueue.pop();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int ans = -1;
    InputData(); // 입력

    // 여기서부터 작성
    initMinDist();
    Solve();

    cout << minDamage[N - 1][N - 1] << "\n"; // 출력
    return 0;
}