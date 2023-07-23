#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#define INF 99999999

using namespace std;

int TC, N, M, W;

int is_time_travel(int num, vector<tuple<int, int, int>> edge){
  int dist[505];
  fill_n(dist, 505, INF);

  dist[num] = 0;

  for(int k=0;k<N;k++){
    for(int i=0;i<edge.size();i++){
      int cur = get<0>(edge[i]), ncur = get<1>(edge[i]), ncost = get<2>(edge[i]);
      if(dist[ncur] > dist[cur] + ncost){
        dist[ncur] = dist[cur] + ncost;
        if(k == N-1) return -1;
      }
    }
  }

  return 1;
}

int main() {
  cin >> TC;

  while(TC--){
    vector<tuple<int, int, int>> edge;
    cin >> N >> M >> W;

    int S, E, T;
    for(int i=0;i<M;i++){
      cin >> S >> E >> T;
      edge.push_back({S, E, T});
      edge.push_back({E, S, T});
    }

    for(int i=0;i<W;i++){
      cin >> S >> E >> T;
      edge.push_back({S, E, -T});
    }

    string answer = "NO";
    if(is_time_travel(1, edge) == -1){
      answer = "YES";
    }

    cout << answer << "\n";
  }
}