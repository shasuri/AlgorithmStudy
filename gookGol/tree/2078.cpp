#include <iostream>
// #include <vector>

using namespace std;

// #define FOR(i, j) for (int i = 0; i < j; i++)

int node[2];
int path[2] = {0, 0};

void input(void)
{
    cin >> node[0] >> node[1];
}

void findPath(int leftElem, int rightElem)
{
    if (leftElem == 1 && rightElem != 1)
    {
        // node가 tree의 오른쪽 테두리에 위치할때
        path[1] += rightElem - 1; // depth = 현재 right의 값 - 1
        return;
    }

    if (rightElem == 1 && leftElem != 1)
    {
        // node가 tree의 왼쪽 테두리에 위치할때
        path[0] += leftElem - 1; // depth = 현재 left의 값 - 1
        return;
    }

    if (leftElem > rightElem)
    {
        // node가 left child!
        path[0]++;
        findPath(leftElem - rightElem, rightElem);
        return;
    }

    if (leftElem < rightElem)
    {
        // node가 right child!
        path[1]++;
        findPath(leftElem, rightElem - leftElem);
        return;
    }

    if (leftElem == rightElem)
    {
        // node가 root!
        return;
    }
}

void solve(void)
{
    findPath(node[0], node[1]);
}

void print(void)
{
    cout << path[0] << " " << path[1] << endl;
}

int main()
{
    input();
    solve();
    print();

    return 0;
}
