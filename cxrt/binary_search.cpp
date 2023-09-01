#include <iostream>
using namespace std;
#define MAXN ((int)5e4)
#define MAXT ((int)1e4)
int N;
int A[MAXN];
int T;
int B[MAXT];
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

int binarySearch(int target){
    int left = 0;
    int right = N - 1;
    int mid = right / 2;

    while (left < right)
    {
        if (A[mid] > target)
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
        if (A[mid] == target)
        {
            return mid + 1;
        }
    }
    return 0;
}

void OutputData(){
	for(int i=0; i<T ; i++){
		cout << binarySearch(B[i]) << "\n";
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