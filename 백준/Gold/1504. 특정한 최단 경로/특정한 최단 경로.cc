#include <iostream>
#include <queue>
#define INF 99999999
#define FASTIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int N, M;
int v1, v2;
vector<pair<int, int>> map[808];

int dijkstra(int start, int end){
  if(start == end) return 0;
  int dist[808];
  fill_n(dist, 808, INF);
  priority_queue<pair<int, int>> pq;
  pq.push({0, start});
  dist[start] = 0;

  while(!pq.empty()){
    int cost = -pq.top().first;
    int cur = pq.top().second;
    pq.pop();
    for(int i=0;i<map[cur].size();i++){
      int ncost = map[cur][i].second;
      int ncur = map[cur][i].first;
      if(dist[ncur] > cost + ncost){
        dist[ncur] = cost + ncost;
        pq.push({-dist[ncur], ncur});
      }
    }
  }

  return dist[end];
}

int main() {
  cin >> N >> M;

  for(int i=0;i<M;i++){
    int st, ed, w;
    cin >> st >> ed >> w;
    map[st].push_back({ed, w});
    map[ed].push_back({st, w});
  }

  cin >> v1 >> v2;

  long long v1_v2 = dijkstra(1, v1) + dijkstra(v1, v2) + dijkstra(v2, N);
  long long v2_v1 = dijkstra(1, v2) + dijkstra(v2, v1) + dijkstra(v1, N);

  long long answer = min(v1_v2, v2_v1);
  if(v1_v2 >= INF && v2_v1 >= INF) answer = -1;
  cout << answer;

  return 0;
}