#include <iostream>
using namespace std;

int N;
int A[100 + 10];
int B[100 + 10];
void InputData()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i] >> B[i];
    }
}
int paper[101][101];
int blackLen = 0;
int min_x = 101;
int max_x = 0;
int min_y = 101;
int max_y = 0;

void DrawLine(int x, int y)
{
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};
    paper[y][x] = 2; // black paper line is two
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            x += dx[i];
            y += dy[i];
            paper[y][x] = 2;
            // cout<<x<<","<<y<<endl;
        }
    }
    return;
}

void CntOutLine(int x, int y)
{
    if (x < min_x || x > max_x || y < min_y || y > max_x)
    {
        return;
    }
    if (paper[y][x] == 2)
    {
        paper[y][x] = 3;
        cout << x << "," << y << endl;

        blackLen++;
        cout << blackLen << endl;
        return;
    }
    if (paper[y][x] == 3)
        return;
    if (paper[y][x] == 1)
        return;

    paper[y][x] = 1;
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    for (int i = 0; i < 4; i++)
    {
        CntOutLine(x + dx[i], y + dy[i]);
    }
}
int main()
{
    // int ans = -1;

    InputData(); // 입력받는 부분
    // 여기서부터 작성

    for (int i = 0; i < N; i++)
    {
        DrawLine(A[i], B[i]);
        if (min_x > A[i])
            min_x = A[i];
        if (max_x < A[i])
            max_x = A[i];
        if (min_y > B[i])
            min_y = B[i];
        if (max_y < B[i])
            max_y = B[i];
    }

    min_x -= 2;
    max_x += 12;
    min_y -= 2;
    max_y += 12;
    CntOutLine(min_x, min_y);
    // cout<<min_x<<min_y<<max_x<<max_y<<endl;

    cout << "HI" << endl; // 출력하는 부분
    return 0;
}