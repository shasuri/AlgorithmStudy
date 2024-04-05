#include <iostream>
using namespace std;

#define MAXN ((int)1e3)
#define MAX_NUM 1000001

int N;            // 정수개수
int A[MAXN + 10]; // 입력 정수
void InputData()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
}

int getModSum(int n)
{

    int modSum = 0;
    while (n > 0)
    {
        modSum += n % 10;
        n /= 10;
    }

    return modSum;
}

int getModNum(int modSum)
{
    while (modSum > 9)
    {
        modSum = getModSum(modSum);
    }

    return modSum;
}

int Solve(void)
{
    int maxModNum = -1;
    int minNum = MAX_NUM;

    for (int i = 0; i < N; i++)
    {
        int modNum = getModNum(A[i]);

        if (modNum > maxModNum ||
            (modNum == maxModNum && minNum > A[i]))
        {
            maxModNum = modNum;
            minNum = A[i];
        }
    }

    return minNum;
}

int main()
{
    int ans = -1;
    InputData(); // 입력 받는 부분

    ans = Solve();

    cout << ans << endl; // 출력하는 부분
    return 0;
}