#include <iostream>
#include <queue>
#define INF 9999999

using namespace std;

int N, M;
int map[1001][1001];
int dist[2][1001][1001];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs(int x, int y, int type){
  queue<pair<int, int>> Q;
  int visit[1001][1001] = {0};

  visit[x][y] = 1;
  Q.push({x, y});
  dist[type][x][y] = 1;

  while(!Q.empty()){
    pair<int, int> now = Q.front();
    Q.pop();
    for(int i=0;i<4;i++){
      int nx = now.first + dx[i], ny = now.second + dy[i];
      if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
      if(map[nx][ny] || visit[nx][ny]) continue;
      visit[nx][ny] = 1;
      Q.push({nx, ny});
      dist[type][nx][ny] = dist[type][now.first][now.second] + 1;
    }
  }
}

int wall_dist(int x, int y){
  int min_dist = INF;
  for(int i=0;i<4;i++){
    int nx = x+dx[i], ny = y+dy[i];
    if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
    if(!dist[0][nx][ny]) continue;
    for(int k=0;k<4;k++){
      int tx = x+dx[k], ty = y+dy[k];
      if(tx < 0 || tx >= N || ty < 0 || ty >= M) continue;
      if(!dist[1][tx][ty] || i == k) continue;
      min_dist = min(min_dist, dist[0][nx][ny] + dist[1][tx][ty] + 1);
    }
  }
  return min_dist;
}

int main() {
  cin >> N >> M;
  for(int i=0;i<N;i++){
    string str;
    cin >> str;
    for(int j=0;j<M;j++){
      map[i][j] = str[j] - '0';
    }
  }

  bfs(0, 0, 0);
  bfs(N-1, M-1, 1);

  int answer = INF;
  int count = 0;
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      if(map[i][j]){
        answer = min(answer, wall_dist(i, j));
      }
      else count++;
    }
  }

  if(count == N*M) answer = dist[0][N-1][M-1];
  if(answer == INF) answer = -1;
  cout << answer;
  
  return 0;
}