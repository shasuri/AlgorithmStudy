#include <iostream>
using namespace std;

char pipeAndLaser[100000 + 10];//쇠막대기와 레이저의 배치를 나타내는 괄호 표현 문자열

void InputData(){
	cin >> pipeAndLaser;
}

int walkPipeAndLaser(void){
    int i = 0;
    int cuttablePipe = 0;

    int cuttedPipe = 0;

    while (pipeAndLaser[i] != '\0')
    {
        if(pipeAndLaser[i] == '('){
            cuttablePipe++;

        }
        else{ // ')'
            cuttablePipe--;
            if (pipeAndLaser[i-1] == '('){
            cuttedPipe += cuttablePipe;
            }
            else{
                cuttedPipe++;
            }
            
        }

        i++;
    }
    return cuttedPipe;
}

int main() {
	int ans;
	InputData();//입력
	
	cout << walkPipeAndLaser() << endl;//출력
	return 0;
}