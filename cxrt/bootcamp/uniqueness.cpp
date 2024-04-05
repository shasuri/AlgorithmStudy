#include <iostream>
#include <cstring>
using namespace std;

int N;
char S[10000 + 10][20 + 10];
bool visited[10000];
void InputData()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> S[i];
    }
}

void initVisited(void)
{
    for (int i = 0; i < N; i++)
    {
        visited[i] = false;
    }
}

void Solve()
{
    int dupCount;
    bool isAllUnique = true;

    for (int i = 0; i < N; i++)
    {

        if (visited[i])
        {
            continue;
        }
        visited[i] = true;

        dupCount = 0;
        for (int j = i + 1; j < N; j++)
        {
            if (visited[j])
            {
                continue;
            }

            if (strcmp(S[i], S[j]) == 0)
            {
                if (dupCount == 0)
                {
                    cout << S[i] << ' ' << i + 1;
                }

                dupCount++;
                visited[j] = true;

                cout << ' ' << j + 1;
            }
        }

        if (dupCount > 0)
        {
            isAllUnique = false;
            cout << '\n';
        }
    }

    if (isAllUnique)
    {
        cout << "unique" << '\n';
    }

    return;    
}

int main()
{
    InputData(); // 입력받는 부분

    Solve();
    return 0;
}