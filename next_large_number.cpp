#include <string>
#include <vector>

using namespace std;

const int ONE = 1;
int countBinOne(int i);

int solution(int n) {
    int answer = 0;
    const int nBinOne = countBinOne(n);
    int nxt = n;
    
    while(true){
        nxt++;
        if (countBinOne(nxt) == nBinOne)
        {
            return nxt;
        }
    }
    
    return answer;
}

int countBinOne(int i){
    int cnt = 0;
    while(i > 0){
        if(i & ONE){
            cnt++;
        }
        i >>= 1;
    }
    return cnt;
}