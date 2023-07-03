#include <iostream>
#include <vector>
#include <queue>
#define INF 99999999

using namespace std;

vector<pair<int, int>> map[1005];
int dist[1005][1005];
int N, M, X;

int main() {
  cin >> N >> M >> X;

  for(int i=0;i<M;i++){
    int st, ed, w;
    cin >> st >> ed >> w;
    map[st].push_back({ed, w});
  }

  fill_n(dist[0], 1005*1005, INF);

  for(int i=1;i<=N;i++){
    priority_queue<pair<int, int>> pq;
    dist[i][i] = 0;
    pq.push({0, i});

    while(!pq.empty()){
      int cost = -pq.top().first;
      int cur = pq.top().second;
      pq.pop();

      for(int k=0;k<map[cur].size();k++){
        int ncur = map[cur][k].first;
        int ncost = map[cur][k].second;
        if(dist[i][ncur] > cost + ncost){
          dist[i][ncur] = cost + ncost;
          pq.push({-dist[i][ncur], ncur});
        }
      }
    }
  }

  int max_dist = 0;
  for(int i=1;i<=N;i++){
    max_dist = max(max_dist, dist[i][X] + dist[X][i]);
  }

  cout << max_dist;

  return 0;
  
}