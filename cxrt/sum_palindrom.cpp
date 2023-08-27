#include <iostream>
using namespace std;

int M; // 정수
int divided[7];
int mCount;
const int divider = 10;

void InputData()
{
    cin >> M;
}
void OutputData(bool ans)
{
    if (ans == 0)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
}

void divideM(void)
{
    while (M != 0)
    {
        divided[mCount++] = M % divider;
        M /= divider;
    }
}
bool isPalindrom(void)
{
    const int halfCount = (mCount - 1) / 2 + 1;

    bool isPureEleven = true;
    bool isNotOverTen = true;

    int palinSum;

    for (int i = 0; i < halfCount; i++){
        palinSum = divided[i] + divided[mCount - 1 - i];

        if (palinSum > 9)
        {
            isNotOverTen = false;
        }

        if (palinSum != 11 && palinSum != 0)
        {
            isPureEleven = false;
        }
        // cout << divided[i] << " + " << divided[mCount - 1 - i] << endl;
    }

    if(isPureEleven || isNotOverTen){
        return true;
    }

    return false;
}

int main()
{
    int N, i;
    bool ans;
    cin >> N;
    for (i = 0; i < N; i++)
    {
        mCount = 0;
        InputData(); // 입력
        
        divideM();
        ans = isPalindrom();

        OutputData(ans); // 출력
    }
    return 0;
}