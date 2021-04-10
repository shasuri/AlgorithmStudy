#include <iostream>

using namespace std;

int S[] = {15,22,13,27,12,10,20,25};
// int S[] = {5,8,7,4,1,2,9,3,6};

void myQuicksort(int arraySort[], int first, int last){
    // int arrSize = *(&arraySort+1) - arraySort;

    if (first < last) {
        int pivot = arraySort[first];

        int leftMark = first+1;
        int rightMark = last;

        do{ // partition
            // bool leftStop = false;
            // bool rightStop = false;

            if(
                arraySort[leftMark] >= pivot &&
                arraySort[rightMark] <= pivot
            )
            {
                int temp = arraySort[leftMark];
                arraySort[leftMark] = arraySort[rightMark];
                arraySort[rightMark] = temp;
            }
            else{
                while(arraySort[leftMark] < pivot && leftMark <= last){
                    leftMark += 1;
                }

                while(arraySort[rightMark] > pivot && rightMark >= first){
                    rightMark -= 1;
                }
            }
        }while(leftMark < rightMark);

        int temp = arraySort[first];
        arraySort[first] = arraySort[rightMark];
        arraySort[rightMark] = temp;

        myQuicksort(arraySort,first,rightMark-1);
        myQuicksort(arraySort,rightMark+1,last);   
    }
    // return arraySort;
}

int main(void){
    int originSize = *(&S+1) - S;
    
    myQuicksort(S,0,originSize-1);

    for(int i = 0; i < originSize; i++){
        cout << S[i] << " ";
    }

    return 0;
}
