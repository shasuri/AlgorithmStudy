#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int INF = 10000000;
int vertex_size = 10/*정점갯수*/;

// 간선 정보 선언
vector<vector<pair<int, int>>> a(vertex_size,vector<pair<int,int>>(vertex_size));

vector<int> dijkstra(int start) {
	
	// 최소 비용 선언
	vector<int> d(vertex_size,INF);
	d[start] = 0;
    
    // 힙 선언
	priority_queue<pair<int, int> > pq;

	// 큐에 자기자신으로 가는 경로를 넣음
	pq.push(make_pair(start, 0));
	
	while(!pq.empty()) {
		int current = pq.top().first;
		
		// 힙의 값은 음수이므로 양수화
		int distance = -pq.top().second;
		pq.pop();
		
		// 최단 거리가 아닌 경우 continue
		if(d[current] < distance)
			continue;
		
		// 최단 거리보다 짧거나 같을 경우
		for(int i = 0; i < a[current].size(); i++) {
		
			// 선택된 노드의 인접 노드 
			int next = a[current][i].first; 
			
			// 선택된 노드를 인접 노드로 거쳐서 가는 비용 
			int nextDistance = distance + a[current][i].second;
			
			// 기존의 최단 거리보다 더 짧으면 교체
			if(nextDistance < d[next]) {
				d[next] = nextDistance;

				//짧은 것이 먼저 오게끔 음수화 후 PUSH
				pq.push(make_pair(next, -nextDistance));
			}
		}
	}
	return d;
}
