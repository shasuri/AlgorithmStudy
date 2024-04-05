#include <iostream>
#include <string>
using namespace std;

const int MAXL = 1000000;
char stk[MAXL];
int top = 0;

void push(char);
bool isFull(void);
void pop(void);
bool isEmpty(void);
char getTop(void);

int solution(string s)
{
    int answer = -1;

    for (char c : s)
    {
        if (!isEmpty() && (getTop() == c))
        {
            pop();
        }
        else
        {
            push(c);
        }
    }

    if (top == 0)
    {
        answer = 1;
    }
    else
    {
        answer = 0;
    }
    
    return answer;
}

void push(char c){
    if(!isFull()){
        stk[top++] = c;
    }
}

bool isFull(void){
    return top >= MAXL;
}

void pop(void){
    if(!isEmpty()){
        --top;
    }
}

bool isEmpty(void){
    return top <= 0;
}

char getTop(void){
    if(!isEmpty()){
        return stk[top - 1];
    }
}