#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

#define MAXN ((int)1e4)
#define MAXAT 1000000001
int M, T, N; // 배에태울수있는수, 배이동시간, 손님수

struct Ticket
{
    int at;
    int ind;

    bool operator<(Ticket t){
        if (at == t.at)
        {
            return ind < t.ind;
        }
        return at < t.at;
    }
};

queue<Ticket> leftQueue;
queue<Ticket> rightQueue;

int arrived[MAXN + 10];
int arrInd = 0;

void InputData()
{
    int at;
    string side;

    cin >> M >> T >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> at >> side;
        Ticket t;
        t.at = at;
        t.ind = i;
        if (side == "left")
        {
            leftQueue.push(t);
        }
        else
        { // side == "right"
            rightQueue.push(t);
        }
    }
}
void OutputData()
{
    for (int i = 0; i < N; i++)
    {
        cout << arrived[i] << "\n";
    }
}

Ticket getTicket(int at, int ind){
    Ticket t;
    t.at = at;
    t.ind = ind;

    return t;
}

void Solve(void)
{
    bool isBoatLeft = true;
    int boatTime = 0;

    Ticket leftFront, rightFront;
    while (arrInd < N)
    {
        leftFront = leftQueue.empty() ? getTicket(MAXAT, -1) : leftQueue.front();
        rightFront = rightQueue.empty() ? getTicket(MAXAT, -1) : rightQueue.front();

        // discuss where boat to go
        if (!((isBoatLeft && (boatTime >= leftFront.at)) ||
              (!isBoatLeft && (boatTime >= rightFront.at))))
        {
            if (rightFront < leftFront)
            {
                boatTime = max(boatTime, rightFront.at);
                if (isBoatLeft)
                {
                    boatTime += T;
                    isBoatLeft = false;
                }
            }
            if (leftFront < rightFront)
            {
                boatTime = max(boatTime, leftFront.at);
                if (!isBoatLeft)
                {
                    boatTime += T;
                    isBoatLeft = true;
                }
            }
            // if (leftFront == rightFront)
            // {
            //     if (isBoatLeft)
            //     {
            //         boatTime = max(boatTime, leftFront);
            //     }
            //     else
            //     {
            //         boatTime = max(boatTime, rightFront);
            //     }
            // }
        }

        if (isBoatLeft)
        { // boat is on left and left client is first

            // take on boat as possible
            boatTime = max(boatTime, leftFront.at);
            for (int i = 0; i < M; i++)
            {
                if (leftFront.at > boatTime)
                {
                    break;
                }
                arrived[leftFront.ind] = boatTime + T;
                arrInd++;
                leftQueue.pop();
                if (arrInd >= N || leftQueue.empty())
                {
                    break;
                }
                leftFront = leftQueue.front();
            }

            // boat move to right
            boatTime += T;
            isBoatLeft = false;
        }
        else
        { // boat is on right and right client is first
            boatTime = max(boatTime, rightFront.at);
            for (int i = 0; i < M; i++)
            {
                if (rightFront.at > boatTime)
                {
                    break;
                }
                arrived[rightFront.ind] = boatTime + T;
                arrInd++;
                rightQueue.pop();
                if (arrInd >= N || rightQueue.empty())
                {
                    break;
                }
                rightFront = rightQueue.front();
            }

            // boat move to left
            boatTime += T;
            isBoatLeft = true;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    InputData(); // 입력받는 부분

    // 여기서부터 작성
    Solve();

    OutputData(); // 출력하는 부분
    return 0;
}