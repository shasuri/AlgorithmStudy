#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 500

int N;
int sol[MAXN];

struct Meeting
{
    int id;
    int start;
    int end;

    const bool operator<(const Meeting m)
    {
        return end < m.end;
    }
} Meetings[MAXN];

void InputData()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> Meetings[i].id >> Meetings[i].start >> Meetings[i].end;
    }
}

int Solve(void)
{
    sort(Meetings, Meetings + N); // Sort by end time.
    
    int meetingCount = 0;
    int lastEnd = 0;
    for (int i = 0; i < N; i++)
    {
        if (Meetings[i].start < lastEnd)
        {
            continue;
        }
        
        lastEnd = Meetings[i].end;
        sol[meetingCount++] = Meetings[i].id;
    }
    return meetingCount;
}

void OutputData(int ans)
{
    cout << ans << endl;
    for (int i = 0; i < ans; i++)
    {
        cout << sol[i] << " ";
    }
    cout << endl;
}
int main()
{
    int ans = -1;

    InputData(); // 입력받는 부분

    // 여기서부터 작성
    ans = Solve();

    OutputData(ans);

    return 0;
}