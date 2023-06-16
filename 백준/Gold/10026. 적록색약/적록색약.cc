#include <iostream>

using namespace std;

char picture[105][105];
int visit[105][105] = {0};
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int N;

int normal(int x, int y, char color){
  for(int i=0;i<4;i++){
    int next_x=x+dx[i], next_y=y+dy[i];
    if(!visit[next_x][next_y] && next_x >= 0 && next_x < N && next_y >= 0 && next_y < N){
      if(picture[next_x][next_y] == color){
        visit[next_x][next_y] = 1;
        normal(next_x, next_y, color);
      }
    }
  }
  
  return 1;
}

int weakness(int x, int y, char color){
  int type = 0;

  if(color == 'R' || color == 'G') type = 1;
  
  for(int i=0;i<4;i++){
    int next_x=x+dx[i], next_y=y+dy[i];
    if(!visit[next_x][next_y] && next_x >= 0 && next_x < N && next_y >= 0 && next_y < N){
      if(type){
        if(picture[next_x][next_y] == 'R' || picture[next_x][next_y] == 'G'){
          visit[next_x][next_y] = 1;
          weakness(next_x, next_y, color);
        }
      }
      else{
        if(picture[next_x][next_y] == 'B'){
          visit[next_x][next_y] = 1;
          weakness(next_x, next_y, color);
        }
      }
    }
  }
  
  return 1;
}


int main() {
  int section_normal = 0, section_weakness = 0;
  char cell;

  cin >> N;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cin >> cell;
      picture[i][j] = cell;
    }
  }

  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(!visit[i][j]){
        visit[i][j] = 1;
        section_normal += normal(i, j, picture[i][j]);
      }
    }
  }

  fill(visit[0], visit[0]+(105*105), 0);

  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(!visit[i][j]){
        visit[i][j] = 1;
        section_weakness += weakness(i, j, picture[i][j]);
      }
    }
  }

  cout << section_normal << " " << section_weakness;

  return 0;
}