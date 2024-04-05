#include <iostream>
#include <queue>

using namespace std;

#define MAXN ((int)1e3)
int M, N;                         // 상자의 가로, 세로 칸 수
int map[MAXN + 10][MAXN + 10];    // 토마토 정보
int dayMap[MAXN + 10][MAXN + 10]; // ripe days

struct Tomato
{
    int h;
    int w;
    int day;
};

queue<Tomato> ripeQueue;

void InputData()
{
    cin >> M >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];
        }
    }
}

bool checkValidTomato(int h, int w)
{
    if (h > -1 && h < N &&
        w > -1 && w < M &&
        map[h][w] == 0)
    {
        return true;
    }

    return false;
}

void ripeNearTomato(int h, int w, int d)
{
    int hdir[] = {1, -1, 0, 0};
    int wdir[] = {0, 0, 1, -1};

    for (int i = 0; i < 4; i++)
    {
        if (checkValidTomato(h + hdir[i], w + wdir[i]))
        {
            ripeQueue.push({h + hdir[i], w + wdir[i], d + 1});
            map[h + hdir[i]][w + wdir[i]] = 1;
            dayMap[h + hdir[i]][w + wdir[i]] = d + 1;
        }
    }
}

int Solve(void)
{

    bool isAlreadyRipe = true;
    bool isThereNoTomato = true;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (map[i][j] == 0)
            {
                isThereNoTomato = false;
                isAlreadyRipe = false;
                dayMap[i][j] = -1;
            }

            if (map[i][j] == 1) // start on ripe tomato
            {
                isThereNoTomato = false;
                ripeQueue.push({i, j, 0});
                dayMap[i][j] = 0;
            }

            if (map[i][j] == -1)
            {
                dayMap[i][j] = -2;
            }
        }
    }

    if (isAlreadyRipe || isThereNoTomato)
    {
        return 0;
    }

    struct Tomato t;

    while (!ripeQueue.empty())
    {
        t = ripeQueue.front();
        // cout << t.h << t.w << t.day << endl;
        ripeNearTomato(t.h, t.w, t.day);

        ripeQueue.pop();
    }

    bool isNotAllRipe = false;
    int maxDay = -1;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (dayMap[i][j] > maxDay)
            {
                maxDay = dayMap[i][j];
            }

            if (dayMap[i][j] == -1)
            {
                return -1;
            }
        }
    }

    return maxDay;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int ans = -1;
    InputData(); // 입력

    // 여기서부터 작성

    cout << Solve() << "\n"; // 출력
    return 0;
}