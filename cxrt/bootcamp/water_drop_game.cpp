#include <iostream>
#include <algorithm>

using namespace std;

#define MAXN (100)
int A;
int N;
int W[MAXN + 10];
void InputData()
{
    cin >> A >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> W[i];
    }
}

int minSkill;

bool dfs(int ind, int power, int skill)
{
    // cout << ind << " / " << power << " / " << skill << endl;
    if (skill >= minSkill)
    {
        return false;
    }

    if (ind > N - 1)
    {
        minSkill = skill;
        if (minSkill == 0)
        {
            return true;
        }
        return false;
    }

    if (power > W[ind]) // consumable
    {
        if (dfs(ind + 1, power + W[ind], skill))
            return true;
    }
    else
    {
        if (power > 1)
        {
            if (dfs(ind, power * 2 - 1, skill + 1)) // use skiil 1
                return true;
        }

        if (dfs(ind + 1, power, skill + 1)) // use skill 2
            return true;
    }

    return false;
}

void Solve(void)
{
    sort(W, W + N);

    minSkill = N;

    dfs(0, A, 0);
}

int main()
{
    int t, T, ans = -1;
    cin >> T;
    for (t = 0; t < T; t++)
    {
        InputData(); // 입력받는 부분

        // 여기서부터 작성
        Solve();

        ans = minSkill;

        cout << "Case #" << t + 1 << ": " << ans << endl; // 출력하는 부분
    }
    return 0;
}