#include <iostream>
#include <queue>
#include <vector>

using namespace std;
#define MAXN (100)
int N, M;                  // 지하철역수, 목적역
int S[MAXN + 2][MAXN + 2]; //[s][e]=시간
int minDist[MAXN];

vector<int> vp;

struct station
{
    int id;
    int spent;
    vector<int> path;
};

queue<station> dst;

void InputData()
{
    cin >> N >> M;
    for (int s = 0; s < N; s++)
    {
        for (int e = 0; e < N; e++)
        {
            cin >> S[s][e];
        }
    }
}

void initMinDist(void)
{
    for (int i = 0; i < MAXN; i++)
    {
        minDist[i] = 101;
    }
}

void Solve()
{
    initMinDist();
    struct station s;
    dst.push({0, 0, {0}});

    while (!dst.empty())
    {
        s = dst.front();
        for (int i = 0; i < N; i++)
        {
            if (i == s.id) // src and dst are same
            {
                continue;
            }

            if (minDist[i] > s.spent + S[s.id][i])
            {
                minDist[i] = s.spent + S[s.id][i];

                vector<int> v = s.path;
                v.push_back(i);

                if (i == M - 1)
                {
                    vp = v;
                    continue;
                }

                dst.push({i, s.spent + S[s.id][i], v});
            }
        }
        dst.pop();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    InputData(); // 입력
    Solve();
    // 여기서부터 작성

    cout << minDist[M - 1] << endl;
    for (vector<int>::iterator it = vp.begin(); it != vp.end(); it++)
    {
        cout << *it + 1 << " ";
    }
    cout << endl;

    return 0;
}