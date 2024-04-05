#include <iostream>
#include <queue>

using namespace std;

#define MAXN (100)
#define DIR 8

int N;
char map[MAXN+1][MAXN+1];
bool visited[MAXN+1][MAXN+1];

int lake = 0;

struct Pixel
{
    int h;
    int w;
};

queue<Pixel> pixelQueue;

int dirH[] = {1, -1, 0, 0, -1, 1, 1, -1};
int dirW[] = {0, 0, -1, 1, 1, 1, -1, -1};

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

bool isValidLakePixel(Pixel p)
{
    return p.h > -1 && p.h < N &&
           p.w > -1 && p.w < N &&
           map[p.h][p.w] == '1' &&
           !visited[p.h][p.w];
}

void visitThisPixel(Pixel p)
{
    visited[p.h][p.w] = true;
}

void bfs(Pixel startPixel)
{
    visitThisPixel(startPixel);
    pixelQueue.push(startPixel);

    Pixel curPixel, nextPixel;

    while (!pixelQueue.empty())
    {
        curPixel = pixelQueue.front();

        for (int i = 0; i < DIR; i++)
        {
            nextPixel.h = curPixel.h + dirH[i];
            nextPixel.w = curPixel.w + dirW[i];

            if (isValidLakePixel(nextPixel))
            {
                visitThisPixel(nextPixel);
                pixelQueue.push(nextPixel);
            }
        }

        pixelQueue.pop();
    }
}

void Solve(void)
{
    initVisited();
    Pixel pixel;

    for (int h = 0; h < N; h++)
    {
        for (int w = 0; w < N; w++)
        {
            pixel.h = h;
            pixel.w = w;

            if (isValidLakePixel(pixel))
            {
                lake++;
                bfs(pixel);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    InputData(); // 입력

    // 여기서부터 작성
    Solve();
    cout << lake << "\n"; // 출력
    return 0;
}