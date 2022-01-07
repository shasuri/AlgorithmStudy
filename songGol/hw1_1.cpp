#include <iostream>

using namespace std;

int S[] = {15, 22, 13, 27, 12, 10, 20, 25};

void myQuicksort(int arraySort[], int first, int last)
{

    if (first < last)
    {
        int pivot = arraySort[first];

        int leftMark = first + 1;
        int rightMark = last;

        do
        { // partition

            if (
                arraySort[leftMark] >= pivot &&
                arraySort[rightMark] <= pivot)
            {
                int temp = arraySort[leftMark];
                arraySort[leftMark] = arraySort[rightMark];
                arraySort[rightMark] = temp;
            }
            else
            {
                while (arraySort[leftMark] < pivot && leftMark <= last)
                {
                    leftMark += 1;
                }

                while (arraySort[rightMark] > pivot && rightMark >= first)
                {
                    rightMark -= 1;
                }
            }
        } while (leftMark < rightMark);

        int temp = arraySort[first];
        arraySort[first] = arraySort[rightMark];
        arraySort[rightMark] = temp;

        myQuicksort(arraySort, first, rightMark - 1);
        myQuicksort(arraySort, rightMark + 1, last);
    }
}

int main(void)
{
    int originSize = *(&S + 1) - S;

    myQuicksort(S, 0, originSize - 1);

    for (int i = 0; i < originSize; i++)
    {
        cout << S[i] << " ";
    }

    return 0;
}
