#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN ((int)1e5)
int N; // 개수
int F[MAXN + 10];

void InputData()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> F[i];
    }
}

bool isCheckable(int t, int u)
{
    return u * 0.9 <= t;
}

int getMid(int t, int u)
{
    return (t + u) / 2;
}

long long Solve(void)
{
    sort(F, F + N);

    long long checkCount = 0;

    for (int i = 0; i < N; i++)
    {
        int low = 0;
        int high = i;
        int mid;
        while (low <= high)
        {
            mid = getMid(low, high);
            if (isCheckable(F[mid], F[i]))
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        checkCount += (long long)(i - low);
    }

    return checkCount;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long ans = 0;

    InputData(); // 입력받는 부분

    // 여기서부터 작성
    ans = Solve();

    cout << ans << "\n"; // 출력하는 부분
    return 0;
}
