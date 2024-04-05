#include <iostream>
#include <algorithm>

using namespace std;

#define MAXN 2000
#define MAXM 10000

int N, C, M; // village, capacity, box

struct Package
{
    int src;
    int dst;
    int mount;

    bool operator<(const Package p)
    {
        return dst < p.dst;
    }
} packages[MAXM + 10];

int vilsToDeliver[MAXN + 10];     // number of villages to take.
int packagesOnTruck[MAXN + 10];   // mount of taken package on truck.
int truckPackageSpace[MAXN + 10]; // space of turck in village.

void InputData()
{
    cin >> N >> C;
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> packages[i].src >> packages[i].dst >> packages[i].mount;
        vilsToDeliver[packages[i].src]++;
    }
}

int getTakableMount(int mount, int space)
{
    if (space >= mount)
    {
        return mount;
    }
    else
    {
        return space;
    }
}

int r(int n)
{
    if (n < 1)
    {
        return 0;
    }

    return n;
}

int getMaxSpace(int src, int dst)
{
    int m = 0;

    for (int i = src; i < dst; i++)
    {
        if (truckPackageSpace[i] > m)
            m = truckPackageSpace[i];
    }

    return m;
}

int Solve(void)
{
    for (int i = 0; i < MAXN + 10; i++)
    {
        truckPackageSpace[i] = 0;
    }

    Package p;
    const int truckCapacity = C;
    int currentTruckSpace = C;
    int deliveredPackageCount = 0;
    int takableMount;
    int villageOffset = 0;
    int j = 0;
    sort(packages, packages + M);

    for (int j = 0; j < M; j++) // take packages
    {
        p = packages[j];

        takableMount = getTakableMount(p.mount, truckCapacity - getMaxSpace(p.src, p.dst));
        // cout << "TAKE : " << p.src << "->" << p.dst << " - " << takableMount << endl;

        for (int k = p.src; k < p.dst; k++)
        {
            truckPackageSpace[k] += takableMount;
            if (truckPackageSpace[k] > truckCapacity)
            {
                truckPackageSpace[k] = truckCapacity;
            }
        }

        deliveredPackageCount += takableMount;
    }

    // cout << "PUT : " << i << " - " << packagesOnTruck[i] << endl;
    return deliveredPackageCount;
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