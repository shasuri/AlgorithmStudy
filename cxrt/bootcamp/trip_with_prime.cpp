#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

#define MAXSE 9999

int S, E; // 출발 정류장 번호, 도착 정류장 번호

// bool primal[MAXSE + 1];
bool visited[MAXSE + 1];

struct BusStop
{
    int id;
    int transferred = 0;

    BusStop(int id_, int transferred_) : id(id_), transferred(transferred_) {}
    BusStop() {}
};

queue<BusStop> dst;

void InputData()
{
    cin >> S >> E;
}

bool isPrime(int n)
{
    bool prime = true;
    int limit = sqrt(n);

    // don't care 0 or 1

    if (n % 2 == 0)
    {
        prime = false;
    }
    else
    {
        for (int i = 3; i <= limit; i += 2)
        {
            if (n % i == 0)
            {
                prime = false;
                break;
            }
        }
    }
    return prime;
}

bool checkDst(int bid)
{
    bool result = !visited[bid] && isPrime(bid);

    return result;
    
}

void visitThisStop(int bid)
{
    visited[bid] = true;
}

int pushNextDst(BusStop b)
{
    int n = 1;
    int preRest = 0;

    for (int i = 0; i < 4; i++)
    {
        int rest = b.id % (n * 10);
        int bid = b.id - rest + preRest;
        preRest = rest;

        for (int j = 0; j < 10; j++)
        {
            if (i == 3 && j == 0)
            {
                bid += n;
                continue;
            }
            // cout << bid << endl;
            if (checkDst(bid))
            {
                if (bid == E)
                {
                    return b.transferred + 1;
                }

                dst.push({bid, b.transferred + 1});
                visitThisStop(bid);
            }
            bid += n;
        }
        n *= 10;
    }

    return -1;
}

int Solve(void)
{
    dst.push({S, 0});
    visitThisStop(S);

    BusStop b;

    while (!dst.empty())
    {
        b = dst.front();
        dst.pop();
        // cout << b.id << endl;
        
        int pushResult = pushNextDst(b);
        if (pushResult != -1){
            return pushResult;
        }

    }
}

int main()
{
    int ans = -1;
    InputData(); // 입력받는 부분

    // 여기서부터 작성
    for (int i = 0; i < MAXSE + 1; i++)
    {
        visited[i] = false;
    }
    

    ans = Solve();
    cout << ans << endl; // 출력하는 부분
    return 0;
}