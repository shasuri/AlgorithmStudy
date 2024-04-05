#include <iostream>
using namespace std;

int N;
int A[100 + 10];
int B[100 + 10];

int map[100][100];

int maxX = 0;
int maxY = 0;

int minX = 101;
int minY = 101;

int paperRound = 0;

void initMap(void)
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            map[i][j] = 0;
        }
    }
}

void putColorPaper(int y, int x)
{
    for (int i = y; i < y + 10; i++)
    {
        for (int j = x; j < x + 10; j++)
        {
            map[i][j] = 1;
        }
    }
}

void InputData()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i] >> B[i];
        if (A[i] > maxX)
        {
            maxX = A[i];
        }

        if (A[i] < minX)
        {
            minX = A[i];
        }

        if (B[i] > maxY)
        {
            maxY = B[i];
        }

        if (B[i] < minY)
        {
            minY = B[i];
        }

        putColorPaper(B[i], A[i]);
    }
}

bool checkBoundary(int y, int x)
{
    return y > -1 && y < 100 &&
           x > -1 && x < 100;
}

int dirY[] = {1, -1, 0, 0};
int dirX[] = {0, 0, 1, -1};

void floodFill(int y, int x)
{
    map[y][x] = 2; // visited

    int nx, ny;
    for (int i = 0; i < 4; i++)
    {
        ny = y + dirY[i];
        nx = x + dirX[i];

        if (map[ny][nx] == 0 || !checkBoundary(ny, nx))
        {
            paperRound++;
            continue;
        }

        if (checkBoundary(ny, nx) && map[ny][nx] == 1)
        {
            floodFill(ny, nx);
        }
    }
}

int Solve(void)
{
    for (int i = minY; i <= maxY; i++)
    {
        for (int j = minX; j <= maxX; j++)
        {
            if (map[i][j] != 1)
            {
                continue;
            }
            floodFill(i, j);
        }
    }

    return paperRound;
}

void printPaper(void)
{
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int ans = -1;
    initMap();
    InputData(); // 입력받는 부분

    // printPaper();

    // 여기서부터 작성
    ans = Solve();
    cout << ans << endl; // 출력하는 부분
    return 0;
}
