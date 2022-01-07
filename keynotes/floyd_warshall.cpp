#include <iostream>
#include <vector>
using namespace std;

int vertex_size = 4/*문제정점 갯수*/;
int INF = 10000000;

// 자료 배열을 초기화합니다. 
vector<vector<int>> a(vertex_size,vector<int>(vertex_size));

vector<vector<int>> floydWarshall(void) {
    // 결과 그래프 선언
    vector<vector<int>> d(vertex_size,vector<int>(vertex_size));
	
	// 결과 그래프 초기화
	for(int i = 0; i < vertex_size; i++){
		for(int j = 0; j < vertex_size; j++) {
			d[i][j] = a[i][j];
		}
	}
	
	// 거쳐가는 노드 순회
	for(int k = 0; k < vertex_size; k++) {
		// 출발 노드 순회
		for(int i = 0; i < vertex_size; i++) {
			// 도착 노드 순회
			for(int j = 0; j < vertex_size; j++) {
				
                //k를 거쳐서 j로가는 비용 vs i에서 j로 바로가는 비용
                if(d[i][k] + d[k][j] < d[i][j])
                {
					d[i][j] = d[i][k] + d[k][j];
				}
                //이 과정을 k를 바꿔가며 테이블을 갱신
			}
		} 
	} 
    return d;
}

int main(void) {
	return 0;
}