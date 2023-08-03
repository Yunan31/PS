#include <iostream>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int R, C;
char map[22][22];

int dfs(int x, int y, bool check[26]){
  int answer = 0;
  for(int i=0;i<4;i++){
    int nx = x+dx[i], ny = y+dy[i];
    if(nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
    if(check[map[nx][ny]-'A']) continue;
    
    check[map[nx][ny]-'A'] = true;
    answer = max(answer, dfs(nx, ny, check)+1);
    check[map[nx][ny]-'A'] = false;
  }

  return answer;
}


int main() {
  cin >> R >> C;

  for(int i=0;i<R;i++){
    for(int j=0;j<C;j++){
      cin >> map[i][j];
    }
  }

  bool check[26] = {false};
  check[map[0][0]-'A'] = true;

  cout << dfs(0, 0, check)+1;
}