#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
using namespace std;

vector<int> getPi(string p){
    int m = (int)p.size(), j=0;
    // pi를 0으로 초기화
    vector<int> pi(m, 0);
    
    // 서로다른 두 인덱스의 문자 값 비교
    for(int i = 1; i< m ; i++){

        // 일치하지 않을 경우
        while(j > 0 && p[i] !=  p[j])
            // j를 앞으로 당김 (중간단계를 pi 배열로 생략) j가 0이 되거나 일치할때까지 반복, j가 0이 되면 pi[i]에 0을 저장
            j = pi[j-1];
        
        // 일치할 경우
        if(p[i] == p[j])
            // pi[i]의 값에 j값을 저장후 +1
            pi[i] = ++j;
    }

    return pi;
}

vector<int> kmp(string s, string p){
    vector<int> ans;
    // pi 배열 작성
    auto pi = getPi(p);
    int n = (int)s.size(), m = (int)p.size(), j =0;

    // 두 문자열의 인덱스를 변화시켜가며 비교
    for(int i = 0 ; i < n ; i++){
    
         // 일치하지 않을 경우
        while(j>0 && s[i] != p[j])
            // j를 앞으로 당김 (중간단계를 pi 배열로 생략) j가 0이 되거나 일치할때까지 반복
            j = pi[j-1]; 
        
        // 일치할 경우
        if(s[i] == p[j]){

            // 탐색 문자열이 발견될 경우
            if(j==m-1){
                ans.push_back(i-m+1);
                j = pi[j];
            }
            // 탐색 문자열이 불완전하게 발견될 경우
            else{
                j++;
            }
        }
    }
    return ans;
}

int main(){
    string s, p;
    getline(cin, s);
    getline(cin, p);
    auto matched = kmp(s,p);
    printf("%d\n", (int)matched.size());
    for(auto i : matched)
        printf("%d ", i+1);
    return 0;
}

