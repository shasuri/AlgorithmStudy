#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

#define MAXN (50)
int N, M, K; // 철도역수, 철도수, 추가로 연결시킬수있는 철도수

bool railMap[MAXN][MAXN];
bool visited[MAXN];
int stationGroup[MAXN];

void InputData()
{
    cin >> N >> M >> K;
    int src, dst;
    for (int i = 0; i < M; i++)
    {
        cin >> src >> dst;

        src--;
        dst--;

        railMap[src][dst] = true;
        railMap[dst][src] = true;
    }
}

bool isCountable(int src, int dst)
{
    return src != dst &&
           railMap[src][dst] &&
           !visited[dst];
}

int countConnectedStation(int start)
{
    queue<int> connectQueue;

    connectQueue.push(start);
    visited[start] = true;

    int connectCount = 1;

    while (!connectQueue.empty())
    {
        int src = connectQueue.front();
        connectQueue.pop();

        for (int dst = 0; dst < N; dst++)
        {
            if (isCountable(src, dst))
            {
                // cout << src << " - " << dst << endl;
                connectCount++;
                visited[dst] = true;
                connectQueue.push(dst);
            }
        }
    }
    return connectCount;
}

bool intDescend(int t, int u)
{
    return t > u;
}

int Solve(void)
{
    int groupCount = 0;

    for (int i = 0; i < N; i++)
    {
        if (!visited[i])
        {
            stationGroup[groupCount++] = countConnectedStation(i);
        }
        
    }

    sort(stationGroup, stationGroup + groupCount, intDescend);

    int unifiedStationSum = 0;
    for (int i = 0; i < K+1; i++)
    {
        unifiedStationSum += stationGroup[i];
    }
    
    return unifiedStationSum;
}

int main()
{
    int ans = -1;
    InputData(); // 입력받는 부분

    // 여기서부터 작성
    ans = Solve();

    cout << ans << "\n"; // 출력하는 부분
    return 0;
}
