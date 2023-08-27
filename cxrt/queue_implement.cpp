#include <iostream>
using namespace std;

#define MAXN ((int)1e4)
int N;//명령개수
int cmd[MAXN + 10];
int a[MAXN + 10];

int que[MAXN + 10];
int wp, rp;
void push(int d){
    que[wp++] = d;
}
void pop() {
    rp++;
}
int front() {
    return que[rp];
}

int size() {
    return wp - rp;
}

bool empty() {
    if (size() <= 0)
    {
        return true;
    }

    return false;
    
}


void Solve(){
	wp = rp = 0;//초기화
	for (int i=0; i<N; i++){
		switch(cmd[i]){
		case 0://읽고 제거
			if (empty()) {
				cout << "E" << endl;
			}
			else{
				cout << front() << endl;
				pop();
			}
			break;
		case 1://저장
			push(a[i]);
			break;
		default://2 : 저장 개수
			cout << size() << endl;
		}
	}
}
void InputData(){
	cin >> N;
	for (int i=0; i<N; i++){
		cin >> cmd[i];
		if (cmd[i] == 1){
			cin >> a[i];
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	InputData();
	Solve();
	return 0;
}