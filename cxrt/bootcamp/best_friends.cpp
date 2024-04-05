#include <iostream>
#include <string>
#include <queue>

using namespace std;

#define MAX_N (300000)
#define MAX_NAME 19

int N, K;
string name[MAX_N];

queue<int> rankQueue[MAX_NAME];

void Input_Data(void)
{
    string str;
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        cin >> name[i];
    }
}

bool checkFriend(int t, int u)
{
    return abs(t - u) <= K;
}

long long Solve(void)
{
    queue<int>* rankq;
    long long bestPairs = 0;

    for (int rank = 0; rank < N; rank++)
    {
        // cout << rankQueue[1].empty() << endl;
        rankq = &rankQueue[name[rank].length() - 2];

        while (!rankq->empty() && !checkFriend(rank, rankq->front()))
        {
            rankq->pop();
        }

        bestPairs += rankq->size();
        rankq->push(rank);
    }

    return bestPairs;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long sol = -1;

    // 입력 받는 부분
    Input_Data();

    // 여기서부터 작성
    sol = Solve();

    // 출력하는 부분
    cout << sol << '\n';

    return 0;
}