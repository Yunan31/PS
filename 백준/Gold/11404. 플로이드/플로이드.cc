#include <iostream>
#define INF 99999999

using namespace std;

int N, M;
int adj[101][101];
int dist[101][101];

int main() {
  cin >> N >> M;

  fill_n(adj[0], 101*101, INF);
  fill_n(dist[0], 101*101, INF);
  
  for(int i=0;i<M;i++){
    int a, b, w;
    cin >> a >> b >> w;
    adj[a][b] = min(adj[a][b], w);
  }

  for(int i=1;i<=N;i++){
    for(int j=1;j<=N;j++){
      if(i==j) dist[i][j] = 0;
      else if(adj[i][j] != INF) dist[i][j] = adj[i][j]; 
    }
  }

  for(int i=1;i<=N;i++){
    for(int j=1;j<=N;j++){
      for(int k=1;k<=N;k++){
        dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
      }
    }
  }

  for(int i=1;i<=N;i++){
    for(int j=1;j<=N;j++){
      if(dist[i][j] == INF) cout << 0 << " ";
      else cout << dist[i][j] << " ";
    }
    cout << '\n';
  }

  return 0;
}