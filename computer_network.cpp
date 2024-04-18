#include <string>
#include <vector>

using namespace std;

const int MAXC = 200;

bool visited[MAXC];

vector<vector<int>> cpus;
int cpuNum;

void countNetwork(int &nw);
void traverseNetwork(int src);

int solution(int n, vector<vector<int>> computers)
{
    int answer = 0;

    cpuNum = n;
    cpus = computers;

    countNetwork(answer);

    return answer;
}

void countNetwork(int &nw)
{
    for (int i = 0; i < cpuNum; i++)
    {
        if (!visited[i])
        {
            nw++;
            visited[i] = true;
            traverseNetwork(i);
        }
    }
}

void traverseNetwork(int src)
{
    for (int dst = 0; dst < cpuNum; dst++)
    {
        if (src == dst)
        {
            continue;
        }

        if (!visited[dst] && cpus[src][dst] == 1)
        {
            visited[dst] = true;
            traverseNetwork(dst);
        }
    }
}