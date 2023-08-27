#include <iostream>
#include <queue>
using namespace std;

#define MAXN (100)

int N, M;//문서수, 궁금한 문서 번호

int ans = 0;
struct Document
{
    int index;
    int priority;

    bool operator<(const Document newDoc) const {
        return this->priority < newDoc.priority;
    }
} P[MAXN];//문서 우선순위

int cnt = 0;

priority_queue<Document> documentPq;

void registDocument(int index, int priority){
    Document* document = &P[cnt++];

    document->index = index;
    document->priority = priority;

    documentPq.push(*document);
}


void InputData() {
    
    int priorityInput;

    cin >> N >> M;

    for (int i=0; i<N; i++){
        cin >> priorityInput;
        registDocument(i, priorityInput);
    }
}

void initCase(void){
    ans = 1;
    cnt = 0;
    documentPq = priority_queue<Document>();
}

int main() {
    int T;
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    cin >> T;
    for (int t=1; t<=T; t++){
        initCase();
        InputData();//입력받는 부분

        while (!(documentPq.top().index == M || documentPq.empty()))
        {
            documentPq.pop();
            ans++;
        }
        

        cout << ans << endl;//출력하는 부분
    }
    return 0;
}