#include <iostream>
#define FASTIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int R, C, T;
int air_up, air_down;
int dust[55][55] = {0};

void turn_on_upper(){
  //위쪽
  int x = air_up, y = 0;
  int dx[4] = {-1, 0, 1, 0};
  int dy[4] = {0, 1, 0, -1};
  int nx = x+dx[0], ny = y+dy[0];
  int i = 0;
  while(!(nx == air_up && ny == 1)){
    int tx = nx+dx[i], ty = ny+dy[i];
    if(tx < 0 || tx > air_up || ty < 0 || ty >= C){
      i++; continue;
    }
    dust[nx][ny] = dust[tx][ty];
    nx = tx; ny = ty;
  }
  dust[nx][ny] = 0;
}

void turn_on_down(){
  //아래쪽
  int x = air_down, y = 0;
  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, 1, 0, -1};
  int nx = x+dx[0], ny = y+dy[0];
  int i = 0;
  while(!(nx == air_down && ny == 1)){
    int tx = nx+dx[i], ty = ny+dy[i];
    if(tx < air_down || tx >= R || ty < 0 || ty >= C){
      i++; continue;
    }
    dust[nx][ny] = dust[tx][ty];
    nx = tx; ny = ty;
  }
  dust[nx][ny] = 0;
}

int main() {
  FASTIO
  cin >> R >> C >> T;

  for(int i=0;i<R;i++){
    for(int j=0;j<C;j++){
      cin >> dust[i][j];
      if(dust[i][j] == -1){
        air_up = i-1; air_down = i;
      }
    }
  }

  int dx[4] = {-1, 1, 0, 0};
  int dy[4] = {0, 0, -1, 1};
  while(T--){
    int spread[55][55] = {0};
    for(int i=0;i<R;i++){
      for(int j=0;j<C;j++){
        if(dust[i][j]/5 == 0) continue;
        spread[i][j] = dust[i][j]/5;
      }
    }

    for(int i=0;i<R;i++){
      for(int j=0;j<C;j++){
        if(spread[i][j] == 0) continue;
        for(int k=0;k<4;k++){
          int nx = i+dx[k], ny = j+dy[k];
          if(nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
          if(dust[nx][ny] == -1) continue;
          dust[i][j] -= spread[i][j];
          dust[nx][ny] += spread[i][j];
        }
      }
    }
    turn_on_upper();
    turn_on_down();
  }

  // cout << endl;
  // for(int i=0;i<R;i++){
  //   for(int j=0;j<C;j++) cout << dust[i][j] << " ";
  //   cout << endl;
  // }

  int answer = 0;
  for(int i=0;i<R;i++){
    for(int j=0;j<C;j++){
      if(dust[i][j] == -1) continue;
      answer += dust[i][j];
    }
  }
  cout << answer;

  return 0;
}