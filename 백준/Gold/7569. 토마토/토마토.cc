#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int tomato[105][105][105];
int visit[105][105][105] = {0};

int check(int M, int N, int H){
  for(int k=0;k<H;k++){
    for(int i=0;i<N;i++){
      for(int j=0;j<M;j++){
        if(tomato[i][j][k] == 0) return 0;
      }
    }
  }
  return 1;
}

int main() {
  int M, N, H;
  queue<tuple<int, int, int>> Q;

  cin >> M >> N >> H;

  int grown, q_count = 0;
  for(int k=0;k<H;k++){
    for(int i=0;i<N;i++){
      for(int j=0;j<M;j++){
        cin >> grown;
        tomato[i][j][k] = grown;
        if(grown == 1){
          q_count++;
          Q.push(make_tuple(i, j, k));
        }
      }
    }
  }

  if(check(M, N, H)){
    cout << "0"; return 0;
  }

  int date = -1;
  int x, y, z, next_q_count = 0;
  int dx[6] = {-1, 1, 0, 0, 0, 0};
  int dy[6] = {0, 0, -1, 1, 0, 0};
  int dz[6] = {0, 0, 0, 0, -1, 1};

  while(!Q.empty()){
    auto now = Q.front();
    x = get<0>(now); y = get<1>(now); z = get<2>(now);
    Q.pop();
    q_count--;
    //cout << "x: " << x << " y: " << y << " z: " << z << " count: " << q_count << endl;

    for(int i=0;i<6;i++){
      int new_x = x+dx[i], new_y = y+dy[i], new_z = z+dz[i];
      if(new_x < 0 || new_x >= N || new_y < 0 || new_y >= M || new_z < 0 || new_z >= H)
        continue;

      if(tomato[new_x][new_y][new_z] == 0 && visit[new_x][new_y][new_z] == 0){
        tomato[new_x][new_y][new_z] = 1;
        visit[new_x][new_y][new_z] = 1;
        next_q_count++;
        Q.push(make_tuple(new_x, new_y, new_z));
      }
    }
        
    if(!q_count) {
      date++; q_count = next_q_count; next_q_count = 0;
    }
  }
  
  // for(int k=0;k<H;k++){
  //   for(int i=0;i<N;i++){
  //     for(int j=0;j<M;j++){
  //       cout << tomato[i][j][k] << " ";
  //     }
  //     cout << endl;
  //   }
  //   cout << endl;
  // }

  if(!check(M, N, H)){
    cout << "-1"; return 0;
  }

  cout << date;

  return 0;
}