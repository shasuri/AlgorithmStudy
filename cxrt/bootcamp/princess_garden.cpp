#include <iostream>
#include <algorithm>

using namespace std;

#define MONTH 12
#define MAX_FLOWER 100000

int N, flowerCnt;

const int MONTH_DAY[MONTH] = {
    31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int MONTH_ACC_DAY[MONTH] = {0};

struct Flower
{
    int start;
    int end;

    bool operator<(Flower f)
    {
        if (start == f.start)
        {
            return end > f.end;
        }
        return start < f.start;
    }
} flowerDates[MAX_FLOWER];

Flower princess;

void setMonthAccDay(void)
{
    int accDay = 0;

    for (int i = 1; i < MONTH; i++) // acc Jan is 0
    {
        accDay += MONTH_DAY[i - 1];
        MONTH_ACC_DAY[i] = accDay;
    }
}

int getAccDay(int month, int day)
{
    return MONTH_ACC_DAY[month - 1] + (day - 1);
}

void InputData()
{
    int sm, sd, em, ed, start, end;

    cin >> N;
    flowerCnt = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> sm >> sd >> em >> ed;

        start = getAccDay(sm, sd);
        end = getAccDay(em, ed);

        if (start > princess.end ||
            end <= princess.start)
        {
            continue;
        }

        flowerDates[flowerCnt].start = max(princess.start, start);
        flowerDates[flowerCnt].end = min(princess.end + 1, end);
        flowerCnt++;
        // end day + 1
    }
}

void setPrincessFavorite(void)
{
    princess.start = getAccDay(3, 1);
    princess.end = getAccDay(11, 30);
}

int Solve(void)
{
    sort(flowerDates, flowerDates + flowerCnt);

    int ind = 0;
    int cur = ind;
    int longCur = cur;

    int flowerSelected = 1;

    if (flowerCnt <= 0 ||
        flowerDates[ind].start > princess.start)
    {
        return 0;
    }

    while (flowerDates[ind].end <= princess.end)
    {
        cur = ind;
        while (cur < flowerCnt &&
               flowerDates[cur].start <= flowerDates[ind].end)
        {
            if (flowerDates[cur].end > flowerDates[longCur].end)
            {
                longCur = cur;
            }
            cur++;
        }

        if (longCur > ind)
        {
            ind = longCur;
            flowerSelected++;
        }
        else{
            break;
        }
        
    }

    if (flowerDates[ind].end <= princess.end)
    {
        return 0;
    }
    else
    {
        return flowerSelected;
    }
}

int main()
{
    int ans = -1;

    setMonthAccDay();
    setPrincessFavorite();
    InputData(); // 입력받는 부분

    // 여기서부터 작성
    ans = Solve();

    cout << ans << endl; // 출력하는 부분
    return 0;
}
