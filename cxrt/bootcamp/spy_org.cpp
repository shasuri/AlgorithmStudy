#include <iostream>
using namespace std;

int N;
char A[20000 + 10];
void InputData()
{
    cin >> N >> A;
}

void analyzeGraph(void)
{
    int i = 0;
    int depth = 0;
    while (A[i] != '\0')
    {
        // cout << A[i];
        if (A[i] == '<')
        {
            depth++;
            i++;
            continue;
        }
        if (A[i] == '>')
        {
            depth--;
            i++;
            continue;
        }

        if (depth == N)
        {
            // int j = i;
            while (A[i] != '<' && A[i] != '>')
            {
                cout << A[i];
                i++;
            }
            cout << " ";
        }
        else{
            i++;
        }
    }
}

void Solve(void)
{
    analyzeGraph();
}

int main()
{
    InputData(); // 입력받는 부분

    // 여기서부터 작성
    Solve();

    return 0;
}