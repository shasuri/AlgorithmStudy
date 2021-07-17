#include <iostream>

using namespace std;

int Answer;
int N = 100000;
int groupCount = 0;
int friends[100000];
int group[100000];

int find(int child){
	if(group[child] == child) 
		return child;
	else 
		return group[child] = find(group[child]);
}

void link(int parent, int child){
	group[find(child)] = find(parent);
	groupCount -= 1;
}

void initGroup(int n){
	for(int i = 0; i < n; i++){
		group[i] = i;
	}
}

void input(void){
	
	cin >> N;
	groupCount = N;

	for(int i = 0; i < N; i++){
		cin >> friends[i];

		if(friends[i] + i < N){
			link(i, friends[i] + i);
		}
	}
}

int solve(void){
	return groupCount;
}

int main(int argc, char** argv)
{
	int T, test_case;
	cin >> T;

	for(test_case = 0; test_case < T; test_case++)
	{

		Answer = 0;

		initGroup(N);
		input();
		Answer = solve();

		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}