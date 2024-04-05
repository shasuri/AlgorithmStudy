#include <iostream>
#include <algorithm>

using namespace std;

#define MAXN ((int)1e5)

int N; // 영화수
int fitMovieCount = 0; // film time more than 1 hour

struct Movie
{
    int start, end;

    bool operator<(Movie m)
    {
        return end < m.end;
    }

} movies[MAXN];

void InputData()
{
    cin >> N;

    int s, e;
    for (int i = 0; i < N; i++)
    {
        cin >> s >> e;

        if (e - s < 2) // less than 1 hour
        {
            continue;
        }

        movies[fitMovieCount].start = s;
        movies[fitMovieCount++].end = e;
    }
}

int Solve(void)
{
    sort(movies, movies + fitMovieCount);

    int lastEndTime = 0;
    int watchCount = 0;

    for (int i = 0; i < fitMovieCount; i++)
    {
        // cout << movies[i].end << endl;
        if (movies[i].start < lastEndTime)
        {
            continue;
        }
        
        lastEndTime = movies[i].end;
        watchCount++;
    }
    
    return watchCount;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int ans = -1;
    InputData(); // 입력받는 부분

    // 여기서부터 작성
    ans = Solve();

    cout << ans << "\n"; // 출력하는 부분
    return 0;
}