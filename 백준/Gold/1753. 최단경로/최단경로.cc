#include <iostream>
#include <queue>
#define INF 9999999

using namespace std;

int main() {
  int V, E, K;
  vector<pair<int, int>> graph[20005];
  priority_queue<pair<int, int>> pq;
  int dist[20005];

  cin >> V >> E >> K;
  for(int i=0;i<E;i++){
    int u, v, w;
    cin >> u >> v >> w;
    graph[u].push_back({v, w});
  }

  fill_n(dist, 20005, INF);

  pq.push({0, K});
  dist[K] = 0;

  while(!pq.empty()){
    int cur = pq.top().second, cost = -pq.top().first;
    pq.pop();
    
    for(int i=0;i<graph[cur].size();i++){
      int ncur = graph[cur][i].first, ncost = graph[cur][i].second;
      if(dist[ncur] > cost + ncost){
        dist[ncur] = cost + ncost;
        pq.push({-dist[ncur], ncur});
      }
    }
  }

  for(int i=1;i<=V;i++){
    if(dist[i] == INF) cout << "INF\n";
    else cout << dist[i] << "\n";
  }

  return 0;
}