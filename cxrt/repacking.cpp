#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN ((int)5e3)
int N;
int A[MAXN];
int space[MAXN];

int accSum = 0;

void swapByIndex(int a, int b)
{
    if (a == b)
    {
        return;
    }

    int tmp = A[a];
    A[a] = A[b];
    A[b] = tmp;
}

void merge(int left, int mid, int right)
{
    int sum = 0;

    int l = left;
    int m = mid;
    int r = right;

    int sp = 0;

    while (l <= mid && r <= right)
    {
        if (A[l] > A[r])
        {
            sum += A[r];
            space[sp++] = A[r++];
        }
        else
        {
            sum += A[l];
            space[sp++] = A[l++];
        }
    }

    if (l > mid)
    {
        for (int i = r; i <= right; i++)
        {
            sum += A[i];
            space[sp++] = A[i++];
        }
    }
    else
    {
        for (int i = l; i <= mid; i++)
        {
            sum += A[i];
            space[sp++] = A[i++];
        }
    }

    accSum += sum;
}
void mergeSort(int left, int right)
{
    int mid = (left + right) / 2;

    if (left < right)
    {
        mergeSort(left, mid);
        mergeSort(mid + 1, right);
        merge(left, mid, right);
    }
}

void InputData()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
}
int main()
{
    int ans;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    InputData(); // 입력

    mergeSort(0, N - 1);
    // 여기서부터 작성

    cout << accSum << "\n";
    return 0;
}