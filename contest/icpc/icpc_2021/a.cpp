#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main(void){
    int N = 0;
    int Q = 0;
    cin >> N >> Q;

    int bs[N];
    for (int i = 0; i < N; i++) {
        cin >> bs[i];
    }

    // int finder[N][N];
    vector<vector<vector<int>>> finder;
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j ++) {
            if (i > j) {
                continue;
            }
            else if (i == j) {
                finder[i][j].push_back(bs[i]);
            }
            else {
                finder[i][j].push_back(bs[i]);
                finder[i][j].push_back(bs[j]);
            }
        }
    }

    int result[Q];
    for (int i = 0; i < Q; i++) {
        int S = 0;
        int E = 0;
        cin >> S >> E;
        vector<int> tmp = finder[S][E];
        // counting
        map<int,int> m;

        for(int j=0;j<tmp.size();j++){
            m[tmp[j]]++;
        }

        int maxFirst = -1;
        int maxSecond = 0;
        
        for(auto it = m.begin() ; it != m.end();++it){
            if(maxSecond < it->second){
                maxSecond = it->second;
                maxFirst = it->first;
            }
            if(maxSecond == it->second && maxFirst < it->first){
                maxFirst = it->first;
            }
        }

        // find max -> int max
        result[i] = maxFirst;
    }

    for(int i = 0; i < Q; i++) {
        cout << result[i] << endl;  //한줄씩 출력
    }
}
