#include <iostream>
using namespace std;

#define MAXN ((int)5e3)
int N;
int A[MAXN + 10];

void InputData(){
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> A[i];
    }
}

void OutputData(){
    for (int i=0; i<N; i++){
        cout << A[i] << " ";
    }
    cout << "\n";
}

void swapByIndex(int a, int b){
    if (a == b)
    {
        return;
    }
    
    int tmp = A[a];
    A[a] = A[b];
    A[b] = tmp;
}

void divideMove(int left, int right){
    if (left >= right)
    {
        return;
    }

    int pivot = left;
    const int pivotValue = A[pivot];
    const int last = right;

    left++;
    do
    {
        while(A[left] < pivotValue && left < last)
        {
            left++;
        }
        
        while(A[right] > pivotValue) // && right > pivot)
        {
            right--;
        }
        if (left < right)
        {
            swapByIndex(left,right);
        }
        
    } while (left < right);
    
    swapByIndex(pivot, right);

    divideMove(pivot, right-1);
    divideMove(right+1, last);
}

void quickSort(void){
    divideMove(0, N-1);
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    InputData();//입력 받는 부분
    
    quickSort();
    
    OutputData();//출력 하는 부분
    return 0;
}
