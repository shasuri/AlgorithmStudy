#include <iostream>
using namespace std;
#define MAXN ((int)3e4)
#define OBJ 3

int N;
int A[MAXN + 10];
int S[OBJ];
int cnt = 0;

void InputData()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
}

void OutputData()
{
    for (int i = 0; i < OBJ; i++)
    {
        cout << S[i] << " ";
    }
    cout << "\n";
}

void selectionSort(void)
{
    int maxValue, maxIndex;

    for (int i = 0; i < OBJ; i++)
    {
        maxValue = -1;
        maxIndex = -1;

        for (int j = 0; j < N; j++)
        {
            if (A[j] > maxValue)
            {
                maxValue = A[j];
                maxIndex = j;
            }
        }

        S[cnt++] = maxIndex + 1;
        A[maxIndex] = -1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    InputData(); // 입력 받는 부분

    selectionSort();

    OutputData(); // 출력 하는 부분
    return 0;
}