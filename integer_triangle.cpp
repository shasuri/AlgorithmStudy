#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> triangle)
{
    int answer = 0;

    int height = triangle.size();

    for (int i = height - 1; i >= 1; i--)
    {
        for (int j = 0; j < i; j++)
        {
            triangle[i - 1][j] += (triangle[i][j] > triangle[i][j + 1] ? triangle[i][j] : triangle[i][j + 1]);
        }
    }


    return triangle[0][0];
}