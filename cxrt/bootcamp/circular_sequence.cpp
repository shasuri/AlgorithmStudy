#include <iostream>
using namespace std;

int N, P;
int nRest;

int R[1000];

void InputData()
{
    cin >> N >> P;
}

int getRest(int s)
{
    if (s == 0)
    {
        return 1;
    }

    if (R[s] != -1)
    {
        return R[s];
    }

    if (s % 2 == 0)
    {
        R[s] = (getRest(s / 2) * getRest(s / 2)) % P;
    }
    else
    {
        R[s] = (getRest(s / 2 + 1) * getRest(s / 2)) % P;
    }
    return R[s];
}

void initRests(void)
{
    for (int i = 0; i < 1000; i++)
    {
        R[i] = -1;
    }
}

int Solve(void)
{

    nRest = N % P;
    R[1] = nRest; // 5
    R[2] = (nRest * nRest) % P; // 25
    R[3] = (R[2] * nRest) % P; // 1
    if (R[3] == 0)
    {
        return 1;
    }
    
    int nextRest = R[3];

    int circularCount = 1;
    int squares = 4;

    while (R[2] != nextRest)
    {
        circularCount++;
        nextRest = getRest(squares);
        squares++;
    }

    return circularCount;
}

int main()
{
    int ans = -1;

    InputData(); // 입력받는 부분

    // 여기서부터 작성
    initRests();
    ans = Solve();

    cout << ans << endl; // 출력하는 부분
    return 0;
}