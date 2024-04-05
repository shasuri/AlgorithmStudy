#include <iostream>
using namespace std;
#define MAXN (20)
int N, K;         // 자연수 개수, 만들수
int A[MAXN + 10]; // 자연수 값
string msg[] = {"NO", "YES"};

void InputData()
{
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
}

bool isUsed(int index, int used)
{
    return used & (1 << index);
}

int useThisIndex(int index, int used)
{
    return used + (1 << index);
}

int dfs(int sum, int used)
{

    if (sum == K)
    {
        return 1;
    }

    if (sum > K)
    {
        return 0;
    }

    if (used == (1 << N) - 1)
    {
        return 0;
    }

    for (int i = 0; i < N; i++)
    {
        if (isUsed(i, used))
        {
            continue;
        }

        if (dfs(sum + A[i], useThisIndex(i, used)))
        {
            return 1;
        }

        used = useThisIndex(i, used);
    }

    return 0;
}

int Solve(void)
{
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += A[i];
    }

    if (sum < K)
    {
        return 0;
    }

    if (sum == K)
    {
        return 1;
    }

    return dfs(0, 0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T, ans = -1;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        InputData(); // 입력

        // 여기서부터 작성
        ans = Solve();

        cout << msg[ans] << "\n"; // 출력
    }
    return 0;
}