#include <iostream>
#include <queue>
#include <algorithm>
#define INF 99999999

using namespace std;

int main() {
  int T;
  cin >> T;

  while(T--){
    int n, m, t;
    int start, g, h;
    cin >> n >> m >> t;
    cin >> start >> g >> h;
    int dist[n+1];
    int need;
    vector<pair<int, int>> graph[n+1];
    vector<int> hubo;
    priority_queue<pair<int, int>> pq;

    for(int i=0;i<m;i++){
      int a, b, d;
      cin >> a >> b >> d;
      graph[a].push_back({b, d});
      graph[b].push_back({a, d});
    }

    for(int i=0;i<graph[g].size();i++){
      if(graph[g][i].first == h) need = graph[g][i].second;
    }

    for(int i=0;i<t;i++){
      int k;
      cin >> k;
      hubo.push_back(k);
    }

    fill_n(dist, n+1, INF);

    dist[start] = 0;
    pq.push({0, start});

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

    int far, near;

    if(dist[g] > dist[h]){
      far = g; near = h;
    }
    else{
      far = h; near = g;
    }

    int sub_dist[n+1];
    fill_n(sub_dist, n+1, INF);

    sub_dist[far] = 0;
    pq.push({0, far});

    while(!pq.empty()){
      int cur = pq.top().second, cost = -pq.top().first;
      pq.pop();
      for(int i=0;i<graph[cur].size();i++){
        int ncur = graph[cur][i].first, ncost = graph[cur][i].second;
        if(sub_dist[ncur] > cost + ncost){
          sub_dist[ncur] = cost + ncost;
          pq.push({-sub_dist[ncur], ncur});
        }
      }
    }

    sort(hubo.begin(), hubo.end());

    for(int i=0;i<hubo.size();i++){
      if(dist[near] + need + sub_dist[hubo[i]] == dist[hubo[i]]){
        cout << hubo[i] << " ";
      }
    }
    cout << '\n';
  }
}