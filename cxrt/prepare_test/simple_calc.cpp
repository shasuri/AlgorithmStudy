#include <iostream>
using namespace std;

#define MAX (20)
int N;
int M[MAX + 10];
char op[MAX + 10];

int stk[20];
int sp = 0;



void InputData(){
	cin >> N;
	cin >> M[0];
	for(int i=1; i<N; i++){
		cin >> op[i] >> M[i];
	}
}

void pushNumbers(void){
    stk[sp++] = M[0];

    for (int i = 1; i < N; i++)
    {
        switch (op[i])
        {
        case '+':
            stk[sp++] = M[i];
            break;
        case '-' :
            stk[sp++] = M[i] * (-1);
            break;
        case '*' :
            stk[sp - 1] *= M[i];
            break;
        case '/' :
            stk[sp - 1] /= M[i];
            break;
        default:
            break;
        }
    }
}

int popNumbers(void){

    int sum = 0;

    while (sp != -1)
    {
        // cout << stk[sp-1] << endl;
        sum += stk[--sp];
    }
    return sum;
}

int main(){
	int ans = -1;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	InputData();//입력

    pushNumbers();

	cout << popNumbers() << "\n";

	return 0;
}