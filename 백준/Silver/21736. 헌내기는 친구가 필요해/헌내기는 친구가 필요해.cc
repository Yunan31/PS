#include <iostream>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int M, N;
char map[605][605];
int visit[605][605] = {0};
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int dfs(int x, int y){
  int count = 0;
  if(map[x][y] == 'P') count++;
  for(int i=0;i<4;i++){
    int nx=x+dx[i], ny=y+dy[i];
    if(nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
    if(map[nx][ny] != 'X' && !visit[nx][ny]){
      visit[nx][ny] = 1;
      count += dfs(nx, ny);
    }
  }
  return count;
}

int main() {
  FASTIO
  int x, y;
  cin >> M >> N;

  for(int i=0;i<M;i++){
    for(int j=0;j<N;j++){
      cin >> map[i][j];
      if(map[i][j] == 'I'){ x = i; y = j; }
    }
  }

  visit[x][y] = 1;
  int answer = dfs(x, y);
  if(!answer) cout << "TT";
  else cout << answer;

  return 0;
}