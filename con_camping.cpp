#include <vector>
#include <algorithm>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.

int solution(int n, vector<vector<int>> data)
{
    int answer = 0;

    int px, py, sx, sy, tx, ty, minx, maxx, miny, maxy;
    bool tentable;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            py = data[i][1];
            px = data[i][0];
            sy = data[j][1];
            sx = data[j][0];

            if (py != sy && px != sx)
            {
                miny = min(py, sy);
                maxy = max(py, sy);
                minx = min(px, sx);
                maxx = max(px, sx);

                tentable = true;
                for (int k = 0; k < n; k++)
                {
                    ty = data[k][1];
                    tx = data[k][0];

                    if (ty > miny && ty < maxy && tx > minx && tx < maxx)
                    {
                        tentable = false;
                        break;
                    }
                }

                if (tentable)
                {
                    answer++;
                }
                
            }
        }
    }

    return answer;
}
