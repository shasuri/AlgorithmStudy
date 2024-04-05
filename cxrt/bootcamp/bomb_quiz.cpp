#include <iostream>
using namespace std;

#define MAXN (100)
#define MEMBER 8
#define LIMIT 210

int K;             // 처음 폭탄을 가진 사람 번호
int N;             // 퀴즈 개수
int T[MAXN + 10];  // 걸린 시간
char Z[MAXN + 10]; // 정답 여부
void InputData()
{
    cin >> K;
    K--;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> T[i] >> Z[i];
    }
}

int getTurnMember(int tc)
{
    return (tc + K) % MEMBER;
}

int Solve(void)
{
    int time = 0;
    int trueCount = 0;

    for (int i = 0; i < N; i++)
    {
        time += T[i];

        if (time > LIMIT)
        {
            break;
        }
        
        switch (Z[i])
        {
        case 'T':
            trueCount++;
            break;

        case 'F':
        case 'P':
            break;
        default:
            break;
        }

    }

    return getTurnMember(trueCount) + 1;
}

int main()
{
    int ans = -1;
    InputData(); // 입력받는 부분

    // 여기서부터 작성
    ans = Solve();
    cout << ans << endl; // 출력하는 부분
    return 0;
}