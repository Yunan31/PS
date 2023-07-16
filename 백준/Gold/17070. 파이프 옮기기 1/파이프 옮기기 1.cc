#include <iostream>
#include <vector>

using namespace std;

//type 0 -> 가로, 1 -> 대각선, 2 -> 세로
int dx[3] = {0, 1, 1};
int dy[3] = {1, 1, 0};
vector<int> available[3] = {
{0, 1}, {0, 1, 2}, {1, 2}
};
int map[17][17];
int N;

int possible(int x, int y, int type){
  int nx = x+dx[type], ny = y+dy[type];
  if(nx < 1 || nx > N || ny < 1 || ny > N) return 0;
  if(map[nx][ny]) return 0;
  return 1;
}

int DFS(int x, int y, int type){
  if(x == N && y == N) return 1;
  int res = 0;
  for(int i=0;i<available[type].size();i++){
    int next_type = available[type][i];
    if(next_type == 1){
      if(possible(x, y, 0) && possible(x, y, 1) && possible(x, y, 2)){
        res += DFS(x+dx[next_type], y+dy[next_type], next_type);
      }
    }
    else{
      if(possible(x, y, next_type)){
        res += DFS(x+dx[next_type], y+dy[next_type], next_type);
      }
    }
  }
  return res;
}

int main() {
  cin >> N;

  for(int i=1;i<=N;i++){
    for(int j=1;j<=N;j++){
      cin >> map[i][j];
    }
  }

  cout << DFS(1, 2, 0);
  return 0;
}