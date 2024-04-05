#include <iostream>
using namespace std;

#define MAXN 3000000
#define MAXDKC 3001

int N, d, k, c;
int A[MAXN];

void InputData()
{
    cin >> N >> d >> k >> c;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
}

class SushiQueue
{
private:
    int front = 0;
    int rear = 0;
    int sushies[MAXDKC];
    int maxSize;

    int maxKind = 0;
    int kind = 0;
    int eaten[MAXDKC];
    int coupon = 0;

    int checkCoupon(void)
    {
        if (eaten[coupon] == 0)
        {
            return kind + 1;
        }
        return kind;
    }

public:
    SushiQueue(int s_, int c_) : maxSize(s_), coupon(c_)
    {
        for (int i = 0; i < MAXDKC; i++)
        {
            eaten[i] = 0;
            sushies[i] = 0;
        }
    }

    bool isFull(void)
    {
        return (rear + 1) % (maxSize + 1) == front;
    }

    bool isEmpty(void)
    {
        return front == rear;
    }

    void push(int sushi)
    {
        if (isFull())
        {
            return;
        }

        sushies[rear++] = sushi;
        rear %= maxSize + 1;

        if (eaten[sushi] == 0)
        {
            kind++;
        }
        eaten[sushi]++;
    }

    int pop(void)
    {
        if (isEmpty())
        {
            return -1;
        }

        int sushi = sushies[front++];
        front %= (maxSize + 1);

        eaten[sushi]--;
        if (eaten[sushi] == 0)
        {
            kind--;
        }

        return sushi;
    }

    int getFrontSushi(void)
    {
        return sushies[front];
    }

    int getRearSushi(void)
    {
        return sushies[(rear - 1) % (maxSize + 1)];
    }

    void updateMaxKind(void)
    {
        int kindWithCoupon = checkCoupon();
        if (maxKind < kindWithCoupon)
        {
            maxKind = kindWithCoupon;
        }
    }

    int getMaxKind(void)
    {
        return maxKind;
    }

    int* getSushies(void)
    {
        return sushies;
    }
};

int rotatedIndex(int i)
{
    return i >= N ? i % N : i;
}

int Solve(void)
{
    SushiQueue sq = SushiQueue(k, c);
    for (int i = 0; i < k - 1; i++) // push k - 1 sushies
    {
        sq.push(A[rotatedIndex(i)]);
    }

    for (int j = 0; j < N; j++)
    {   
        sq.push(A[rotatedIndex(k + j - 1)]); // push rear sushi
        sq.updateMaxKind();                  // update max kind
        sq.pop();                            // pop front sushi
    }

    return sq.getMaxKind();
}

int main()
{
    int ans = -1;

    InputData(); // 입력받는 부분

    // 여기서부터 작성
    ans = Solve();

    cout << ans << endl; // 출력하는 부분
    return 0;
}