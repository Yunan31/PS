#include <iostream>
#include <queue>

using namespace std;

int N, M;
int map[11][11];
int visit[11][11] = {0};
vector<pair<int, int>> graph[7];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs(int x, int y, int num){
  queue<pair<int, int>> Q;
  Q.push({x, y});
  visit[x][y] = 1;

  while(!Q.empty()){
    x = Q.front().first; y = Q.front().second;
    Q.pop();
    map[x][y] = num;
    for(int i=0;i<4;i++){
      int nx = x+dx[i], ny = y+dy[i];
      if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
      if(visit[nx][ny] || !map[nx][ny]) continue;

      Q.push({nx, ny});
      visit[nx][ny] = 1;
    }
  }
}

void get_node(){
  int from, to;
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      
      if(map[i][j] != 0){
        from = map[i][j];
        
        for(int k=0;k<4;k++){
          int nx = i+dx[k], ny = j+dy[k];
          if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

          //다리 연결 시도
          if(map[nx][ny] == 0){
            int count = 0;
            while(map[nx][ny] == 0){
              nx += dx[k]; ny += dy[k];
              if(nx < 0 || nx >= N || ny < 0 || ny >= M) break;
              count++;
            }

            to = map[nx][ny];
            if(count > 1 && to > 0) graph[from].push_back({to, count});
          }
        }
      }
    }
  }
}

int main() {
  cin >> N >> M;
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      cin >> map[i][j];
    }
  }

  int tag = 1;
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      if(map[i][j] && !visit[i][j]){
        bfs(i, j, tag);
        tag++;
      }
    }
  }

  get_node();

  priority_queue<pair<int, int>> pq;
  int visited[7] = {0};
  int answer = 0;

  pq.push({0, 1});

  while(!pq.empty()){
    int now = pq.top().second, dist = -pq.top().first;
    pq.pop();
    if(visited[now]) continue;

    visited[now] = 1;
    answer += dist;

    for(auto next:graph[now]){
      pq.push({-next.second, next.first});
    }
  }

  for(int i=1;i<tag;i++){
    if(!visited[i]){
      answer = -1; break;
    }
  }

  cout << answer;
}