#include <iostream>
using namespace std;

#define DICE 6
#define MAX_ROLL 5
int N; // 던진횟수
int M; // 출력모양

int seq[MAX_ROLL];

void InputData()
{
    cin >> N >> M;
}

void printSeq(void)
{
    for (int i = 0; i < N; i++)
    {
        cout << seq[i] << ' ';
    }
    cout << '\n';
    return;
}

void duplPerm(int rolled)
{
    if (rolled >= N)
    {
        printSeq();
        return;
    }

    for (int num = 0; num < DICE; num++)
    {
        seq[rolled] = num + 1;
        duplPerm(rolled + 1);
    }

    return;
}

void duplComb(int rolled, int start)
{
    if (rolled >= N)
    {
        printSeq();
        return;
    }

    for (int num = start; num < DICE; num++)
    {
        seq[rolled] = num + 1;
        duplComb(rolled + 1, num);
    }

    return;
}

bool isShown(int num, int shown)
{
    return shown & (1 << num);
}

int showThisNumber(int num, int shown)
{
    return shown + (1 << num);
}

void perm(int rolled, int shown)
{
    if (rolled >= N)
    {
        printSeq();
        return;
    }

    for (int num = 0; num < DICE; num++)
    {
        if (isShown(num, shown))
        {
            continue;
        }

        seq[rolled] = num + 1;
        perm(rolled + 1, showThisNumber(num, shown));
    }

    return;
}

void Solve(void)
{

    switch (M)
    {
    case 1:
        duplPerm(0);
        break;
    case 2:
        duplComb(0, 0);
        break;
    case 3:
        perm(0, 0);
        break;

    default:
        cout << "Invalid rolling command!" << endl;
        break;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    InputData(); // 입력

    Solve();

    return 0;
}