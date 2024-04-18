#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
const int DIV = 1000000007;

vector<int> money;
int changeCase = 0;
int minMoney = DIV;

void dfs(int leftMoney, vector<int>::iterator startItr);

int solution(int n, vector<int> money_)
{
    int answer = 0;

    // sort(money_.begin(), money_.end(), greater<int>());
    // minMoney = *(money_.end() - 1);

    money = money_;

    // for (auto m : money_)
    // {
    //     if (m < minMoney)
    //     {
    //         minMoney = m;
    //     }
    // }

    dfs(n, money.begin());

    answer = changeCase;

    return answer;
}

void dfs(int leftMoney, vector<int>::iterator startItr)
{

    for (vector<int>::iterator it = startItr; it != money.end(); it++)
    {
        if (*it <= leftMoney)
        {
            // cout << *it << " ";
            if (leftMoney == *it)
            {
                changeCase++;
                if (changeCase == DIV)
                {
                    changeCase = 0;
                }
                
                // changeCase %= DIV;
                // cout << '\n';
                return;
            }
            dfs(leftMoney - *it, it);
        }
    }
}