#include <string>
#include <vector>
#include <iostream>

using namespace std;

typedef vector<vector<int>> Table;

const int MAXN = 1001;
const int MAXM = 1001;

const int ATTACK = 1;
const int HEAL = 2;

int N, M;

int accSumTable[MAXN][MAXM];

Table buildings;

void setAccSumTable(Table &skill);
void setBuildingDamageTable(void);
int countNonDestroiedBuilding(Table &board);
void printTables(void);
int solution(vector<vector<int>> board, vector<vector<int>> skill)
{
    int answer = 0;

    N = board.size();
    M = board[0].size();

    setAccSumTable(skill);

    setBuildingDamageTable();

    answer = countNonDestroiedBuilding(board);

    buildings = board;
    printTables();
    return answer;
}

void setAccSumTable(Table &skill)
{
    for (auto s : skill)
    {
        int type = s[0];
        int r1 = s[1];
        int c1 = s[2];
        int r2 = s[3];
        int c2 = s[4];
        int degree = s[5];

        if (type == ATTACK)
        {
            degree *= -1;
        }

        accSumTable[r1][c1] += degree;
        accSumTable[r1][c2 + 1] += degree * (-1);

        accSumTable[r2 + 1][c1] += degree;
        accSumTable[r2 + 1][c2 + 1] += degree * (-1);
    }
}

void setBuildingDamageTable(void)
{
    for (int n = 0; n < N; n++)
    {
        for (int m = 0; m < M - 1; m++)
        {
            accSumTable[n][m + 1] += accSumTable[n][m];
        }
    }

    for (int n = 0; n < N - 1; n++)
    {
        for (int m = 0; m < M; m++)
        {
            accSumTable[n + 1][m] += accSumTable[n][m];
        }
    }
}

int countNonDestroiedBuilding(Table &board)
{
    int nonDestroiedBuilding = 0;
    for (int n = 0; n < N; n++)
    {
        for (int m = 0; m < M; m++)
        {
            if (board[n][m] + accSumTable[n][m] > 0)
            {
                nonDestroiedBuilding++;
            }
        }
    }
    return nonDestroiedBuilding;
}

void printTables(void)
{
    for (int n = 0; n < N; n++)
    {
        for (int m = 0; m < M; m++)
        {
            cout << buildings[n][m]+ accSumTable[n][m] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}