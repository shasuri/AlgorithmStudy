#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

#define MAXN (20)
#define INF 20000000

int N, B;
int H[MAXN + 10];

struct Cow
{
    int ind;
    int heightSum;
};

void InputData()
{
    cin >> N >> B;
    for (int i = 0; i < N; i++)
    {
        cin >> H[i];
    }
}

int Solve(void)
{
    stack<Cow> cowStk;

    cowStk.push({0, 0});
    int minDiff = INF;

    while (!cowStk.empty())
    {
        Cow curCow = cowStk.top();
        cowStk.pop();
        // cout << curCow.heightSum << endl;
        if (curCow.heightSum - B >= minDiff)
        {
            continue;
        }
        

        if (curCow.ind < N)
        {
            cowStk.push({curCow.ind + 1, curCow.heightSum + H[curCow.ind]});
            cowStk.push({curCow.ind + 1, curCow.heightSum});
        }
        else
        {
            int diff = curCow.heightSum - B;
            if (diff >= 0)
            {
                minDiff = min(minDiff, diff);
            }        

            if (minDiff == 0)
            {
                break;
            }
        }
    }

    return minDiff;
}

int main()
{
    int T, ans = -1;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        InputData(); // 입력받는 부분

        // 여기서부터 작성
        
        ans = Solve();
        cout << ans << endl;
    }
    return 0;
}
