#include <string>
#include <vector>

using namespace std;

const short MAXS = 30;

bool losts[MAXS];
bool reserves[MAXS];

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    short cantReceive = 0;

    for(auto l : lost){
        losts[l - 1] = true;
    }
    
    for(auto r : reserve){
        reserves[r - 1] = true;
    }
    
    for(short l = 0; l < n; l++){
        if (!losts[l])
        {
            continue;
        }

        if(l - 1 >= 0 && reserves[l - 1]){
            reserves[l - 1] = false;
            continue;
        }
        
        if(reserves[l]){
            reserves[l] = false;
            continue;
        }

        if (l + 1 < n && reserves[l + 1])
        {
            reserves[l + 1] = false;
            continue;
        }

        cantReceive++;
    }

    answer = static_cast<int>(n - cantReceive);
    return answer;
}