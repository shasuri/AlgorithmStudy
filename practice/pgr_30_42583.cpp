// 다리를 지나는 트럭
// https://school.programmers.co.kr/learn/courses/30/lessons/42583

#include <iostream>
#include <string>
#include <vector>

#define MAX_BR_LEN 10000

using namespace std;

class BridgeQueue
{
private:
    int head = 0;
    int tail = 0;
    int size = -1;
    int bridge[MAX_BR_LEN];

public:
    BridgeQueue(int _size)
    {
        size = _size;
    }

    void enqueue(int truckNumber)
    {
        tail++;
        tail %= size;
        bridge[tail] = truckNumber;
    }

    int dequeue(void)
    {
        if (is_empty())
        {
            return -1;
        }

        head++;
        head %= size;
        return bridge[head];
    }

    void dequeue_all(void)
    {
        tail = head;
    }

    bool is_full(void)
    {
        return (tail + 1) % size == head;
    }

    bool is_empty(void)
    {
        return head == tail;
    }

    int push(int truckNumber)
    {
        int dq = -1;

        if (is_full())
        {
            dq = dequeue();
        }
        enqueue(truckNumber);

        return dq;
    }
};

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    int answer = 0;
    int time_spent = 0;
    int present_weight = 0;
    int present_truck_number = 0;

    BridgeQueue bridge_queue = BridgeQueue(bridge_length);

    for (vector<int>::iterator i = truck_weights.begin(); i != truck_weights.end();)
    {
        if (present_weight + *i <= weight && present_truck_number < bridge_length)
        {
            bridge_queue.enqueue(*i);
            present_weight += *i;
            present_truck_number++;
            time_spent++;

            i++;
        }
        else
        {
            present_weight -= bridge_queue.dequeue();
            present_truck_number--;

            time_spent += bridge_length - present_truck_number;
        }
    }

    time_spent += bridge_length;
    answer = time_spent;

    return answer;
}