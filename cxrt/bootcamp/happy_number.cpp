#include <iostream>
using namespace std;
#define MAXN ((int)1e3)
int N;
bool used[MAXN + 10];
void InputData()
{
    cin >> N;
}

int square(int n)
{
    return n * n;
}

int getSquareSum(int n)
{
    if (n == 1)
    {
        return 1;
    }

    int s = 0;
    while (n > 0)
    {
        s += square(n % 10);
        n /= 10;
    }

    return s;
}

bool dfs(int n)
{
    if (used[n] == true)
    {
        return false;
    }
    used[n] = true;

    int squareSum = getSquareSum(n);

    if (squareSum == 1)
    {
        return true;
    }
    else
    {
        return dfs(squareSum);
    }
}

int Solve(void)
{
    for (int i = 0; i < N; i++)
    {
        if (dfs(N - i))
        {
            return N - i;
        }
    }
}

int main()
{
    int ans = -1;
    InputData(); // 입력받는 부분

    ans =  Solve();

    cout << ans << endl; // 출력하는 부분
    return 0;
}
