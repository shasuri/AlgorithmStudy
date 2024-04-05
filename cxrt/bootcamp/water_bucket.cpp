#include <iostream>
#include <queue>

using namespace std;

#define MAXCAP 1001

int capacityA, capacityB, goalA, goalB;

bool onceFilled[MAXCAP][MAXCAP];

struct Bucket
{
    int capacity;
    int current;
    int goal;
};

struct BucketPair
{
    Bucket a;
    Bucket b;
    int taskCount = 0;

    BucketPair() {}
    BucketPair(Bucket a_, Bucket b_, int t) : a(a_), b(b_), taskCount(t) {}
};

void InputData()
{
    cin >> capacityA >> capacityB >> goalA >> goalB;
}

queue<BucketPair> bpQueue;

void recordFilled(int aCur, int bCur)
{
    onceFilled[aCur][bCur] = true;
}

bool isFilledOnce(int aCur, int bCur)
{
    return onceFilled[aCur][bCur];
}

bool isAchiveGoal(Bucket buck)
{
    return buck.current == buck.goal;
}
bool isAchiveGoal(BucketPair bp)
{
    return isAchiveGoal(bp.a) && isAchiveGoal(bp.b);
}

bool isFull(Bucket buck)
{
    return buck.current >= buck.capacity;
}

bool isEmpty(Bucket buck)
{
    return buck.current <= 0;
}

Bucket getEmptyBucket(Bucket buck)
{
    return {buck.capacity, 0, buck.goal};
}

Bucket getFullBucket(Bucket buck)
{
    return {buck.capacity, buck.capacity, buck.goal};
}

BucketPair moveWater(Bucket src, Bucket dst)
{

    int sum = src.current + dst.current;

    if (sum > dst.capacity)
    {
        dst.current = dst.capacity;
        src.current = sum - dst.capacity;
    }
    else
    {
        src.current = 0;
        dst.current = sum;
    }

    return {src, dst, -1};
}

int Solve(void)
{
    BucketPair initial = {{capacityA, 0, goalA},
                          {capacityB, 0, goalB},
                          0};

    bpQueue.push(initial);
    recordFilled(0, 0);

    while (!bpQueue.empty())
    {
        BucketPair bp = bpQueue.front();
        bpQueue.pop();

        if (isAchiveGoal(bp))
        {
            return bp.taskCount;
        }

        // task for a

        if (!isEmpty(bp.a))
        {
            // empty a
            if (!isFilledOnce(0, bp.b.current))
            {
                recordFilled(0, bp.b.current);
                bpQueue.push({getEmptyBucket(bp.a),
                              bp.b, bp.taskCount + 1});
            }

            if (!isFull(bp.b))
            {
                // move a b
                BucketPair moveResult = moveWater(bp.a, bp.b);
                if (!isFilledOnce(moveResult.a.current, moveResult.b.current))
                {
                    recordFilled(moveResult.a.current, moveResult.b.current);
                    bpQueue.push({moveResult.a, moveResult.b, bp.taskCount + 1});
                }
            }
        }

        if (!isFull(bp.a))
        {
            // fill a
            if (!isFilledOnce(bp.a.capacity, bp.b.current))
            {
                recordFilled(bp.a.capacity, bp.b.current);
                bpQueue.push({getFullBucket(bp.a),
                              bp.b, bp.taskCount + 1});
            }
        }

        // task for b
        if (!isEmpty(bp.b))
        {
            // empty b
            if (!isFilledOnce(bp.a.current, 0))
            {
                recordFilled(bp.a.current, 0);
                bpQueue.push({bp.a, getEmptyBucket(bp.b),
                              bp.taskCount + 1});
            }

            if (!isFull(bp.a))
            {
                // move b a
                BucketPair moveResult = moveWater(bp.b, bp.a);
                if (!isFilledOnce(moveResult.b.current, moveResult.a.current))
                {
                    recordFilled(moveResult.b.current, moveResult.a.current);
                    bpQueue.push({moveResult.b, moveResult.a, bp.taskCount + 1});
                }
            }
        }

        if (!isFull(bp.b))
        {
            // fill b
            if (!isFilledOnce(bp.a.current, bp.b.capacity))
            {
                recordFilled(bp.a.current, bp.b.capacity);
                bpQueue.push({bp.a, getFullBucket(bp.b),
                              bp.taskCount + 1});
            }
        }
    }

    return -1;
}

int main()
{
    int ans = -2;
    InputData(); // 입력받는 부분

    // 여기서부터 작성
    ans = Solve();

    cout << ans << "\n"; // 출력하는 부분
    return 0;
}
