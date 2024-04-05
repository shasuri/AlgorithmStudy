#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_N (100000)
#define MAX_K 10000

int N, M;
int need[MAX_N];
int needSum = 0;
int maxK = 0;

void Input_Data(void)
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> need[i];
        needSum += need[i];
        maxK = max(maxK, need[i]);
    }
}

int getMid(int t, int u)
{
    return (t + u) / 2;
}

int spendMoney(int k)
{
    int m = 0;
    int pocket = 0;
    int expose = 0;

    for (int i = 0; i < N; i++)
    {
        if (need[i] > pocket)
        {
            pocket = 0; // store all money in pocket

            pocket += k;
            m++;
            // expose = (need[i] - 1) / k + 1;
            // pocket += expose * k;
            // m += expose;

            // while (need[i] > pocket)
            // {
            //     pocket += k;
            //     m++;
            // }
        }

        pocket -= need[i];

        if (m > M)
        {
            return m;
        }
    }

    return m;
}

int Solve(void)
{
    int low = maxK;
    int high = needSum;
    int mid;

    int spendResult = -1;

    while (low <= high)
    {
        mid = getMid(low, high);
        // cout << mid << endl;
        spendResult = spendMoney(mid);

        if (spendResult > M)
        {
            low = mid + 1;
        }

        if (spendResult <= M)
        {
            high = mid - 1;
        }
    }

    // mid = k
    return low;
}

int main(void)
{
    ios_base::sync_with_stdio();
    cin.tie(nullptr);
    cout.tie(nullptr);
    int sol = -1;

    // 입력 받는 부분
    Input_Data();

    // 여기서부터 작성
    sol = Solve();
    // 출력하는 부분
    cout << sol << '\n';

    return 0;
}