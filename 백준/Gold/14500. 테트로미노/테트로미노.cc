#include <iostream>

using namespace std;

#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int map[505][505];
int visit[505][505] = {0};
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int N, M;

int dfs(int x, int y, int count){
  visit[x][y] = 1;
  if(count == 4) return map[x][y];
  int score = 0;

  for(int i=0;i<4;i++){
    int nx = x+dx[i], ny = y+dy[i];
    if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
    if(!visit[nx][ny]){
      visit[nx][ny] = 1;
      score = max(score, dfs(nx, ny, count+1));
      visit[nx][ny] = 0;
    }
  }

  return map[x][y] + score;
}

int main() {
  FASTIO
  cin >> N >> M;

  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      cin >> map[i][j];
    }
  }

  //4개가 1자 형태로 연결된 경우
  int answer = 0;
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      visit[i][j] = 1;
      answer = max(answer, dfs(i, j, 1));
      visit[i][j] = 0;
    }
  }

  //ㅗ자 바깥범위
  for(int i=0;i<N-2;i++){
    for(int j=0;j<M-1;j++){
      int temp = map[i][j] + map[i+1][j] + map[i+2][j] + map[i+1][j+1];
      answer = max(answer,temp);
    }
  }
  for(int i=0;i<N-1;i++){
    for(int j=0;j<M-2;j++){
      int temp = map[i][j] + map[i][j+1] + map[i][j+2] + map[i+1][j+1];
      answer = max(answer,temp);
    }
  }

  //ㅗ자 안쪽범위
  for(int i=0;i<N-2;i++){
    for(int j=1;j<M;j++){
      int temp = map[i][j] + map[i+1][j] + map[i+2][j] + map[i+1][j-1];
      answer = max(answer,temp);
    }
  }
  for(int i=1;i<N;i++){
    for(int j=0;j<M-2;j++){
      int temp = map[i][j] + map[i][j+1] + map[i][j+2] + map[i-1][j+1];
      answer = max(answer,temp);
    }
  }

  cout << answer;

  return 0;
}