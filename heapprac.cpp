#include <iostream>

int heap[100];
int heapSize = 0;

void heapInit(void)
{
    heapSize = 0;
}

int heapPush(int value)
{
    if (heapSize + 1 > 100)
    {
        return 0;
    }

    heap[heapSize] = value;

    int current = heapSize;
    int parent = (current - 1) / 2;

    while (current > 0 && heap[current] < heap[parent])
    {
        int temp = heap[parent];
        heap[parent] = heap[current];
        heap[current] = temp;

        current = parent;
        parent = (current - 1) / 2;
    }

    heapSize += 1;
    return 1;
}

int heapPop(){
    if(heapSize <= 0){
        return 0;
    }

    int value = heap[0];
    heapSize = heapSize-1;
    heap[0] = heap[heapSize];

    int current = 0;

    while(current*2+1 < heapSize){
        int child;
        if(current*2+2 == heapSize){
            child = current*2 + 1;
        }
    }
}