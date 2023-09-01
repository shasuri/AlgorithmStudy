#include <iostream>
#include <algorithm>

using namespace std;
#define MAXN ((int)1e3)

int N;//연잎수
int A[MAXN+10];//연잎좌표

int compare (const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}

int binarySearch(int i, int j)
{
    int start = A[i];
    int pass = A[j];
    int minDist = A[j] - A[i];
    int maxDist = 2 * minDist;

    int left = j + 1;
    int right = N - 1;
    int mid;

    while (left <= right)
    {
        mid = (left + right) / 2;
        if (A[j] + minDist <= A[mid])
        {
            right = mid - 1;
        }

        else
        {
            left = mid + 1;
        }
    }
    
    int minPoint;
    if (A[left] >= A[j] + minDist && A[left] <= A[j] + maxDist )
    {
        minPoint = left;
    }
    else{
        minPoint = -1;
    }
    
    left = j + 1;
    right = N - 1;

    while (left <= right)
    {
        mid = (left + right) / 2;
        if (A[j] + maxDist >= A[mid])
        {
            left = mid + 1;
        }

        else
        {
            right = mid - 1;
        }
    }
    int maxPoint;

    if (A[left - 1] >= A[j] + minDist && A[left - 1] <= A[j] + maxDist ){
        maxPoint = left - 1;
    }
    else{
        maxPoint = -1;
    }

    if (minPoint == -1 && maxPoint == -1)
    {
        return 0;
    }

    return maxPoint - minPoint + 1;
}

void InputData(){
	cin >> N;
	for (int i=0; i<N; i++){
		cin >> A[i];
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int ans = 0;
	InputData();//입력받는 부분
    qsort(A, N, sizeof(int), compare);
	//여기서부터 작성

    for (int i = 0; i < N - 2; i++)
    {
        for (int j = i + 1; j < N - 1; j++)
        {
            ans += binarySearch(i, j);
        }
        
    }
    

	cout << ans << "\n";//출력하는 부분
	return 0;
}

//m - l <= r - m <= 2 * (m - l)

//1 3 4 7 10