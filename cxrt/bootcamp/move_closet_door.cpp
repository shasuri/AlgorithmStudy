#include <iostream>
#include <utility>
using namespace std;

#define MAXN (20)
int N;
int sl, sr;
int M;
int seq[MAXN + 10];

int minMoveCount = 401;

void InputData()
{
    cin >> N;

    cin >> sl >> sr;
    sl--;
    sr--;
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> seq[i];
        seq[i] -= 1;
    }
}

void dfs(int depth, int moveCount, pair<int, int> doors)
{
    if (moveCount >= minMoveCount)
    {
        return;
    }

    if (depth >= M)
    {
        if (moveCount < minMoveCount)
        {
            minMoveCount = moveCount;
        }

        return;
    }

    // first door moves
    if (doors.second != seq[depth])
    {
        int firstMove = abs(seq[depth] - doors.first);
        // cout << depth + 1 << " " << moveCount + firstMove << " " << seq[depth] << " " << doors.second << endl;
        dfs(depth + 1, moveCount + firstMove, make_pair(seq[depth], doors.second));
    }

    // second door moves
    if (doors.first != seq[depth])
    {
        int secondMove = abs(seq[depth] - doors.second);
        // cout << depth + 1 << " " << moveCount + secondMove << " " << doors.first << " " << seq[depth] << endl;
        dfs(depth + 1, moveCount + secondMove, make_pair(doors.first, seq[depth]));
    }
}

int Solve(void)
{

    dfs(0, 0, make_pair(sl, sr));

    return minMoveCount;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int ans = -1;

    InputData(); // 입력받는 부분

    // 여기서부터 작성
    ans = Solve();

    cout << ans << endl; // 출력하는 부분
    return 0;
}