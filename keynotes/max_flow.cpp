#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int INF = 100000000;
int vertex_size = 6/*문제 정점 갯수*/;
int result;

//경로 기록 배열
//-1은 아직 이 루프에서 방문하지 않았음을 의미
vector<int> d(vertex_size,-1);

//경로 정보 선언
vector<vector<int>> a(vertex_size,vector<int>(vertex_size));

//경로 수용량 선언
vector<vector<int>> c(vertex_size,vector<int>(vertex_size));

//경로 유량 선언
vector<vector<int>> f(vertex_size,vector<int>(vertex_size));

int maxFlow(int start, int end) {

	while(true) {
        queue<int> q;
		q.push(start);
		
        //BFS
        while(!q.empty()) {
			
            int x = q.front();
			q.pop();

			for(int i = 0; i < a[x].size(); i++) {
				int y = a[x][i];
                // 방문하지 않은 노드 중에 용량이 남은 경우 
				if(c[x][y] - f[x][y] > 0 && d[y] == -1) {
					q.push(y);

                    // 경로 저장
					d[y] = x;
                    
                    // 도착지에 도달한 경우
                    if(y == end)
                        break;
				}
			}
		}
        
        // 모든 경로를 찾은 뒤에 탈출
		if(d[end] == -1)
            break;
		
        int flow = INF;
		
        for(int i = end; i != start; i = d[i]) {
            // 거꾸로 최소 유량 탐색 
			flow = min(flow, c[d[i]][i] - f[d[i]][i]);
		}
		
        // 최소 유량만큼 흘려보내기
		for(int i = end; i != start; i = d[i]) {
			f[d[i]][i] += flow;
			f[i][d[i]] -= flow;
		}

		result += flow;
	}

    return result;
}

int main(void) 
{return 0;}