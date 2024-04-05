#include <iostream>
#include <cmath>

#define FOUR 4

using namespace std;
int N; // 빌딩의 층수

void InputData()
{
    cin >> N;
}

int getFourByPart(int digit, int n) // 1 1 , 6 0
{
    int fours = 0;
    int root = digit;

    if (digit > FOUR)
    {
        fours += pow(10, n);
        root -= 1;
    }

    for (int i = 0; i < n; i++)
    {
        fours += root * pow(9, n - i - 1) * pow(10, i);
    }

    return fours;
}

int Solve(void)
{
    int n = N;
    int r;
    int i = 0;
    int foursSum = 0;

    while (n > 0)
    {
        r = n % 10;
        n /= 10;

        foursSum += getFourByPart(r, i);
        i++;
    }

    return foursSum;
}

int main()
{
    int ans = -1;
    InputData(); // 입력받는 부분

    // 여기서부터 작성
    ans = N - Solve();

    cout << ans << endl; // 출력하는 부분
    return 0;
}