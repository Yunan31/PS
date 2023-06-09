#include <iostream>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int T, M, N, K, X, Y;

int dfs(int x, int y, int visit[][55], int map[][55]){
  int count = 0;
  if(visit[x][y] != 0)
    return 0;

  visit[x][y] = 1;
  
  if(map[x][y] != 0){
    int next_x, next_y;
    for(int i=0;i<4;i++){
      next_x = x + dx[i]; next_y = y + dy[i];
      if(next_x >= 0 && next_x < M && next_y >= 0 && next_y < N)
        count += dfs(next_x, next_y, visit, map);
    }
    return count + 1;
  }
  return 0;
}

int main() {
  int count;
  cin >> T;

  while(T--){
    int visit[55][55] = {0};
    int map[55][55] = {0};

    cin >> M >> N >> K;
    while(K--){
      cin >> X >> Y;
      map[X][Y] = 1;
    }

    count = 0;
    for(int i=0;i<M;i++){
      for(int j=0;j<N;j++){
        int check = dfs(i, j, visit, map);
        if(check) count++;
      }
    }

    cout << count << "\n";
  }
}