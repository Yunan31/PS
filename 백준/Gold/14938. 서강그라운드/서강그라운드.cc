#include <iostream>
#include <queue>

using namespace std;

int N, M, r;
int item[101];
vector<pair<int, int>> adj[101];

int get_item(int start){
  int dist[101] = {0};
  int answer = 0;
  priority_queue<pair<int, int>> PQ;

  fill_n(dist, 101, 99999);

  dist[start] = 0;
  PQ.push({0, start});

  while(!PQ.empty()){
    int now = PQ.top().second;
    int cost = -PQ.top().first;
    PQ.pop();
    for(int i=0;i<adj[now].size();i++){
      int next = adj[now][i].first, ncost = adj[now][i].second;
      if(dist[next] > cost + ncost){
        dist[next] = cost+ncost;
        PQ.push({-(cost+ncost), next});
      }
    }
  }

  for(int i=1;i<=N;i++){
    if(dist[i] <= M) answer += item[i];
  }

  return answer;
}

int main() {
  cin >> N >> M >> r;

  for(int i=1;i<=N;i++){
    cin >> item[i];
  }

  for(int i=0;i<r;i++){
    int a, b, w;
    cin >> a >> b >> w;
    adj[a].push_back({b, w});
    adj[b].push_back({a, w});
  }

  int answer = 0;

  for(int i=1;i<=N;i++){
    answer = max(answer, get_item(i));
  }

  cout << answer;

  return 0;
}