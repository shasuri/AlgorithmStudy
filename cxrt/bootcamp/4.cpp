#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN ((int)2e3)
#define MAXC ((int)1e4)
#define MAXM ((int)1e4)
int N, C; // 마을수, 트럭용량
int M;    // 박스 정보 개수
struct DATA
{
    int s, e, cnt; // 시작마을, 도착마을, 박스 개수
};
DATA A[MAXM + 10];    // 박스 정보
int truck[MAXN + 10]; // 각 마을에서 트럭 상태
void InputData()
{
    cin >> N >> C;
    cin >> M;
    for (int i = 0; i < M; i++)
    { // 박스 정보 인덱스
        cin >> A[i].s >> A[i].e >> A[i].cnt;
    }
}
bool comp(DATA a, DATA b)
{
    return a.e < b.e;
}
int Solve()
{
    int sum = 0;
    // 1.도착마을 기준 오름차순 정렬
    sort(A, A + M, comp);
    // 2.박스정보 분석하며 보내기
    for (int i = 0; i < M; i++)
    { // 박스 정보 인덱스
        int maxv = 0;
        // 1.s~(e-1) truck 값 중에 최대값 구하기
        for (int k = A[i].s; k < A[i].e; k++)
        {
            if (maxv < truck[k])
                maxv = truck[k];
        }
        maxv = C - maxv; // 싣을 수 있는 최대값 = 트럭 총 용량 - 이미 싣어있는 최대값
        // 2.i번째 박스 개수 랑 비교해서 maxv 수정(이 값이 트럭에 싣으려는 양)
        if (maxv > A[i].cnt)
            maxv = A[i].cnt;
        // 3.정보 갱신
        sum += maxv; // 배송한 박스 개수 누적 더하기
        for (int k = A[i].s; k < A[i].e; k++)
        {
            truck[k] += maxv;
        }
    }
    return sum;
}
int main()
{
    InputData();
    int ans = Solve();
    cout << ans << endl;
    return 0;
}