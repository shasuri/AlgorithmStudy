#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX (100)
#define DIR 4

int M, N, K;        // 세로크기, 가로크기, 직사각형 개수
int sol[MAX * MAX]; // 각 영역 넓이 저장용
bool paper[MAX][MAX];

struct Point
{
    int y;
    int x;
};

void drawRectangle(Point s, Point e)
{
    for (int y = s.y; y < e.y; y++)
    {
        for (int x = s.x; x < e.x; x++)
        {
            paper[y][x] = true;
        }
    }
}

void InputData()
{
    Point start;
    Point end;
    cin >> M >> N >> K;
    for (int i = 0; i < K; i++)
    {
        cin >> start.x >> start.y >> end.x >> end.y;
        drawRectangle(start, end);
    }
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

bool isInRectangle(Point p)
{
    return paper[p.y][p.x];
}

bool isVisitable(Point p)
{
    return p.y > -1 && p.y < M &&
           p.x > -1 && p.x < N &&
           !isInRectangle(p);
}

void visitThisPoint(Point p)
{
    paper[p.y][p.x] = true;
}

int dirY[] = {1, -1, 0, 0};
int dirX[] = {0, 0, 1, -1};

int getArea(Point start)
{
    queue<Point> pointQueue;

    pointQueue.push(start);
    visitThisPoint(start);

    int area = 1;

    while (!pointQueue.empty())
    {
        Point curPoint = pointQueue.front();
        pointQueue.pop();

        for (int i = 0; i < DIR; i++)
        {
            Point newPoint = {curPoint.y + dirY[i], curPoint.x + dirX[i]};

            if (isVisitable(newPoint))
            {
                visitThisPoint(newPoint);
                pointQueue.push(newPoint);
                area++;
            }
        }
    }

    return area;
}

int Solve(void)
{
    int areaCount = 0;
    for (int y = 0; y < M; y++)
    {
        for (int x = 0; x < N; x++)
        {
            Point point = {y, x};
            if (!isInRectangle(point))
            {
                sol[areaCount++] = getArea(point);
            }
        }
    }

    sort(sol, sol + areaCount);

    return areaCount;
}

int main(void)
{
    int ans = -1;
    InputData(); // 입력받는 부분

    // 여기서부터 작성
    ans = Solve();
    OutputData(ans); // 출력하는 부분
    return 0;
}