#include <iostream>
#include <vector>

using namespace std;

struct person
{
    bool visited;       // 방문여부
    vector<int> family; // 1촌관계의 가족
};

int x, y;              // 문제에서 촌수를 요구하는 두 사람
int chon = -1;         // 촌수 -1 초기화
bool findFlag = false; // 탐색 성공 여부

vector<person> people; // n명의 person을 담을 vector

void dfs(int start, int step)
{
    person *starter = &people[start]; // 1촌을 찾을 사람

    if (starter->visited) // 방문했으면 return
    {
        return;
    }
    starter->visited = true; // 방문 표기

    for (int i = 0; i < starter->family.size(); i++) // 1촌들을 순회
    {
        if (findFlag) // 찾았으면 순회하지 않고 바로 return
        {
            return;
        }

        if (starter->family[i] == y) // 탐색 완료
        {
            chon = step + 1; // 전역변수에 step + 1을 기록
            findFlag = true; // 탐색성공 여부 체크
            return;
        }

        dfs(starter->family[i], step + 1); // 1촌들에 step 누적 후 재귀
    }
}

int main(void)
{
    int peopleNum, relNum; // 사람 수, 관계 수

    cin >> peopleNum;
    people.resize(peopleNum); // vector 크기 지정

    cin >> x >> y;
    x--; // 입력 n은 1부터 시작하므로 -1
    y--;

    cin >> relNum;

    for (int i = 0; i < relNum; i++)
    {
        int parent, child;

        cin >> parent >> child;

        people[parent - 1].family.push_back(child - 1); // 양쪽 1촌에 모두 추가
        people[child - 1].family.push_back(parent - 1);
    }

    dfs(x, 0);

    cout << chon << endl;
}
