#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> people, int limit)
{
    int answer = 0;
    sort(people.begin(), people.end());

    int cur = 0;
    int boat = 0;

    int i = 0;
    int j = people.size() - 1;

    while (i < j)
    {
        if (people[i] + people[j] <= limit)
        {
            i++;
        }
            j--;
            boat++;
    }

    if (i == j)
    {
        boat++;
    }

    answer = boat;
    return answer;
}

// 40 50 60 60 80