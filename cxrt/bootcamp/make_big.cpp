#include <iostream>
#include <stack>
using namespace std;

#define MAXN ((int)5e5)
int N, K;
char str[MAXN + 10];

stack<int> stk;

void InputData()
{
    cin >> N >> K;
    cin >> str;
}

void recurse()
{
    if (stk.empty())
    {
        return;
    }
    int t = stk.top();
    stk.pop();
    recurse();
    cout << t;
}

void Solve(void)
{
    int i, n;
    int popCount = 0;
    int pushCount = 0;
    for (i = 0; i < N; i++)
    {
        n = str[i] - '0';
        if (popCount >= K)
        {
            break;
        }
        if (!stk.empty())
        {
            while (!stk.empty() && stk.top() < n && popCount < K)
            {
                popCount++;
                stk.pop();
            }
        }
        if (stk.size() < N - K)
        {
            stk.push(n);
        }
    }
    if (stk.size() < N - K)
    {
        for (int j = i; j < N; j++)
        {
            stk.push(str[j] - '0');
        }
    }
    recurse();
}

int main()
{
    InputData(); // 입력 받는 부분

    // 여기서부터 작성
    Solve();

    return 0;
}