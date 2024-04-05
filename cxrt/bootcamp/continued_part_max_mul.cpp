#include <iostream>
#include <stdio.h>
using namespace std;

int N;
double D[10000+10];

double maxMul = 0;

void InputData(){
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> D[i];
    }
}

double Solve(void){
    double m;
    for (int i = 0; i < N; i++)
    {
        m = 1.0;
        for (int j = i; j < N; j++)
        {
            m *= D[j];

            if (m > maxMul)
            {
                maxMul = m;
            }
        }
    }
    
    return maxMul;
}

int main(){
    double ans = -1;

    InputData();// 입력받는 부분

    // 여기서부터 작성
    ans = Solve();
    printf("%.3lf\n", ans);// 출력하는 부분
    return 0;
}