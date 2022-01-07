// [BOJ] 1로 만들기 / 실버3 / 30분
// https://www.acmicpc.net/problem/1463
// 정수 N이 주어졌을때 "2로 나누거나", "3으로 나누거나", "1을 빼거나" 해서 N을 1을 만들어 준다 할때 연산 횟수를 구하면 된다.
// DP Vector에 저장되는 값이 index+1의 수에서 1까지 걸리는 최소 연산의 수라고 생각하고, 3개의 분기로 나누어지는 재귀함수를 만들었다.
// DP에 값이 저장되어 있다면 그 값을 리턴(최솟값이므로).
// 값이 저장되어 있지 않다면, 계속 분기를 진행시키고 값이 돌아오면 3개의 분기로부터 돌아온 수들 중 최솟값에다 1을 더한뒤(이 수에서 한 번 더 연산을 한 것이므로) DP에다 저장하고 리턴한다.
// 배열로 해보니까 1000000의 길이로는 Segment Fault가 떠서 실패 했고, map은 시간초과로 실패.

#include <iostream>
#include <vector>

using namespace std;

#define MAX 999999 // 초기 수치

vector<int> DP(1000000, -1); // DP[n] = (n에서  1까지의 최소 연산 횟수라고 생각한다.)
int N;                       // 입력 값 N
int calcCount;               // N의 최소 연산 횟수

void input(void)
{
    cin >> N;
}

int branch(int n)
{
    int minDepth;
    int twoDivDepth = MAX;   // 최댓값으로 초기화
    int threeDivDepth = MAX; // 최댓값으로 초기화
    int oneSubDepth = MAX;   // 최댓값으로 초기화

    if (DP[n - 1] != -1) // 기록된 수라면
    {
        return DP[n - 1]; // 기록된 값을 그대로 리턴
    }

    if (n % 2 == 0) // 2로 나눌 수 있으면
    {
        twoDivDepth = branch(n / 2); // 2로 나눈 다음 분기
    }

    if (n % 3 == 0) // 3으로 나눌 수 있으면
    {
        threeDivDepth = branch(n / 3); // 3으로 나눈 다음 분기
    }

    oneSubDepth = branch(n - 1); // 1을 빼고 분기

    minDepth = min(min(twoDivDepth, threeDivDepth), oneSubDepth) + 1; // 3개의 분기의 값을 모두 비교한 뒤, 최솟값에 계산했다는 의미로 1을 더함

    DP[n - 1] = minDepth; // DP에 기록
    // cout << n << " : " << DP[n - 1] << endl;
    return minDepth;
}

void solve(void)
{
    for (int i = 0; i < 1000000; i++)
        DP[i] = -1; // DP를 -1로 초기화, -1이 아니라면 기록된 수로 판단.

    DP[0] = 0; // 1은 연산 횟수가 0이므로

    calcCount = branch(N); // 연산횟수에 N의 분기 값을 입력
}

void print(void)
{
    cout << calcCount;
}

int main()
{
    input();
    solve();
    print();

    return 0;
}