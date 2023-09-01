#include <iostream>
using namespace std;
#define MAXN ((int)1e5)
int N;//빌딩수
int H[MAXN+10];//빌딩높이
int sol[MAXN+10];//각 빌딩에서 보이는 빌딩 번호

struct Building
{
    int indexViewing;
    int height;
    int index;
}Skyline[MAXN];
int sp = 0;

Building noBuilding;


void InputData() {
	cin >> N;
	for (int i=0; i<N; i++){
		cin >> H[i];
	}
}
void OutputData() {
	while (sp > 0)
    {
		cout << Skyline[--sp].indexViewing + 1 << endl;
    }
}

Building* pushNewBuilding(int index, int indexViewing){
    Building* bp = &Skyline[sp];
    bp->indexViewing = indexViewing;
    bp->index = index;
    bp->height = H[index];
    sp++;

    return bp;
}

Building* getViewingBuilding(int indexViewing){
    if (indexViewing == -1)
    {
        return &noBuilding;
    }
    
    return &Skyline[N - 1 - indexViewing];
}

int getIndexViewing(int height, int index){
    
    Building* viewingBuilding = getViewingBuilding(index + 1);
    // cout << height << " " << viewingBuilding->height << endl;
    while (viewingBuilding->index > -1 && viewingBuilding->height <= height)
    {           
        viewingBuilding = getViewingBuilding(viewingBuilding->indexViewing);
    }
    return viewingBuilding->index;
}

void registSkyline(){
    
    pushNewBuilding(N-1, -1); // last building

    for (int i = N-2; i > -1; i--)
    {
        pushNewBuilding(i, getIndexViewing(H[i], i));
    }
    
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
    InputData();//입력받는 부분
    
    noBuilding.index = -1;
	registSkyline();

	OutputData();//출력하는 부분
	return 0;
}