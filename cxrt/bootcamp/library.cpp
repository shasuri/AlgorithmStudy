#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 10000

int N;

struct Student
{
    int start;
    int end;

    bool operator<(const Student s)
    {
        if (start == s.start)
        {
            return end < s.end;
        }
        return start < s.start;
    }

} students[MAXN];

int maxPresent = 0;
int maxAbsent = 0;

void InputData(void)
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> students[i].start >> students[i].end;
    }
}

void compareAbsents(int absent)
{
    if (absent > maxAbsent)
    {
        maxAbsent = absent;
    }
}

void comparePresents(int present)
{
    if (present > maxPresent)
    {
        maxPresent = present;
    }
}

void Solve(void)
{
    sort(students, students + N); // Sort by start time.

    int headStartTime = 1;
    int lastEndTime = 1;

    for (int i = 0; i < N; i++)
    {
        if (lastEndTime < students[i].start) // cut
        {
            comparePresents(lastEndTime - headStartTime);
            compareAbsents(students[i].start - lastEndTime);
            // status = true; // now present
            headStartTime = students[i].start;
            lastEndTime = students[i].end;
        }

        else if (lastEndTime < students[i].end)
        {
            lastEndTime = students[i].end;
        }
    }

    comparePresents(lastEndTime - headStartTime);
}

int main(void)
{
    InputData(); // 입력받는 부분

    // 여기서부터 작성
    Solve();
    cout << maxPresent << " " << maxAbsent << endl; // 출력하는 부분
    return 0;
}