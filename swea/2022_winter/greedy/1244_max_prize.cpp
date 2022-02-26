// solving
#include <iostream>

using namespace std;

void input(void);
void solve(void);
void pushPrize(int);
void print(int);

int swapLimit;
int maxPrize;

char prizeContainer[7];
int prizeLen;

int main(int argc, char **argv)
{
    int test_case;
    int T;
    // freopen("input.txt", "r", stdin);
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        input();
        // solve();
        print(test_case);
    }
    return 0;
}

void input(void)
{
    int prize;
    cin >> prize >> swapLimit;
    pushPrize(prize);
}

void pushPrize(int prize)
{
    int quot;
    int i = 0;
    do
    {
        prizeContainer[i] = (prize % 10)+'0';
        prize /= 10;
        i++;
    } while (prize != 0);

    prizeContainer[i] = '\0';
    prizeLen = i;
}

void solve(void){
    char maxChar = '0';
    int maxIndex = -1;
    for(int i = 0; i < swapLimit; i++){
        for(int j = 0; j=prizeLen; j++){
            if(prizeContainer[j] > maxChar){
                maxChar = prizeContainer[j]
            }
        }
    }
}

void swap(int i, int j){
    char tmp;
    tmp = prizeContainer[i];
    prizeContainer[i] = prizeContainer[j];
    prizeContainer[j] = tmp;
}

void print(int testCase){
    cout << "#" << testCase << " ";
    for(int i = 0; i < prizeLen; i++){
        cout << prizeContainer[prizeLen-i-1];
    }
    cout << endl;
}