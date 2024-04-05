#include <iostream>
#include <algorithm>

using namespace std;

#define TEN 10

int N;
int W[20];
void InputData()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> W[i];
    }
}

bool isLoadable(int curWeight, int loadingCow)
{
    while (curWeight != 0 && loadingCow != 0)
    {
        if (curWeight % TEN + loadingCow % TEN >= TEN)
        {
            return false;
        }
        curWeight /= TEN;
        loadingCow /= TEN;
    }
 
    return true;
}

int maxLoaded = 0;

bool dfs(int cowIndex, int curWeight, int cowLoaded)
{
    if (cowIndex >= N)
    {
        maxLoaded = max(maxLoaded, cowLoaded);

        if (maxLoaded == N) // All loaded
        {
            return true;
        }
    }
    else
    {
        if (isLoadable(curWeight, W[cowIndex]) &&
            dfs(cowIndex + 1, curWeight + W[cowIndex], cowLoaded + 1))
        {
            return true;
        }
        if (dfs(cowIndex + 1, curWeight, cowLoaded))
        {
            return true;
        }
    }
    return false;
}

void Solve(void)
{
    dfs(0, 0, 0);
}

int main()
{
    int ans = -1;

    InputData(); // 입력받는 부분

    // 여기서부터 작성
    Solve();
    
    ans = maxLoaded;

    cout << ans << endl; // 출력하는 부분
    return 0;
}