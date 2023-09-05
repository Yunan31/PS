#include <iostream>
#include <queue>

using namespace std;

int main() {
  int N, M;
  int u, v, d;
  priority_queue<pair<int, pair<int, int>>> pq;
  vector<pair<int, int>> graph[1005];
  int visit[1005] = {0};
  int answer = 0;
  bool type[1005]; //M = true, W = false

  cin >> N >> M;
  for(int i=1;i<=N;i++){
    char ch;
    cin >> ch;
    if(ch == 'M') type[i] = true;
    else type[i] = false;
  }

  for(int i=0;i<M;i++){
    cin >> u >> v >> d;
    graph[u].push_back({v, d});
    graph[v].push_back({u, d});
  }

  pq.push({0, {1, 1}});

  while(!pq.empty()){
    int w = -pq.top().first;
    int from = pq.top().second.first, to = pq.top().second.second;
    pq.pop();
    if(visit[to]) continue;
    if(to != 1 && type[from] == type[to]) continue;

    visit[to] = 1;
    answer += w;

    for(auto p : graph[to]){
      pq.push({-p.second, {to, p.first}});
    }
  }

  for(int i=1;i<=N;i++){
    if(visit[i] == 0){
      answer = -1;
      break;
    }
  }

  cout << answer;
  
}