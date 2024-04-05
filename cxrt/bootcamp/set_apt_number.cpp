#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN (25)
#define DIR 4

int N;
char map[MAXN][MAXN];
bool visited[MAXN][MAXN];

int apartment = 0;
int house[625];

int dirH[] = {1, -1, 0, 0}; //, -1, 1, 1, -1};
int dirW[] = {0, 0, -1, 1}; //, 1, 1, -1, -1};

void InputData()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> &map[i][0];
    }
}

void initVisited(void)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            visited[i][j] = false;
        }
    }
    return;
}

bool checkValidSpace(int h, int w)
{
    return h > -1 && h < N &&
           w > -1 && w < N &&
           map[h][w] == '1' &&
           !visited[h][w];
}

int dfs(int h, int w)
{
    int houseCnt = 1;
    visited[h][w] = true;
    for (int i = 0; i < DIR; i++)
    {
        if (checkValidSpace(h + dirH[i], w + dirW[i]))
        {
            houseCnt += dfs(h + dirH[i], w + dirW[i]);
        }
    }

    return houseCnt;
}

void Solve(void)
{
    initVisited();

    for (int h = 0; h < N; h++)
    {
        for (int w = 0; w < N; w++)
        {
            if (map[h][w] == '1' && !visited[h][w])
            {
                house[apartment++] = dfs(h, w);
            }
        }
    }

    sort(&house[0], &house[apartment]);
}
void OuputData(void)
{
    cout << apartment << '\n';
    for (int i = 0; i < apartment; i++)
    {
        cout << house[i] << '\n';
    }

    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    InputData(); // 입력

    // 여기서부터 작성
    Solve();

    OuputData();
    return 0;
}
