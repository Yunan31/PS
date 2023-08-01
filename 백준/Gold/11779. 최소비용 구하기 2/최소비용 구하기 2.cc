#include <iostream>
#include <queue>
#define INF 999999999

using namespace std;

int main() {
  int N, E, start, end;
  vector<pair<int, int>> adj[1001];
  int dist[1001], next[1001];
  vector<int> answer;
  priority_queue<pair<int, int>> PQ;
  cin >> N >> E;
  for(int i=0;i<E;i++){
    int a, b, w;
    cin >> a >> b >> w;
    adj[a].push_back({b, w});
  }

  cin >> start >> end;

  fill_n(dist, 1001, INF);
  dist[start] = 0;
  next[start] = 0;
  PQ.push({0, start});

  while(!PQ.empty()){
    int cost = -PQ.top().first;
    int cur = PQ.top().second;
    PQ.pop();
    
    if(cost > dist[cur]) continue;
    
    for(int i=0;i<adj[cur].size();i++){
      int ncur = adj[cur][i].first;
      int ncost = adj[cur][i].second;
      
      if(dist[ncur] > cost + ncost){
        dist[ncur] = cost + ncost;
        next[ncur] = cur;
        PQ.push({-dist[ncur], ncur});
      }
    }
  }

  int cur = next[end];
  answer.push_back(end);
  while(cur){
    answer.push_back(cur);
    cur = next[cur];
  }

  cout << dist[end] << '\n';
  cout << answer.size() << '\n';

  for(int i=answer.size()-1;i>=0;i--){
    cout << answer[i] << " ";
  }

  return 0;

}