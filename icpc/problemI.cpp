#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int N;
    cin >> N;

    vector<int> vec;
    for(int i=0; i<2*N; i++){
        int tmp;
        cin >> tmp;
        vec.push_back(tmp);
    }

    sort(vec.begin(), vec.end());
    int minVal = 200000;

    for(int i=0; i<N; i++){
        minVal = min(minVal, vec[i] + vec[vec.size() - (i+1)]);
    }
    cout << minVal;

    return 0;
}