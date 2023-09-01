#include <iostream>
using namespace std;
#define MAX ((int)2e5)
int N;
int A[MAX+10];
int T;
int B[MAX+10];
// int dp[MAXN];
void InputData(){
	cin >> N;
	for(int i=0 ; i<N ; i++){
		cin >> A[i];
	}
	cin >> T;
	for(int i=0 ; i<T ; i++){
		cin >> B[i];
	}
}

// 0 0 1 1 1 9 9
int countFromStart(int start, int target){
    int cnt = 0;
    for (int i = start; i < N; i++)
    {
        if (A[i] != target)
        {
            break;
        }
        cnt++;
    }

    return cnt;
}

int searchStart(int target){
    // cout << target << endl;
    int left = 0;
    int right = N - 1;
    int mid = right / 2;

    while (left <= right)
    {
        if (A[mid] >= target)
        {
            right = mid - 1;
            mid = (right + left) / 2;
        }

        if (A[mid] < target)
        {
            left = mid + 1;
            mid = (right + left) / 2;
        }
        // cout << mid << ": " << A[mid] << endl;
    }
    return left;
}

int searchEnd(int target){
    // cout << target << endl;
    int left = 0;
    int right = N - 1;
    int mid = right / 2;

    while (left <= right)
    {
        if (A[mid] > target)
        {
            right = mid - 1;
            mid = (right + left) / 2;
        }

        if (A[mid] <= target)
        {
            left = mid + 1;
            mid = (right + left) / 2;
        }
        // cout << mid << ": " << A[mid] << endl;
    }
    // 0 0 1 1 1 9 9
    return right;
}


void OutputData(){
	for(int i=0; i<T ; i++){
		cout << searchEnd(B[i]) - searchStart(B[i]) << " ";
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	InputData();// 입력받는 부분

	OutputData();// 출력하는 부분
	return 0;
}