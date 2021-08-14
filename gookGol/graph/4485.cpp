#include <iostream>
#include <vector>
#include <queue>

#define MAX 125
#define INF 140626 // 9*125*125 + 1

using namespace std;

int cave[MAX][MAX];
int dist[MAX][MAX];

void input(void);
void initDist(void);
void solve(int);

struct node // 동굴 좌표의 값을 담을 구조체
{
    int indexI;
    int indexJ;
    int value;
};

struct cmp // pq를 오름차순으로
{
    bool operator()(node t, node u)
    {
        return t.value > u.value;
    }
};

void input(void)
{
    int n;
    int m = 1; // Problem count

    while (true) // testcase 돌리기
    {
        cin >> n; // 동굴의 크기
        if (n == 0)
            break;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // cout << i << "," << j << endl;
                cin >> cave[i][j]; // 도둑루피 배치 표시
            }
        }
        initDist(); // 최단거리배열 초기화
        solve(n);   // 거리배열 업데이트, djikstra

        cout << "Problem " << m << ": " << dist[n - 1][n - 1] + cave[0][0] << endl; // 출력

        m++;
    }
}

void initDist(void)
{
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
            dist[i][j] = INF; // 거리배열에 이동량 최댓값 입력
    }
    dist[0][0] = 0; // 시작점은 0으로
}

void solve(int caveSize)
{
    int move[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}; // 이동방향을 담는 배열, 각각, 하, 우, 상, 좌

    priority_queue<node, vector<node>, cmp> pq;

    pq.push({0, 0, 0}); // 시작점 정보 push

    while (!pq.empty())
    {

        node loc = pq.top(); // pq의 최상위 queue를 빼냄, location
        int li = loc.indexI; // location index i
        int lj = loc.indexJ; // location index j

        // if (loc.value < INF)
        //     cout << "[" << li << "][" << lj << "] : " << loc.value << endl;
        // pq.top 정보 출력

        pq.pop();

        if (dist[li][lj] >= loc.value) // top queue의 value와 최단 거리 정보를 비교, value가 작으면 업데이트 시작
        {
            for (int k = 0; k < 4; k++) // 상하좌우 방향으로 업데이트
            {
                int ni = li + move[k][0]; // new index i
                int nj = lj + move[k][1]; // new index j

                if ((ni < caveSize && nj < caveSize) && (ni > -1 && nj > -1)) // ni, nj가 배열밖을 참조하지 못하도록 방지
                {
                    if (dist[ni][nj] > dist[li][lj] + cave[ni][nj]) // 현위치 최단거리와 다음위치 이동값의 합이 다음 위치 최단거리보다 작으면,
                    {
                        dist[ni][nj] = dist[li][lj] + cave[ni][nj]; // 최단거리배열 업데이트
                        pq.push({ni, nj, dist[ni][nj]});            // 다음위치정보를 push
                    }
                }
            }
        }
    }
}

int main(void)
{
    input();

    return 0;
}
