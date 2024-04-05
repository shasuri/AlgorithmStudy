#include <iostream>

using namespace std;

#define MAXN (100)
#define DIR 4

int N; // 그림크기(정사각형)
char map[MAXN + 1][MAXN + 1];
int sol1 = 0;
int sol2 = 0;

bool visitedNormal[MAXN][MAXN];
bool visitedBlind[MAXN][MAXN];

void initVisiteds(void)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            visitedNormal[i][j] = false;
            visitedBlind[i][j] = false;
        }
    }
}

void InputData()
{
    cin >> N;
    for (int h = 0; h < N; h++)
    {
        cin >> &map[h][0];
    }
}

bool checkBoundary(int h, int w)
{
    return h > -1 && h < N &&
           w > -1 && w < N;
}

bool isBlindColor(char curColor, char nextColor)
{

    if (curColor == nextColor)
    {
        return true;
    }
    if ((curColor == 'G' || curColor == 'R') &&
        (nextColor == 'G' || nextColor == 'R'))
    {
        return true;
    }

    return false;
}

int dirH[] = {1, -1, 0, 0};
int dirW[] = {0, 0, 1, -1};
void printBlind(void)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << visitedBlind[i][j] << " ";
        }
        cout << endl;
    }
}
void floodFill(int h, int w, char color, bool forBlind)
{
    for (int i = 0; i < DIR; i++)
    {
        int newH = h + dirH[i];
        int newW = w + dirW[i];

        if (checkBoundary(newH, newW))
        {
            if (!forBlind && !visitedNormal[newH][newW] && color == map[newH][newW])
            {
                visitedNormal[newH][newW] = true;
                visitedBlind[newH][newW] = true;
                floodFill(newH, newW, map[newH][newW], false);
            }

            else if (!visitedBlind[newH][newW] && isBlindColor(color, map[newH][newW]))
            {
                // cout << h << " : " << w << endl;
                // cout << color << " : " << map[newH][newW] << endl;
                visitedBlind[newH][newW] = true;
                floodFill(newH, newW, map[newH][newW], true);
            }
        }
    }
}

void Solve(void)
{
    initVisiteds();
    for (int h = 0; h < N; h++)
    {
        for (int w = 0; w < N; w++)
        {
            if (checkBoundary(h, w))
            {
                if (!visitedNormal[h][w])
                {
                    visitedNormal[h][w] = true;
                    sol1++;
                    if (!visitedBlind[h][w])
                    {
                        visitedBlind[h][w] = true;
                        sol2++;
                    }
                    floodFill(h, w, map[h][w], false);
                    // cout << endl;
                    // printBlind();
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    InputData(); // 입력받는 부분

    // 여기서부터 작성
    Solve();

    cout << sol1 << " " << sol2 << "\n"; // 출력하는 부분
    return 0;
}