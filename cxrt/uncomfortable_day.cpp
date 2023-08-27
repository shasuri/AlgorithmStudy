#include <iostream>
using namespace std;

#define MAXN ((int)8e4)
int N;
int H[MAXN];
int sp = 0;
long long ans = 0;

int getTop(void){
    return (sp > 0) ? H[sp - 1] : -1;
}

void popCow(void){
    sp--;
}

void pushCow(int height){
    while (sp > 0 && getTop() <= height)
    {
        popCow();
    }
    ans += sp;
    H[sp++] = height;
}

void InputData(){
	cin >> N;
    int h;
	for (int i=0; i<N; i++){
		cin >> h;

        pushCow(h);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	InputData();//입력

	//여기서부터 작성

	cout << ans << "\n";//출력
	return 0;
}
