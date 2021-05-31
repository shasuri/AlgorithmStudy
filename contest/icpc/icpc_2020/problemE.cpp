#include <iostream>
using namespace std;
int ds[500001];

void init(int N){
    for(int i=0; i<N; i++){
        ds[i] = -1;
    }
}

int find(int i){
    if(ds[i] < 0)
        return i;
    else{
        int parent = find(ds[i]);
        ds[i] = parent;
        return ds[i];
    }
        
}

int unions(int a, int b){
    int pa = find(a);
    int pb = find(b);

    if(pa == pb){
        return 1;
    }
    else{
        ds[pa] += ds[pb];
        ds[pb] = pa;
        return 0;
    }
}

int main(){
    int N, M;
    cin >> N >> M;

    init(N);

    for(int i=1; i<=M; i++){
        int s, d;
        cin >> s >> d;
        int done = unions(s, d);

        if(done){
            cout << i;
            return 0;
        }
    }
    // cout << "\n";
    // for(int i=0; i<N; i++){
    //     cout << ds[i] << " ";
    // }
    // cout << "-------------------------\n";
    cout << 0;
    return 0;
}