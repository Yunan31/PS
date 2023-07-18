#include <iostream>
#include <queue>

using namespace std;

int map[101][101];
int N, M;
int remain = 0;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs(int x, int y){
  int visit[101][101] = {0};
  queue<pair<int, int>> Q;

  Q.push({x, y});
  visit[x][y] = 1;
  map[x][y] = 2;

  while(!Q.empty()){
    int now_x = Q.front().first, now_y = Q.front().second;
    Q.pop();

    for(int i=0;i<4;i++){
      int nx = now_x+dx[i], ny = now_y+dy[i];
      if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
      if(map[nx][ny] != 1 && visit[nx][ny] == 0){
        map[nx][ny] = 2;
        visit[nx][ny] = 1;
        Q.push({nx, ny});
      }
    }
  }
}

int melting(){
  int total = 0;

  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      if(map[i][j] == 1){
        int cnt = 0;
        for(int k=0;k<4;k++){
          int nx = i+dx[k], ny = j+dy[k];
          if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
          if(map[nx][ny] == 2) cnt++;
        }
        if(cnt >= 2){
          map[i][j] = 0;
          total++;
        }
      }
    }
  }

  return total;
}

int main() {
  cin >> N >> M;
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      cin >> map[i][j];
      if(map[i][j]) remain++;
    }
  }

  int answer = 0;
  while(remain){
    bfs(0, 0);
    remain -= melting();
    answer++;
  }

  cout << answer;
  
}