#include <iostream>
#include <algorithm>

using namespace std;

#define MAXN (20)
#define INF 20000000

int N, B;
int H[MAXN + 10];

void InputData()
{
    cin >> N >> B;
    for (int i = 0; i < N; i++)
    {
        cin >> H[i];
    }
}

// void initVisited(bool *visited, int size)
// {
//     for (int i = 0; i < size; i++)
//     {
//         visited[i] = false;
//     }
// }

// bool visited[MAXN];

int dfs(int cow, int heightSum)
{
    heightSum += H[cow];

    if (heightSum >= B)
    {
        return heightSum - B;
    }

    int minDiff = INF;

    for (int i = cow + 1; i < N; i++)
    {
        minDiff = min(minDiff, dfs(i, heightSum));
    }

    return minDiff;
}

int Solve(void)
{
    int minDiff = INF;
    // initVisited(visited, N);
    for (int i = 0; i < N; i++)
    {
        minDiff = min(minDiff, dfs(i, 0));
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