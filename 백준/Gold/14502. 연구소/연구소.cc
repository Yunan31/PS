#include <algorithm>
#include <iostream>
#include <queue>
#define FASTIO                                                                 \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);

using namespace std;

int N, M;
int map[8][8];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int bfs() {
  queue<pair<int, int>> Q;
  int visit[8][8] = {0};

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (map[i][j] == 2) {
        Q.push({i, j});
        visit[i][j] = 1;
      }
    }
  }

  while (!Q.empty()) {
    int x = Q.front().first, y = Q.front().second;
    Q.pop();
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i], ny = y + dy[i];
      if (nx < 0 || nx >= N || ny < 0 || ny >= M)
        continue;
      if (visit[nx][ny] || map[nx][ny] != 0)
        continue;
      Q.push({nx, ny});
      visit[nx][ny] = 1;
    }
  }

  int safety = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (visit[i][j] == 0 && map[i][j] == 0)
        safety++;
    }
  }

  return safety;
}

int make_wall(int K, pair<int, int> start) {
  if (K == 0) {
    return bfs();
  }
  int answer = 0, flag = 0;
  for (int i = start.first; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if(!flag){ j = start.second; flag++; }
      if(j>=M) continue;
      if (map[i][j] == 0) {
        map[i][j] = 1;
        answer = max(answer, make_wall(K - 1, {i, j + 1}));
        map[i][j] = 0;
      }
    }
  }
  return answer;
}

int main() {
  cin >> N >> M;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      cin >> map[i][j];

  cout << make_wall(3, {0, 0});
}