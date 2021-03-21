#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int N, M, K;
int dungeon[26][200001] = {0};
int sum_dungeon[26][200001];
int UP = 0;
string str;
int result;
long long int answer = 0;

void input() 
{
  char tmp;
  cin >> N >> M >> K;
  for (int k = 0; k < K; k++) {
    cin >> tmp; // m == 0
    tmp == 'R' ? (sum_dungeon[k][0] = 0, UP++): (sum_dungeon[k][0] = 1, dungeon[k][0] = 1);
    for (int m = 1; m < M; m++) {
      cin >> tmp;
      if (tmp == 'R') {
        sum_dungeon[k][m] = sum_dungeon[k][m-1];
        UP++;
      }
      else {
        dungeon[k][m] = UP + 1;
        sum_dungeon[k][m] = sum_dungeon[k][m-1] + dungeon[k][m];
        UP = 0;
      }
    }
    dungeon[k][M] = UP;
    sum_dungeon[k][M] = sum_dungeon[k][M-1] + dungeon[k][M];
    UP = 0;
  }
  cin >> str;
}

void solve() 
{
  answer = dungeon[str[N-1] - 'A'][M] == 0 ? dungeon[str[N-1] - 'A'][M - 1] : dungeon[str[N-1] - 'A'][M];
  result = answer;
  for (int n = N - 2, m = M - 1; n >= 0; n--) {
    if (m - result < 0) {
      result = sum_dungeon[str[n] - 'A'][m];
      answer += result;
    }
    else {
      result = sum_dungeon[str[n] - 'A'][m] - sum_dungeon[str[n] - 'A'][m - result];
      if (result == 0) {
        return;
      }
      answer += result;
    }
    while(m > 0 && dungeon[str[n] - 'A'][m] == 0) {
      m--;
    }
  }
}

void print() 
{
  cout << answer << "\n";
}

int main()
{
  input();
  solve();
  print();
}