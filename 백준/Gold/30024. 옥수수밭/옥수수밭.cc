#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int N, M, K;
int map[1005][1005];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int visit[1005][1005] = {0};

int main() {
  cin >> N >> M;

  priority_queue<tuple<int, int, int>> pq;
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      cin >> map[i][j];
      if(i == 0 || i == N-1 || j == 0 || j == M-1){
        pq.push({map[i][j], i, j});
        visit[i][j] = 1;
      }
    }
  }

  cin >> K;

  while(K--){
    int x = get<1>(pq.top()), y = get<2>(pq.top());
    pq.pop();
    cout << x+1 << " " << y+1 << "\n";

    for(int i=0;i<4;i++){
      int nx=x+dx[i], ny=y+dy[i];
      if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
      if(visit[nx][ny]) continue;
      pq.push({map[nx][ny], nx, ny});
      visit[nx][ny] = 1;
    }
  }
}