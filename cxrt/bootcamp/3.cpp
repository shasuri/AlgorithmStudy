#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN (100)
int paper[MAXN + 10][MAXN + 10]; // 도화지
void FillPaper(int sh, int sw, int eh, int ew)
{
    for (int i = sh; i < eh; i++)
    {
        for (int j = sw; j < ew; j++)
        {
            paper[i][j] = 1;
        }
    }
}
void InputData()
{
    int n, sw, sh;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> sw >> sh;
        FillPaper(sh, sw, sh + 10, sw + 10);
    }
}
int isPossible(int sh, int sw, int eh, int ew)
{
    for (int i = sh; i <= eh; i++)
    {
        for (int j = sw; j <= ew; j++)
        {
            if (paper[i][j] == 0)
                return 0; // 불가능
        }
    }
    return 1; // 가능
}

int SolveN3()
{
    int maxarea = 100, area;
    // 1.배열 정리해서 높이 구하기
    for (int w = 0; w < MAXN; w++)
    { // 가로
        for (int h = 1; h < MAXN; h++)
        { // 세로
            if (paper[h][w] == 0)
                continue;
            paper[h][w] += paper[h - 1][w];
        }
    }
    // 2.최대넓이 구하기
    for (int r = 1; r < MAXN; r++)
    {
        for (int s = 0; s < MAXN; s++)
        {
            int h = 101; // 최소 높이 선택해야 하므로 최대값
            for (int k = s; k < MAXN; k++)
            {
                if (h > paper[r][k])
                    h = paper[r][k]; // 낮은 높이 선택
                if (h == 0)
                    break;
                area = h * (k - s + 1);
                if (maxarea < area)
                    maxarea = area;
            }
        }
    }
    return maxarea;
}
int main()
{
    InputData();
    // int ans = SolveN6();
    int ans = SolveN3();
    cout << ans << endl;
    return 0;
}
