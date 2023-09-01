/*
 * PNU TECHWEEK Competition
 * Practice Session Python I/O Example
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}

int main()
{

    // Get N from standard input
    int N;
    cin >> N;

    // Declare array to contain vote results
    // int votes[101];
    // memset(votes, 0, sizeof(votes));
    int tmp;
    vector<pair<int, int>>::iterator it;
    // get each vote result in 'votes' array with for loop
    vector<pair<int, int>> votes; // idx, cnt
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        it = find_if(votes.begin(), votes.end(),
                     [&tmp](const pair<int, int> &tt)
                     { return tt.first == tmp; });
        if (votes.end() == it)
        {
            votes.push_back(make_pair(tmp, 1));
        }
        else
        {
            it->second += 1;
        }
    }

    sort(votes.begin(), votes.end(), cmp);

    // for(auto a: votes){
    //     cout <<a.first << " " << a.second << "\n";
    // }

    // calculate answer

    /*
    TO-DO part
    Uses votes[0] as a temporary answer
    */

    // print answer
    int i = 0;
    while (i + 1 < N && votes[i].second == votes[i + 1].second)
    {
        i += 2;
    }
    if (i + 1 < N)
    {
        cout << votes[i].first;
    }
    else
    {
        cout << -1;
    }
}