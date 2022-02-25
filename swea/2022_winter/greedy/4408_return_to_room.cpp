#include <iostream>
#include <queue>
using namespace std;

struct Path
{
    int src;
    int dst;
} path[401];

bool operator<(Path t, Path u){
    return t.src > u.src;
}

priority_queue<Path*> pq;
int studentNum;
int pathCount;

void input(void);
void solve(void);
bool checkDuplicated(Path*,Path*);
void print(void);

int main(int argc, char** argv)
{
	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        input();
        solve();
        print();
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

void input(){
    pathCount = 0;
    cin >> studentNum;
    int src,dst,tmp;

    for(int i = 0; i < studentNum; i++){
        cin >> src >> dst;
        if(src > dst){
            tmp = src;
            src = dst;
            dst = tmp;
        }
        
        Path* newPath = &path[pathCount++];
        newPath->src = src;
        newPath->dst = dst;

        pq.push(newPath);  
    }
}

bool checkDuplicated(Path* p, Path* q){
    int pSrc,pDst,qSrc,qDst;
    pSrc = (p->src-1)/2;
    pDst = (p->dst-1)/2;
    qSrc = (q->src-1)/2;
    qDst = (q->dst-1)/2;

        

}

void solve(){
    Path* p;
    Path* q;

    while (!pq.empty())
    {
        p = pq.top();
        pq.pop();
        while (true)
        {
            q = pq.top();

        }
        
    }
    
}