#include <iostream>
#include <queue>
#define INF 999999999

using namespace std;

int main() {
  int N, E, start, end;
  vector<pair<int, int>> adj[1001];
  int dist[1001], visit[1001] = {0};
  priority_queue<pair<int, int>> PQ;
  cin >> N >> E;
  for(int i=0;i<E;i++){
    int a, b, w;
    cin >> a >> b >> w;
    adj[a].push_back({b, w});
    //adj[b].push_back({a, w});
  }

  cin >> start >> end;

  fill_n(dist, 1001, INF);
  dist[start] = 0; visit[start] = 0;
  PQ.push({0, start});

  while(!PQ.empty()){
    int cost = -PQ.top().first;
    int cur = PQ.top().second;
    PQ.pop();
    if(visit[cur]) continue;
    visit[cur]++;
    
    for(int i=0;i<adj[cur].size();i++){
      int next = adj[cur][i].first;
      int ncost = adj[cur][i].second;
      if(dist[next] > cost + ncost){
        dist[next] = cost + ncost;
        PQ.push({-dist[next], next});
      }
    }
  }

  cout << dist[end];

  return 0;

}