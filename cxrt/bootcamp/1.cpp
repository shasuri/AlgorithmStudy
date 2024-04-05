#include <iostream>
using namespace std;
int visit[1001];
int N, P;
void InputData()
{
    cin >> N >> P;
}

int Solve(void)
{
    int init = N * N % P;

    int cnt = 0;

    int i = init;

    while (!visit[i])
    {
        visit[i] = cnt;
        cnt++;

        i = i * N % P;
    }

    return cnt - visit[i];
}

int main()
{
    int ans = -1;
    InputData(); // 입력받는 부분

    // 여기서부터 작성
    ans = Solve();

    cout << ans << endl; // 출력하는 부분
    return 0;
}