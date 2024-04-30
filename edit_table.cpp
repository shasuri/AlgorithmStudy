#include <string>
#include <vector>
#include <iostream>
#include <stack>

#define DEBUG_MODE

using namespace std;

const int MAXR = 1000000;

const char SELECT_UP = 'U';
const char SELECT_DOWN = 'D';
const char REMOVE = 'C';
const char REVERT = 'Z';

const char EXIST = 'O';
const char NOT_EXIST = 'X';

struct Row
{
#ifdef DEBUG_MODE
    int ind = -1;
#endif
    bool exist = false;
    Row *next = nullptr;
    Row *prev = nullptr;
} Rows[MAXR];

Row head, tail;
Row *selected;

stack<Row *> removedRows;

string solution(int n, int k, vector<string> cmd);
void initTable(int n);
void processCmd(vector<string> &cmd);
int charToInt(char c);
void selectPrevRow(int s);
void selectNextRow(int s);
void removeRow(void);
void revertRow(void);
Row *searchNextExist(Row *r);
Row *searchPrevExist(Row *r);
void markExist(string &existMarked, int n);

#ifdef DEBUG_MODE
int main(void)
{
    solution(8, 2, {"D 2", "C", "U 3", "C", "D 4", "C", "U 2", "Z", "Z"});
}
#endif

string solution(int n, int k, vector<string> cmd)
{
    string answer = "";

    initTable(n);

    selected = &Rows[k];

    processCmd(cmd);

    markExist(answer, n);

    return answer;
}

void initTable(int n)
{
    head.next = &tail;
    tail.prev = &head;

    for (int i = 0; i < n; i++)
    {
        Rows[i].exist = true;

#ifdef DEBUG_MODE
        Rows[i].ind = i;
#endif

        tail.prev->next = &Rows[i];

        Rows[i].prev = tail.prev;
        Rows[i].next = &tail;

        tail.prev = &Rows[i];
    }
}

void processCmd(vector<string> &cmd)
{
    int selectInd;
    for (auto c : cmd)
    {
#ifdef DEBUG_MODE
        cout << c[0];
#endif
        switch (c[0])
        {
        case SELECT_UP:
#ifdef DEBUG_MODE
            cout << stoi(c.substr(2)) << '\n';
#endif
            selectInd = stoi(c.substr(2));
            selectPrevRow(selectInd);
            break;
        case SELECT_DOWN:
#ifdef DEBUG_MODE
            cout << stoi(c.substr(2)) << '\n';
#endif
            selectInd = stoi(c.substr(2));
            selectNextRow(selectInd);
            break;
        case REMOVE:
#ifdef DEBUG_MODE
            cout << '\n';
#endif
            removeRow();
            break;
        case REVERT:
#ifdef DEBUG_MODE
            cout << '\n';
#endif
            revertRow();
            break;

        default:
            break;
        }
    }
}

int charToInt(char c)
{
    return c - '0';
}

void selectPrevRow(int s)
{
    Row *rowSelect = selected;
    for (int i = 0; i < s; i++)
    {
        if (rowSelect->prev == &head)
        {
            break;
        }
        rowSelect = rowSelect->prev;
    }

    selected = rowSelect;
}

void selectNextRow(int s)
{
    Row *rowSelect = selected;
    for (int i = 0; i < s; i++)
    {
        if (rowSelect->next == &tail)
        {
            break;
        }
        rowSelect = rowSelect->next;
    }

    selected = rowSelect;
}

void removeRow(void)
{
    Row *removed;

    removed = selected;

    if (removed->next == &tail)
    {
        selected = selected->prev;
    }
    else
    {
        selected = selected->next;
    }

    removed->next->prev = removed->prev;
    removed->prev->next = removed->next;

    removed->exist = false;

    removedRows.push(removed);
#ifdef DEBUG_MODE
    cout << removed->ind << " is removed!" << '\n';
#endif
}

void revertRow(void)
{
    Row *removed = removedRows.top();
    searchNextExist(removed)->prev = removed;
    searchPrevExist(removed)->next = removed;

    removed->exist = true;

    removedRows.pop();
#ifdef DEBUG_MODE
    cout << removed->ind << " is reverted." << '\n';
#endif
}

Row *searchNextExist(Row *r)
{
    Row *rowCheck = r->next;
    while (!(rowCheck->exist) && rowCheck != &tail)
    {
        rowCheck = rowCheck->next;
    }

    return rowCheck;
}

Row *searchPrevExist(Row *r)
{
    Row *rowCheck = r->prev;
    while (!(rowCheck->exist) && rowCheck != &head)
    {
        rowCheck = rowCheck->prev;
    }

    return rowCheck;
}

void markExist(string &existMarked, int n)
{
    for (int i = 0; i < n; i++)
    {
        existMarked.push_back(Rows[i].exist ? EXIST : NOT_EXIST);
    }
}