#include <iostream>
#include <queue>
using namespace std;

#define MAXN (100)
int W, H;                       // 지도의 가로 세로 크기
char map[MAXN + 10][MAXN + 10]; // 지도 정보('1':저글링, '0':빈곳)
int sw, sh;                     // 시작위치 가로 세로 좌표

struct Zergling
{
    int h;
    int w;
    int irradiated;
};

queue<Zergling> irradQueue;

void InputData()
{
    cin >> W >> H;
    for (int i = 0; i < H; i++)
    {
        cin >> &map[i][0];
    }
    cin >> sw >> sh;

    sh--;
    sw--;
}

int dirH[] = {1, -1, 0, 0};
int dirW[] = {0, 0, 1, -1};

bool isAvailable(int h, int w)
{
    return h > -1 && h < H &&
           w > -1 && w < W &&
           map[h][w] == '1'; // h,w is not ground and visited zergling
}

void visitHere(int h, int w)
{
    map[h][w] = '2';
}

int countSurvived(void)
{
    int s = 0;
    for (int h = 0; h < H; h++)
    {
        for (int w = 0; w < W; w++)
        {
            if (map[h][w] == '1')
            {
                s++;
            }
        }
    }

    return s;
}

void Solve(void)
{
    int allIrradiate = 0;

    visitHere(sh, sw);
    irradQueue.push({sh, sw, 0});
    Zergling z;
    while (!irradQueue.empty())
    {
        z = irradQueue.front();

        for (int i = 0; i < 4; i++)
        {
            int nh = z.h + dirH[i];
            int nw = z.w + dirW[i];

            if (isAvailable(nh, nw))
            {
                visitHere(nh, nw);
                irradQueue.push({nh, nw, z.irradiated + 1});
            }
        }

        irradQueue.pop();
    }

    allIrradiate = z.irradiated + 3;

    cout << allIrradiate << '\n' << countSurvived();
}

int main()
{
    InputData(); // 입력 받는 부분

    Solve();

    return 0;
}