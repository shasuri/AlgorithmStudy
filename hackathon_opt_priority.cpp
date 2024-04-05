#include <string>
#include <queue>
#include <iostream>


using namespace std;

const short OPTN = 3;
const short MAXE = 100;

const short PLUS = -1;
const short MINUS = -2;
const short MUL = -3;
const char OPT[OPTN] = {PLUS,MINUS,MUL};

bool optVisited[OPTN] = {true, true, true};
queue<long long> parsedExp;
queue<short> parsedOpt;

void parseExp(string ex);
bool isOpt(char c);
short convertOpt(char c);
void permPriority(short depth);

long long solution(string expression) {
    long long answer = 0;
    
    parseExp(expression);
    permPriority(0);
    
    return answer;
}

void parseExp(string ex){
    string num;
    short len = 0;

    for (auto c : ex)
    {
        if (isOpt(c))
        {
            parsedExp.push(static_cast<long long>(stoi(num)));
            num.clear();
            parsedOpt.push(convertOpt(c));
            optVisited[convertOptIdx(c)] = false;
        }
        else{
            num.push(c);
        }
    }

    if (num.size() > 0)
    {
        parsedExp.push(static_cast<long long>(stoi(num)));
        num.clear();
    }
}

bool isOpt(char c){
    return (c == '+' || c == '-' || c == '*');
}

short convertOpt(char c){
    switch (c)
    {
    case '+':
        return PLUS;
        break;
    case '-':
        return MINUS;
        break;
    case '*':
        return MUL;
        break;
    default:
        break;
    }
    
    return -4;
}

int convertOptIdx(char c){
    switch (c)
    {
    case '+':
        return 0;
        break;
    case '-':
        return 1;
        break;
    case '*':
        return 2;
        break;
    default:
        break;
    }
    
    return -1;
}


void permPriority(short depth, queue<long long>& exp, queue<short>& opts){
    if (depth >= MAXE)
    {
        return;
    }
    
    for (int i = 0; i < MAXE; i++)
    {
        if (!optVisited[i])
        {
            // dfs
            optVisited[i] = true;
            // cout << OPT[i] << " ";
            permPriority(depth+1, getCalcQue(OPT[i], exp, opts));
            optVisited[i] = false;
        }
    }
}

queue<long long> getCalcQue(const char opt, queue<long long>& exp){
    queue<long long> queCalc;
    for (int i = 0; i < exp.size(); i++)
    {
        if (exp[i] == opt)
        {
            queCalc.pop();
            queCalc.push(calcExp(exp[i - 1], exp[i + 1], exp[i]));
        }
        else
        {
            queCalc.push(exp[i]);
        }
    }
    
    return queCalc;
}

long long calcExp(const long long t, const long long u, const long long opt){
    switch (c)
    {
    case PLUS:
        return t + u;
        break;
    case MINUS:
        return t - u;
        break;
    case MUL:
        return t * u;
        break;
    default:
        break;
    }
    
    return -1;
}