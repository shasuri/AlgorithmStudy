#include <iostream>
#include <cstring>
using namespace std;

int N;
char S[10000 + 10][20 + 10];
int L[10000 + 10];

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

    for (int i = 0; i < 10010; i++)
    {
        L[i] = -1;
    }
    
}

bool isStrSame(char* t, char* u, int tLen, int uInd){


    int uLen;

    if (L[uInd] == -1)
    {
        L[uInd] = strlen(u);
    }
    uLen = L[uInd];

    if (tLen != uLen)
    {
        return false;
    }

    for (int i = 0; i < tLen; i++)
    {
        if (t[i] != u[i])
        {
            return false;
        }
    }

    return true;
}

void Solve()
{
    int dupCount, strLen;
    bool isAllUnique = true;

    for (int i = 0; i < N; i++)
    {

        if (visited[i])
        {
            continue;
        }
        visited[i] = true;

        dupCount = 0;
        
        if (L[i] == -1)
        {
            L[i] = strlen(S[i]);
        }
        strLen = L[i];
        
        for (int j = i + 1; j < N; j++)
        {
            if (visited[j])
            {
                continue;
            }

            if (L[j] == -1)
            {
                L[j] = strlen(S[j]);
            }

            if (L[i] != L[j])
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
    initVisited();
    Solve();
    return 0;
}