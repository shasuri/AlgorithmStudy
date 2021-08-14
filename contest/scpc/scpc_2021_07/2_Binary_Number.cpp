#include <iostream>
#include <string>

using namespace std;

int Answer, bitLen, dist;
int bitB;
string inputB;
int minA, zeroA, outputA;

int binaryToDecimal(string n)
{
    string num = n;
    int dec_value = 0;
 
    // Initializing base value to 1, i.e 2^0
    int base = 1;
 
    int len = num.length();
    for (int i = len - 1; i >= 0; i--) {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }
 
    return dec_value;
}

void input(){
	cin >> bitLen >> dist;
	cin >> inputB;
	bitB = binaryToDecimal(inputB);
}

void solve(){
	minA = 0;
	zeroA = 2^bitLen - 1;

	for(int i = 0;i < bitLen - dist; i++){
		if(inputB[i] == '1'){
			minA += 2^(bitLen - i - dist);
		}
	}

	for(int i = 0; i < dist; i++){
		if(input)
	}
}


int main(int argc, char** argv)
{
	int T, test_case;

    

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = 0;

		input();

		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;
}