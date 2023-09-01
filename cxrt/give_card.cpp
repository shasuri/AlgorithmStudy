#include <iostream>
using namespace std;

#define MAXN (100)
int N;
int sol[MAXN];
int sp = 0;

class CardQueue
{
private:
    const int deckFullSize, queueFullSize;

    int deck[MAXN + 1];

    int rear = 0;
    int front = 0;
    int deckSize = 0;

    void setArrangedDeck(void)
    {
        for (int i = 1; i <= deckFullSize; i++)
        {
            enqueue(i);
        }
    }

    int getCircularPoint(int point)
    {
        if (point > deckFullSize){
            // return point % queueFullSize;
            return 0;
        }
        if (point < 0)
        {
            // return (point + queueFullSize) % queueFullSize;
            return queueFullSize - 1;
        }
        
        return point;
    }

    // int getSwappedPoint(int point){

    // }

    bool isEmpty(void)
    {
        return rear == front;
    }

    bool isFull(void)
    { // rear가 front보다 반시계 1차이가 난다면,
        return (rear + 1) % queueFullSize == front;
    }

    int getSize(void)
    {
        return (rear - front) % queueFullSize;
    }

    void enqueue(int card)
    {
        if (isFull())
        {
            cout << "full ";
            return; // full
        }

        deck[rear] = card;

        rear = getCircularPoint(rear + 1);
    }

    int dequeue(void)
    {
        if (isEmpty())
        {
            cout << "empty ";
            return -1; // empty
        }

        int deq = deck[front];

        front = getCircularPoint(front + 1);
        return deq;
    }

    void swapDeck(int swapNumber)
    {
        for (int i = 0; i < swapNumber; i++)
        {
            enqueue(dequeue());
        }

        // rear = getCircularPoint_(rear + cards);
        // front = getCircularPoint_(front + cards);
    }

    int getRearNumber(void)
    {
        return deck[getCircularPoint(rear - 1)];
    }

public:
    CardQueue(int deckSize) : deckFullSize(deckSize), queueFullSize(deckSize + 1)
    {
        setArrangedDeck();
    }

    void giveCard(void)
    {
        for (int i = 0; i < N - 1; i++)
        {
            swapDeck(getRearNumber() / 2);
            sol[sp++] = dequeue();
        }

        sol[sp++] = dequeue();
    }
};

void InputData()
{
    cin >> N;
    
}

void OutputData()
{
    for (int i = 0; i < N; i++)
    {
        cout << sol[i] << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    InputData(); // 입력

    CardQueue cq(N);
    cq.giveCard();
    
    OutputData(); // 출력
    return 0;
}
