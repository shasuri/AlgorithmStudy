#include <iostream>

using namespace std;

#define MAX_ITEM 100
#define MAX

int dp[10000];

struct item
{
    int value = 0;
    int quant = 0;
} items[100];

int main(int argc, char **argv)
{
    int test_case;
    int T;
    // freopen("input.txt", "r", stdin);
    cin >> T;

    int N, K;
    int v, c;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        cin >> N >> K;
        for (int i = 0; i < N; i++)
        {
            cin >> v >> c;

            items[i].quant = v;
            items[i].value = c;
        }
        binaryChoice(0, 0, 0);
    }
    return 0; //정상종료시 반드시 0을 리턴해야합니다.
}

void binaryChoice(int ii, int bagQuant, int itemVal)
{
    items[ii].quant;
}