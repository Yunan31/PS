#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int N, X, x, y;
int field[2001][2001], water[2001][2001] = {0};
//int visit[2001][2001] = {0};
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> N >> X >> x >> y;
  for(int i=1;i<=N;i++){
    for(int j=1;j<=N;j++){
      cin >> field[i][j];
    }
  }

  water[x][y] = X;

  //int count = 0;
  priority_queue<tuple<int, int, int>> pq;
  for(int i=1;i<=N;i++){
    for(int j=1;j<=N;j++){
      if(water[i][j] > 1) pq.push({field[i][j], i, j});
    }
  }
  
  while(!pq.empty()){
    int a = get<1>(pq.top()), b = get<2>(pq.top());
    pq.pop();
    
    for(int i=0;i<4;i++){
      int nx = a+dx[i], ny = b+dy[i];
      if(nx < 1 || nx > N || ny < 1 || ny > N) continue;
      //if(visit[nx][ny]) continue;

      if(field[a][b] == field[nx][ny]){
        if(water[a][b] - 1 > water[nx][ny]){
          water[nx][ny] = water[a][b] - 1;
          //visit[nx][ny] = 1;
          if(water[a][b] - 1 > 1) pq.push({field[nx][ny], nx, ny});
        }
      }
      else if(field[a][b] > field[nx][ny]){
        if(water[nx][ny] < X){
          water[nx][ny] = X;
          //visit[nx][ny] = 1;
          pq.push({field[nx][ny], nx, ny});
        }
      }
    }
  }
  //cout << endl;
  int answer = 0;
  for(int i=1;i<=N;i++){
    for(int j=1;j<=N;j++){
      //cout << water[i][j] << " ";
      if(water[i][j]) answer++;
    }
    //cout << endl;
  }
  cout << answer;
}