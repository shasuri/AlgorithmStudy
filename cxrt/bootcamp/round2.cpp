#include <iostream>
using namespace std;
#define MAXN ((int)1e4)
int N;
int X[MAXN + 10];
int Y[MAXN + 10];

int farm[100][100];

int maxX = -1;
int maxY = -1;
int minX = 101;
int minY = 101;

void InputData()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> X[i] >> Y[i];
        X[i]--;
        Y[i]--;

        farm[Y[i]][X[i]] = 1;

        if (maxX < X[i])
        {
            maxX = X[i];
        }

        if (maxY < Y[i])
        {
            maxY = Y[i];
        }

        if (minX > X[i])
        {
            minX = X[i];
        }

        if (minY > Y[i])
        {
            minY = Y[i];
        }
    }
}

bool isValidSpace(int y, int x)
{
    return y > minY - 1 && y < maxY + 1 &&
           x > minX - 1 && x < maxX + 1 &&
           farm[y][x] == 0;
}

int dirX[] = {1, -1, 0, 0};
int dirY[] = {0, 0, 1, -1};

void floodFill(int y, int x)
{
    farm[y][x] = 2; // visited

    for (int i = 0; i < 4; i++)
    {
        int newX = x + dirX[i];
        int newY = y + dirY[i];

        if (isValidSpace(y, x))
        {
            floodFill(newY, newX);
        }
    }
}

bool isInFarm(int y, int x)
{
    return y > minY - 1 && y < maxY + 1 &&
           x > minX - 1 && x < maxX + 1;
}

int getGrassRound(void)
{
    int round = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int newY = Y[i] + dirY[j];
            int newX = X[i] + dirX[j];

            if (isInFarm(newY, newX))
            {
                if (farm[newY][newX] == 2)
                {
                    round++;
                }
            }
            else
            {
                round++;
            }
        }
    }
    return round;
}

int Solve(void)
{
    floodFill(minY - 1, minX - 1);

    return getGrassRound();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int ans = -1;
    InputData(); // 입력받는 부분

    // 여기서부터 작성
    ans = Solve();

    cout << ans << "\n"; // 출력하는 부분
    return 0;
}