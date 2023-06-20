#include <iostream>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int map[505][505];
int count[505][505] = {0};
int visit[505][505] = {0};
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int M, N;

int dfs(int x, int y){
  if(x == M-1 && y == N-1) return 1;
  int next_x, next_y;
  if(!visit[x][y]){
    visit[x][y] = 1;
    
    for(int i=0;i<4;i++){
      next_x = x+dx[i], next_y = y+dy[i];
      if(next_x>=0 && next_x<M && next_y>=0 && next_y<N){
        if(map[next_x][next_y] < map[x][y]){
          count[x][y] += dfs(next_x, next_y);
        }
      }
    }
  }

  return count[x][y];
}

int main() {
  FASTIO

  cin >> M >> N;

  for(int i=0;i<M;i++){
    for(int j=0;j<N;j++){
      cin >> map[i][j];
    }
  }
  
  cout << dfs(0, 0);

  return 0;
}