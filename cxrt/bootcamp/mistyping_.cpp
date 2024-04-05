#include <iostream>
using namespace std;

char str[100000+10];
int len = 0;

void InputData(){
    cin >> str;   
}

int Solve(void){
    int depth = 0;
    int openPar = 0;
    int closePar = 0;

    int i = 0;
    while(str[i] != '\0')
    {
        if (str[i] == '(')
        {
            depth++;
            openPar++;
        }
        else{
            depth--;
            closePar++;
        }

        if (depth == 1)
        {
            openPar = 0;
        }

        if (depth < 0)
        {
            return closePar;
        }
        i++;
    }

    return openPar;
    
}

int main(){
    int ans = -1;

    InputData();// 입력받는 부분

    // 여기서부터 작성
    ans = Solve();
    cout << ans << endl;// 출력하는 부분
    return 0;
}