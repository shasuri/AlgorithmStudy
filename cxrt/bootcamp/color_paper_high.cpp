#include <iostream>
#include <algorithm>
#define PAPER 10
#define BACKGROUND 100
 
using namespace std;
 
int N; // 색종이 수
int X[BACKGROUND];
int Y[BACKGROUND];
 
int bg[BACKGROUND][BACKGROUND];
 
void InputData()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> X[i] >> Y[i];
    }
}
 
void printPaper(void)
{
    for (int i = 0; i < BACKGROUND; i++)
    {
        for (int j = 0; j < BACKGROUND; j++)
        {
            if (bg[i][j] >= 10)
            {
                cout << bg[i][j] << " ";
            }
            else
            {
                cout << bg[i][j] << "  ";
            }
        }
        cout << endl;
    }
}
 
void fillPaper(void)
{
    for (int i = 0; i < BACKGROUND; i++)
    {
        for (int j = 0; j < BACKGROUND; j++)
        {
            bg[i][j] = 0;
        }
    }
 
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < PAPER; j++)
        {
            for (int k = 0; k < PAPER; k++)
            {
                bg[Y[i] + j][X[i] + k] = 1;
            }
        }
    }
}
 
int dfs(int y, int x)
{
    if (y >= BACKGROUND || bg[y][x] == 0)
    {
        return y;
    }
 
    if (y < BACKGROUND && bg[y][x] > 1)
    {
        return y + bg[y][x];
    }
 
    int deepest = dfs(y + 1, x);
    bg[y][x] = deepest - y;
    return deepest;
}
 
void progressDown(int y, int x)
{
    for (int i = x; i < x + 10; i++)
    {
        dfs(y, i);
    }
}
 
int progressRight(void)
{
    int maxArea = 0;
    for (int i = 0; i < BACKGROUND; i++)
    {
        for (int j = 0; j < BACKGROUND; j++)
        {
 
            int x = j;
            int y = i;
            if (bg[y][x] == 0)
            {
                continue;
            }
 
            int w = 0;
            int minY = 101;
            while (x + w < BACKGROUND && bg[y][x + w] > 0)
            {
                minY = min(minY, bg[y][x + w]);
                if (maxArea < (w + 1) * minY)
                {
                    maxArea = (w + 1) * minY;
                }
 
                // cout << k << p << endl;
 
                w++;
            }
        }
    }
 
    return maxArea;
}
 
int Solve()
{
    fillPaper();
    for (int i = 0; i < N; i++)
    {
        progressDown(Y[i], X[i]);
    }
    // printPaper();
    return progressRight();
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