#include <cmath>
#include <iostream>

using namespace std;

unsigned long long getDot(unsigned long long, unsigned long long );

long long solution(int r1, int r2) {
    long long answer = 0;

    unsigned long long r1Dot = 0;
    unsigned long long r2Dot = 0;

    for(int x = 1; x < r1; x++){
        r1Dot += getDot(r1, x);
    }
    
    for(int x = 1; x < r2; x++){
        r2Dot += getDot(r2, x);
    }

    answer = (r2Dot - r1Dot) * 4 + 8;

    return answer;
}

unsigned long long getDot(unsigned long long r, unsigned long long x){
    return sqrt(pow(r,2) - pow(x,2));
}
