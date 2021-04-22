#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  map<int, int> compress;
  vector<int> a(n), b(n), p(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i] >> b[i] >> p[i];
    b[i]++;
    compress[a[i]], compress[b[i]];
  }

  int coords = 0;
  for (auto &v : compress)
  {

    v.second = coords++;
    cout << v.first << " " << v.second << endl;
  }
  // cout << compress[b[1]] << endl;

  vector<vector<pair<int, int>>> project(coords);
  for (int i = 0; i < n; i++)
  {
    project[compress[b[i]]].emplace_back(compress[a[i]], p[i]);
    // compress[b[i]] : coords of b[i]
    // compress[a[i]] : coords of a[i]
    // p[i]           : reward of i
  }

  // for (int i = 0; i < coords; i++)
  // {
  //   for (auto p : project[i])
  //   {
  //     cout << i << " " << p.first << " " << p.second << endl;
  //   }
  // }
  vector<long long> dp(coords, 0);
  for (int i = 0; i < coords; i++)
  {
    if (i > 0)
    {
      dp[i] = dp[i - 1];
    }
    for (auto p : project[i])
    {
      dp[i] = max(dp[i], dp[p.first] + p.second);
      // dp[i]        : max reward until coord i
      // dp[p.first]  : max reward until coord p.first = project[i]..first = i olympiad's start day
      // p.second     : i olympiad's reward
    }
  }
  cout << dp[coords - 1] << endl;

  return 0;
}

/*
2 0
3 1
5 2
6 3
7 4
8 5
9 6

2 4 4
3 6 6
6 8 2
5 7 3

2 0 4
4 1 6
5 2 3
6 3 2
*/