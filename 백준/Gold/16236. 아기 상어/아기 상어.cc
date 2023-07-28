#include <iostream>
#include <queue>

using namespace std;

int N;
int map[22][22];
int shark_x, shark_y;
int shark_size = 2, eat_count = 2, answer = 0;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

pair<int, int> eat(){
  queue<pair<int, int>> Q;
  int visit[22][22] = {0};
  vector<pair<int, int>> list;
  int dist = 0;

  Q.push({shark_x, shark_y});
  visit[shark_x][shark_y] = 1;

  while(!Q.empty()){
    int x = Q.front().first, y = Q.front().second;
    Q.pop();
    
    for(int i=0;i<4;i++){
      int nx = x + dx[i], ny = y + dy[i];

      if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
      if(visit[nx][ny]) continue;
      
      if(map[nx][ny] <= shark_size){
        if(map[nx][ny] > 0 && map[nx][ny] < shark_size){
          if(dist == 0) dist = visit[x][y];
          if(dist < visit[x][y]) continue;
          list.push_back({nx, ny});
          continue;
        }
        visit[nx][ny] = visit[x][y] + 1;
        Q.push({nx, ny});
      }
    }
  }

  if(list.empty()){
    return {shark_x, shark_y};
  }
  
  pair<int, int> ret = list[0];
  for(int i=0;i<list.size();i++){
    if(ret > list[i]) ret = list[i];
  }
  answer += dist;
  if(--eat_count == 0){
    shark_size++; eat_count = shark_size;
  }
  return ret;
}

bool is_none(){
  int count = 0;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(map[i][j] == 0 || map[i][j] >= shark_size) count++;
    }
  }
  return count == N*N;
}


int main() {
  cin >> N;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cin >> map[i][j];
      if(map[i][j] == 9){
        shark_x = i; shark_y = j;
      }
    }
  }

  map[shark_x][shark_y] = 0;

  while(!is_none()){
    pair<int, int> next = eat();
    if(next == make_pair(shark_x, shark_y)) break;
    shark_x = next.first; shark_y = next.second;
    map[shark_x][shark_y] = 0;
  }

  cout << answer;
}