#include <iostream>
#include <string>
#include <queue>
using namespace std;
 
#define MAXN ((int)1e4)
int M, T, N;//배에태울수있는수, 배이동시간, 손님수
int AT[MAXN + 10];
string SIDE[MAXN + 10];
 
int arrived[MAXN + 10];
 
queue <int> que[2];
void Solve() {
    //0.초기화
    que[0] = {};
    que[1] = {};
    for (int i = 0; i < N; i++) {
        if (SIDE[i] == "left") que[0].push(i);
        else que[1].push(i);
    }
    //1.시뮬레이션
    int shipside = 0;
    int shiptime = 0;
    int arrivedcnt = 0;
    while (arrivedcnt < N) {
        if (!que[shipside].empty() && (shiptime >= AT[que[shipside].front()])) {
            int cnt = 0;
            while (!que[shipside].empty() && (cnt < M)) {
                int i = que[shipside].front();
                if (AT[i] > shiptime) break;
                que[shipside].pop();
                arrived[i] = shiptime + T;
                cnt++; arrivedcnt++;
            }
            shiptime += T;
            shipside ^= 1;
        }
        else {
            if (que[shipside].empty()) {
                shipside ^= 1;
                if (shiptime < AT[que[shipside].front()]) shiptime = AT[que[shipside].front()];
                shiptime += T;
            }
            else {
                int idx = que[shipside].front();
                if (!que[shipside ^ 1].empty() && (AT[idx] > AT[que[shipside ^ 1].front()])) {
                    idx = que[shipside ^ 1].front();
                    shipside ^= 1;
                    if (shiptime < AT[idx]) shiptime = AT[idx];
                    shiptime += T;
                }
                else {
                    shiptime = AT[idx];
                }
            }
        }
    }
}
 
void InputData() {
    cin >> M >> T >> N;
    for (int i = 0; i < N; i++) {
        cin >> AT[i] >> SIDE[i];
    }
}
void OutputData() {
    for (int i = 0; i < N; i++) {
        cout << arrived[i] << "\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    InputData();//입력받는 부분
     
    Solve();//여기서부터 작성
 
    OutputData();//출력하는 부분
    return 0;
}