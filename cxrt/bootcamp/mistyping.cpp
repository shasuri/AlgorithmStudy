#include <iostream>
using namespace std;
#define MAXN 100000

char str[MAXN + 1];
int storage[MAXN];

int len;
bool isOpenMore;
bool isRightString;

int openPar = 0;
int closePar = 0;

void InputData()
{
    cin >> str;
}

void analyzeString(void)
{
    int i = 0;

    while (str[i] != '\0')
    {
        if (str[i] == '(')
        {
            openPar++;
        }

        if (str[i] == ')')
        {
            closePar++;
        }
        i++;
        storage[i] = openPar;
    }

    isOpenMore = (openPar > closePar);
    isRightString = (openPar == closePar);
    len = i;
}

int walkLeft(void)
{
    int leftOpenPar = 0;
    int leftClosePar = 0;
    int wrongCount = 0;
    for (int i = len - 1; i > -1; i--)
    {
        if (str[i] == ')')
        {
            leftClosePar++;
        }
        if (str[i] == '(')
        {
            leftOpenPar++;
        }

        if (leftOpenPar > leftClosePar)
        {
            return leftOpenPar;
        }
    }

    return wrongCount;
}

int walkRight(void)
{
    int rightOpenPar = 0;
    int rightClosePar = 0;
    int wrongCount = 0;

    for (int i = 0; i < len; i++)
    {
        if (str[i] == '(')
        {
            rightOpenPar++;
        }
        if (str[i] == ')')
        {
            rightClosePar++;
        }
        if (rightClosePar > rightOpenPar)
        {
            return rightClosePar;
        }
    }
}

int Solve(void)
{
    analyzeString();

    if (isRightString)
    {
        return 0;
    }

    int wrongCount = 0;

    if (isOpenMore) // wrong par is open par
    {
        return walkLeft();
    }
    else
    {

        return walkRight();
    }
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