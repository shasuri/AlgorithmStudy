#include <iostream>
#include <queue>
#include <map>
#include <vector>

using namespace std;

int main(void)
{
    struct oly
    {
        int start;
        int end;
        int reward;
    }; // structure to store olympiad day info

    struct cmp
    {
        bool operator()(oly h, oly a)
        {
            return h.end > a.end;
        }
    }; // cmp using in priority queue

    int n;
    // number of Olympiads
    cin >> n;
    // input n

    priority_queue<oly, vector<oly>, cmp> olys;
    // pq to store and sort oly by end day

    map<int, int> daysZip;
    // map to match days to continous number

    vector<int> a(n);
    vector<int> b(n);
    vector<int> p(n);
    // a, b, p vector

    for (int i = 0; i < n; i++)
    {

        // input a, b, p

        cin >> a[i] >> b[i] >> p[i];

        daysZip[a[i]];
        daysZip[b[i] + 1];
        // make space for days on map
        // dp value of end day should be applied next day
    }

    int dayNum = 0;

    for (auto &iter : daysZip)
    {
        iter.second = dayNum++;
        // match start / end+1 day to continous number
    }

    for (int i = 0; i < n; i++)
    {
        oly olympiad;

        olympiad.start = daysZip[a[i]];
        olympiad.end = daysZip[b[i] + 1];
        olympiad.reward = p[i];

        // make oly object

        olys.push(olympiad);
        // push object to pq
        // objects will be sorted by cmp of pq
    }

    vector<long long> dp(dayNum, 0);
    // dp vector is consist of maximum accumulated rewards untili index day

    oly recentOly = {-1, -1, -1};
    // recent accumulated olympiad will be stored

    for (int indexDay = 0; indexDay < dayNum; indexDay++)
    {

        oly olyEngage = olys.top();
        // oly to engage, top one in pq

        if (indexDay > 0 && recentOly.end != olyEngage.end)
        {
            // if indexDay is not 0 and end day of recent oly is different,

            dp[indexDay] = dp[indexDay - 1];
            // copy previous day's dp

            // condition is for preventing overlapping copy by comparing end days
        }

        if (olyEngage.end == indexDay)
        {
            dp[olyEngage.end] = max(dp[olyEngage.end],
                                    dp[olyEngage.start] + olyEngage.reward);

            // choose bigger one among previous day's dp
            //                      or start day's dp + reward(engage this olympiad)

            recentOly = olyEngage;
            // save this oly to remember this end day

            olys.pop();
            // oly is popped and next oly is top

            if (olys.size() > 0 && olys.top().end == olyEngage.end)
                indexDay--;
            // if next oly's end day is same to popped one,
            // try to engage next oly so, delay the index one time
        }
    }

    // for (int i = 0; i < dayNum; i++)
    //     cout << dp[i] << " ";
    // cout << endl;

    cout << dp[dayNum - 1] << endl;
    // print out last dp value, maximum one

    return 0;
}