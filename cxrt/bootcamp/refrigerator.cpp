#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 100

int N;
int freezer = 0;

struct Matter
{
    int minTemp;
    int maxTemp;

    bool operator<(Matter m)
    {
        return minTemp < m.minTemp;
    }
} matters[MAXN];

void InputData()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> matters[i].minTemp >> matters[i].maxTemp;
    }
}

int Solve(void)
{
    sort(matters, matters + N);

    int headMinTemp = 10001;
    int tailMaxTemp = -271;
    for (int i = 0; i < N; i++)
    {
        // cout << matters[i].minTemp << endl;
        if (tailMaxTemp < matters[i].minTemp)
        {
            freezer++;
            headMinTemp = matters[i].minTemp;
            tailMaxTemp = matters[i].maxTemp;
        }
        else
        {
            if (headMinTemp < matters[i].minTemp)
            {
                headMinTemp = matters[i].minTemp;
            }

            if (tailMaxTemp > matters[i].maxTemp)
            {
                tailMaxTemp = matters[i].maxTemp;
            }
        }
    }

    return freezer;
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