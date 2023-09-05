#include <iostream>
#include <queue>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int V, E;
  int a, b, w;
  priority_queue<pair<int, int>> pq;
  vector<pair<int, int>> graph[10005];
  int visit[10005] = {0};
  int answer = 0;

  cin >> V >> E;
  for(int i=0;i<E;i++){
    cin >> a >> b >> w;
    graph[a].push_back({b, w});
    graph[b].push_back({a, w});
  }

  pq.push({0, 1});

  while(!pq.empty()){
    int now = pq.top().second, w = -pq.top().first;
    pq.pop();
    if(visit[now]) continue;

    visit[now] = 1;
    answer += w;

    for(auto p : graph[now]){
      pq.push({-p.second, p.first});
    }
  }

  cout << answer;
}