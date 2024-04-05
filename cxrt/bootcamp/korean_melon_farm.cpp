#include <iostream>
using namespace std;

int K;
int A[6];
int B[6];

int maxSN = 0;
int maxSNIndex = 0;

int maxEW = 0;
int maxEWIndex = 0;

int blankSN, blankEW, blankSNIndex, blankEWIndex;

void findMaxLen(int dir, int len, int ind)
{
    switch (dir)
    {
    case 3: // S
    case 4: // N
        if (maxSN < len)
        {
            maxSN = len;
            maxSNIndex = ind;
        }

        break;

    case 1: // E
    case 2: // W
        if (maxEW < len)
        {
            maxEW = len;
            maxEWIndex = ind;
        }

        break;

    default:
        break;
    }
}

void InputData()
{
    cin >> K;
    for (int i = 0; i < 6; i++)
    {
        cin >> A[i] >> B[i];
        // dir >> len

        findMaxLen(A[i], B[i], i);
    }

}

int getRotatedIndex(int ind)
{
    return ind % 6;
}

int isSNMaxNext(int ind)
{
    return getRotatedIndex(maxEWIndex + 1) == maxSNIndex;
}

int getLineLen(int ind){
    return B[getRotatedIndex(ind)];
}

int Solve(void)
{
    
    blankEWIndex = maxEWIndex;
    blankSNIndex = maxSNIndex;

    if (isSNMaxNext(maxEWIndex)) // if max sn is next on max ew
    {
        blankEWIndex += 4;
        blankSNIndex += 2;
    }
    else
    {
        blankEWIndex += 2;
        blankSNIndex += 4;
    }

    blankEW = getLineLen(blankEWIndex);
    blankSN = getLineLen(blankSNIndex);
    
    // cout << "mew\tmsn\tbew\tbsn\t\n";
    // cout << maxEW << '\t' << maxSN << '\t' << blankEW << '\t' << blankSN << "\t\n";
    
    return (maxEW * maxSN) - (blankEW * blankSN);
}

int main()
{
    int ans = -1;
    InputData(); // 입력받는 부분

    // 여기서부터 작성
    ans = Solve() * K;
    cout << ans << endl; // 출력하는 부분
    return 0;
}