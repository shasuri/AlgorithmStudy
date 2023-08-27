#include <iostream>
using namespace std;
#define MAXN ((int)1e4)
int N, M;
int A[MAXN + 10];

int maxBudget = 0;
int minBudget = 100001;
int sumBudget = 0;

void InputData()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    cin >> M;
}

int getAbleBudget(int capacity)
{
    int ableBudget = 0;
    for (int i = 0; i < N; i++)
    {
        if (A[i] > capacity)
        {
            ableBudget += capacity;
        }
        else
        {
            ableBudget += A[i];
        }
    }
    return ableBudget;
}

int checkEdge()
{
    int budget;
    for (int i = 0; i < N; i++)
    {
        budget = A[i];
        sumBudget += budget;

        if (budget > maxBudget)
        {
            maxBudget = budget;
        }

        if (budget < minBudget)
        {
            minBudget = budget;
        }
    }

    if (M >= sumBudget)
    {
        return maxBudget;
    }

    if (M <= N * minBudget)
    {
        return M / N;
    }

    return -1;
}

int binarySearch(){
    const int start = minBudget;
    const int end = sumBudget;

    int left = start;
    int right = end;
    int mid;

    while(left <= right){
        mid = (left + right) / 2;

        if(getAbleBudget(mid) <= M){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    return right;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int ans = -1;

    InputData(); // 입력받는 부분

    int edgeChecked = checkEdge();

    if (edgeChecked != -1)
    {
        ans = edgeChecked;
    }
    else{
        ans = binarySearch();
    }

    cout << ans << endl; // 출력하는 부분
    return 0;
}