#include <string>
#include <vector>

using namespace std;

const int LIMIT = 8;
const int MAX_GOAL = 32001;
int dp[MAX_GOAL];

int goal;
int n;

int solution(int N, int number)
{
    int answer = 0;
    goal = number;
    n = N;

    dfs(0, 0);

    return answer;
}

bool dfs(int present, int depth, int prevCalc)
{
    if (depth > LIMIT)
    {
        return;
    }

    if (goal == present)
    {
        /* code */
    }

    if (goal > present)
    {
        dfs(present + n, depth + 1, 0);
        dfs(present + 1, depth + 2, 1);
        dfs(present * n, depth + 1, 2);
    }

    if (goal < present)
    {
        dfs(present - n, depth + 1, 3);
        dfs(present - 1, depth + 2, 4);
        dfs(present / n, depth + 1, 5);
    }
}