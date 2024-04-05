#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

#define MAXN (100)
#define INF 1000000

int L;                // 정비를 받지 않고 갈수있는 최대거리
int N;                // 정비소 개수
int dist[MAXN + 10];  // 정비소사이거리
int times[MAXN + 10]; // 정비시간
int path[MAXN + 10];
int visited[MAXN + 10];

int minTimeStopped = 0;

struct Status
{
    int loc;
    int time;
    int stopped = 0;
    Status() {}
    Status(int loc_, int time_, int stopped_) : loc(loc_), time(time_), stopped(stopped_) {}
};

queue<Status> dst;

void InputData()
{
    cin >> L;
    cin >> N;
    for (int i = 0; i <= N; i++)
    {
        cin >> dist[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> times[i];
    }
}

bool isGoalIn(int loc)
{
    return loc > N;
}

void Solve(void)
{
    dst.push({-1, 0, 0});

    Status s;

    while (!dst.empty())
    {
        s = dst.front();
        dst.pop();
        // cout << s.loc << " / " << s.restDist << " / " << s.stopped << " / " << s.time << endl;
        int newLoc = s.loc + 1;
        int newDist = L - dist[newLoc];

        while (newDist >= 0)
        {
            if (s.time + times[newLoc] < visited[newLoc])
            {
                // cout << newLoc << " : " << s.time << " : " << newDist << endl;
                visited[newLoc] = s.time + times[newLoc];
                path[newLoc] = s.loc;

                if (newLoc >= N)
                {
                    minTimeStopped = s.stopped;
                    break;
                }

                dst.push({newLoc, s.time + times[newLoc], s.stopped + 1});
            }

            newLoc++;
            newDist -= dist[newLoc];
        }
    }
}

void tracePath(int p)
{
    if (path[p] == -1)
    {
        return;
    }
    tracePath(path[p]);
    cout << path[p] + 1 << " ";
}

int main()
{
    InputData(); // 입력 받는 부분

    for (int i = 0; i <= N; i++)
    {
        visited[i] = INF;
    }

    for (int i = 0; i <= N; i++)
    {
        path[i] = -1;
    }

    // 여기서부터 작성
    Solve();

    if (visited[N] == 0){
       cout << 0 << endl;
    }
    else{
        cout << visited[N] << endl;
        cout << minTimeStopped << endl;
        tracePath(N);
        cout << endl;
    }

    return 0;
}