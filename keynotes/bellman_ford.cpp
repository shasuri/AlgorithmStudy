#include <iostream>
#include <vector>

using namespace std;

int vertex_size = 5/*문제의 정점 갯수*/;
int edge_size = 10/*문제의 간선 갯수*/;
int INF = 10000000;

bool bellmanFord(void)
{
    vector<int> dist(vertex_size+1,INF);
    vector<vector<int>> edge(edge_size,vector<int>(3));

    //초기 시작정점을 1번 노드로 설정
    dist[1] = 0;

    //RELAX 시행
    for (int i = 1; i <= vertex_size - 1; i++)
    {
        for (int j = 0; j < edge.size(); j++)
        {
            int src = edge[j][0];
            int dst = edge[j][1];
            int cost = edge[j][2];
 
            //시작 정점이 아직 무한일 경우 continue
            if (dist[src] == INF)
                continue;
            
            // 기존 경로의 비용보다 이 경로의 비용이 더 낮으면 대체
            if (dist[dst] > dist[src] + cost)
                dist[dst] = dist[src] + cost;
        }
    }
 
    for (int i = 0; i < edge.size(); i++)
    {
        int src = edge[i][0];
        int dst = edge[i][1];
        int cost = edge[i][2];

        //시작 정점이 아직 무한일 경우 continue
        if (dist[src] == INF)
            continue;
        
        // 최종 경로의 비용보다 더 낮게 측정 될때
        if (dist[dst] > dist[src] + cost)
        {
            // 음의 사이클 존재
            return true;
        }
    }

    // 음의 사이클이 존재하지 않음
    return false;
}

int main(void) {return 0;}
