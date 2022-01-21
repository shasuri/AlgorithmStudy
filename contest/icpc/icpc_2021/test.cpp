#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main(void){
    map<int,int> m;
    
    m[100000]++;
    // cout << m[100000];
    
    int max = 0;
    for(auto it = m.begin() ; it != m.end();++it){
        if(max < it->second){
            max = it->second;
        }
    }
}
