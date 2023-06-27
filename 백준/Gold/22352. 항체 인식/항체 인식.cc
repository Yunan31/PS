#include <iostream>
#include <queue>

using namespace std;

int before[33][33], after[33][33];
int visit[33][33] = {0};
int group[33][33] = {0};
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int N, M;

int bfs(int x, int y, int num){
  queue<pair<int, int>> Q;

  if(visit[x][y]) return 0;

  visit[x][y] = 1;
  group[x][y] = num;
  Q.push({x, y});

  while(!Q.empty()){
    pair<int, int> now = Q.front();
    Q.pop();

    for(int i=0;i<4;i++){
      int nx = now.first+dx[i], ny = now.second+dy[i];
      if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
      if(!visit[nx][ny] && before[nx][ny] == before[x][y]){
        group[nx][ny] = num; visit[nx][ny] = 1;
        Q.push({nx, ny});
      }
    }
  }

  return 1;
}

pair<int, int> get_group_comp_num(){
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      if(before[i][j] != after[i][j]){
        return {group[i][j], after[i][j]};
      }
    }
  }
  return {-1, -1};
}

string solve(int group_num, int comp_num){
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      if(group[i][j] == group_num && after[i][j] != comp_num) return "NO";
      if(before[i][j] != after[i][j] && group[i][j] != group_num) return "NO";
    }
  }
  return "YES";
}

int main() {
  cin >> N >> M;

  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      cin >> before[i][j];
    }
  }

  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      cin >> after[i][j];
    }
  }

  int num = 1;
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      if(bfs(i, j, num)) num++;
    }
  }

  // cout << endl;
  // for(int i=0;i<N;i++){
  //   for(int j=0;j<M;j++){
  //     cout << group[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  pair<int, int> pii = get_group_comp_num();
  string answer = solve(pii.first, pii.second);

  cout << answer;

  return 0;
}