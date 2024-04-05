#include <iostream>
using namespace std;

#define MAXN 3000001
#define MAXDKC 3001

int N, d, k, c;
int A[MAXN];

int eaten[MAXDKC];
int maxKind = 0;

void InputData()
{
    cin >> N >> d >> k >> c;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
}

int rotatedIndex(int i)
{
    return i >= N ? i % N : i;
}

int Solve(void)
{
    int sushi, frontSushi, rearSushi;
    int kind = 0;
    int coupon = c;

    for (int j = 0; j < k; j++)
    {
        sushi = A[rotatedIndex(j)];

        if (eaten[sushi] == 0)
        {
            kind++;
        }
        eaten[sushi]++;
    }

    for (int i = 0; i < N; i++)
    {

        if (eaten[coupon] == 0)
        {
            if (maxKind < kind + 1)
            {
                maxKind = kind + 1;
            }
        }
        else if (maxKind < kind)
        {
            maxKind = kind;
        }

        // reset variables
        frontSushi = A[rotatedIndex(i)];
        rearSushi = A[rotatedIndex(i + k)];
        if (frontSushi == rearSushi)
        {
            continue;
        }

        // pop
        eaten[frontSushi]--;
        if (eaten[frontSushi] == 0)
        {
            kind--;
        }

        // push
        if (eaten[rearSushi] == 0)
        {
            kind++;
        }
        eaten[rearSushi]++;
    }

    if (eaten[coupon] == 0)
    {
        if (maxKind < kind + 1)
        {
            maxKind = kind + 1;
        }
    }
    else if (maxKind < kind)
    {
        maxKind = kind;
    }

    return maxKind;
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