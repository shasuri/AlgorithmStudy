#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int N;              // 마을 수
int A[100000 + 10]; // 마을 위치
int B[100000 + 10]; // 잡힌 물고기 양

int fishSum = 0;
int maxFish = 0;

void InputData()
{
    // scanf("%d", &N);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        // scanf("%d %d", &A[i], &B[i]);
        cin >> A[i] >> B[i];
        fishSum += B[i];
        maxFish = max(maxFish,B[i]);
    }
}

int getMid(int l, int h)
{
    return (l + h) / 2;
}

bool isFeedable(int children){
    long long restFish = 0;
    int tax;
    for (int i = 0; i < N - 1; i++)
    {
        restFish += B[i] - children;
        tax = A[i+1] - A[i];
        if (restFish < 0)
        {
            restFish -= (long long)tax;
        }
        else{
            restFish -= (long long)tax;
            if (restFish < 0)
            {
                restFish = 0;
            }
        }
    }

    long long restFishInLastVil = B[N-1] - children;
    return restFishInLastVil + restFish >= 0;
    
}

int Solve(void)
{
    int low = 0;
    int high = maxFish;
    int mid;
    int sol;

    while (low <= high)
    {
        mid = getMid(low, high);
        if (isFeedable(mid))
        {
            low = mid + 1;
            sol = mid;
        }
        else
        {
            high = mid - 1;
        }
    }

    return high;
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