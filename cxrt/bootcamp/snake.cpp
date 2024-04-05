#include <iostream>
#include <queue>

using namespace std;

#define MAXN (100)
#define MAXL (100)
#define DIR 4

const char SPACE = '.';
const char SNAKE = 'O';
const char FRUIT = 'F';

const char RIGHT = 'D';
const char LEFT = 'L';

const int DIR_R[DIR] = {0, 1, 0, -1};
const int DIR_C[DIR] = {1, 0, -1, 0}; // R D L U

int N;

char map[MAXN][MAXN];

int K;

int L;
int X[MAXN + 10];
char CMD[MAXN + 10];

struct Point
{
    int r;
    int c;
};

queue<Point> snake;
void printMap(void);

void initMap(void)
{
    for (int r = 0; r < N; r++)
    {
        for (int c = 0; c < N; c++)
        {
            map[r][c] = SPACE;
        }
    }
}

void InputData()
{
    int fruitR, fruitC;
    cin >> N;
    initMap();

    cin >> K;
    for (int i = 0; i < K; i++)
    {
        cin >> fruitR >> fruitC;

        fruitR--;
        fruitC--;

        map[fruitR][fruitC] = FRUIT;
    }

    cin >> L;
    for (int i = 0; i < L; i++)
    {
        cin >> X[i] >> CMD[i];
    }
}

bool isInBoundary(Point p)
{
    return p.r > -1 && p.r < N &&
           p.c > -1 && p.c < N;
}

int Solve(void)
{
    int survivedTime = 0;

    snake.push({0, 0}); // head as tail
    map[0][0] = SNAKE;

    int curDir = 0; // Init direction is right.
                    // R : 0, D : 1, L : 2, U : 3

    for (int i = 0; i <= L; i++)
    {
        int xtime = (i == L) ? (MAXN * MAXL) : X[i];
        // Continue after all command ends

        while (survivedTime < xtime)
        {
            // printMap();
            survivedTime++;

            Point tail = snake.front();
            Point head = snake.back();

            Point nHead = {head.r + DIR_R[curDir],
                           head.c + DIR_C[curDir]};

            if (!isInBoundary(nHead))
            {
                // Game over
                return survivedTime;
            }

            if (map[nHead.r][nHead.c] == SNAKE)
            {
                // Game over
                return survivedTime;
            }

            if (map[nHead.r][nHead.c] != FRUIT)
            {
                map[tail.r][tail.c] = SPACE;
                snake.pop();
            }

            snake.push(nHead);
            map[nHead.r][nHead.c] = SNAKE;
        }

        if (CMD[i] == RIGHT)
        {
            curDir = (curDir + 1) % DIR;
        }
        if (CMD[i] == LEFT)
        {
            curDir = ((curDir - 1) + DIR) % DIR;
        }
    }

    // return survivedTime;
}

void printMap(void)
{
    for (int r = 0; r < N; r++)
    {
        for (int c = 0; c < N; c++)
        {
            cout << map[r][c];
        }
        cout << endl;
    }
    cout << endl;
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