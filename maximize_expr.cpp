#include <string>
#include <vector>
#include <iostream>

using namespace std;

const char ADD = '+';
const char SUB = '-';
const char MUL = '*';

const char usableOpts[] = {ADD, SUB, MUL};
bool optVisited[] = {true, true, true};

vector<long long> originOprs;
vector<char> originOpts;

long long maxV = 0;

void parseExpr(string &expr);
bool isOpt(char c);
short charToShort(char c);
int optToIdx(char c);

void decidePriority(int depth, vector<long long> operands, vector<char> operators);

long long calcOpr(long long t, long long u, char opt);

long long solution(string expression)
{
    long long answer = 0;

    parseExpr(expression);

    decidePriority(0, originOprs, originOpts);

    return maxV;
}

void parseExpr(string &expr)
{
    short n = 0;
    char c;
    for (int i = 0; i < expr.length(); i++)
    {
        c = expr[i];
        if (isOpt(c))
        {
            originOprs.push_back(n);
            n = 0;
            originOpts.push_back(c);
            optVisited[optToIdx(c)] = false;
        }
        else
        {
            n = n * 10 + charToShort(c);
        }
    }
    originOprs.push_back(n);
}

bool isOpt(char c)
{
    return c == ADD || c == SUB || c == MUL;
}

short charToShort(char c)
{
    return c - '0';
}

int optToIdx(char c)
{
    switch (c)
    {
    case ADD:
        return 0;
        break;
    case SUB:
        return 1;
        break;
    case MUL:
        return 2;
        break;
    default:
        break;
    }
    return -1;
}

void decidePriority(int depth, vector<long long> operands, vector<char> operators)
{
    if (depth >= 3)
    {
        
        if (abs(operands[0]) > maxV)
        {
            cout << "last v : " << abs(operands[0]) << '\n';
            maxV = abs(operands[0]);
        }
        return;
    }

    for (int i = 0; i < 3; i++)
    {
        if (optVisited[i])
        {
            continue;
        }

        optVisited[i] = true;

        vector<long long> operands_ = operands;
        vector<char> operators_ = operators;

        int j = 0;

        for (vector<char>::iterator it = operators_.begin(); it != operators_.end();)
        {
            if (*it == usableOpts[i])
            {
                operands_[j] = calcOpr(operands_[j], operands_[j + 1], *it);
                operands_.erase(operands_.begin() + j + 1);
                operators_.erase(it);
            }
            else
            {
                it++;
                j++;
            }
        }

        decidePriority(depth + 1, operands_, operators_);

        optVisited[i] = false;
    }
}

long long calcOpr(long long t, long long u, char opt)
{
    cout << t << ' ' << opt << ' ' << u << " = ";
    switch (opt)
    {
    case ADD:
        cout << t + u << '\n';
        return t + u;
        break;
    case SUB:
        cout << t - u << '\n';
        return t - u;
        break;
    case MUL:
        cout << t * u << '\n';
        return t * u;
        break;
    default:
        break;
    }
    return -1;
}