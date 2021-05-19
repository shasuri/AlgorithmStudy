#include <iostream>
#include <vector>
#include <queue>

using namespace std;
struct node
{
    int indexI;
    int indexJ;
    int value;
};
struct cmp
{
    bool operator()(node t, node u)
    {
        return t.value > u.value;
    }
};

int main()
{
    priority_queue<node, vector<node>, cmp> pq;

    pq.push({1, 1, 10});
    pq.push({1, 1, 32});
    pq.push({1, 1, 25});

    cout << pq.top().value << endl;
    pq.pop();
    cout << pq.top().value << endl;
    pq.pop();
    cout << pq.top().value << endl;
    pq.pop();
    return 0;
}
