#include <iostream>
using namespace std;

char str[100000 + 10];
void InputData()
{
    cin >> str;
}

int startingPar = 0;
int endingPar = 0;
int reverseCount = 0;

void push(void)
{
    startingPar++;
}

void pop(void)
{
    if (startingPar <= endingPar)
    {
        reverseCount++;
        push();
        return;
    }

    endingPar++;
}

int Solve(void)
{
    int i = 0;

    while (str[i] != '\0')
    {
        if (str[i] == '(') // push
        {
            push();
        }
        else
        { // pop
            pop();
        }

        i++;
    }

    if (startingPar > endingPar)
    {
        reverseCount += (startingPar - endingPar) / 2;
    }

    return reverseCount;
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