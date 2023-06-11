#include <iostream>
#include <queue>

using namespace std;

int tomato[1005][1005];
int visit[1005][1005] = {0};

int check(int M, int N){
    for(int i=0;i<N;i++){
      for(int j=0;j<M;j++){
        if(tomato[i][j] == 0) return 0;
      }
    }
  return 1;
}

int main() {
  ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
  
  int M, N;
  queue<pair<int, int>> Q;

  cin >> M >> N;

  int grown, q_count = 0;
    for(int i=0;i<N;i++){
      for(int j=0;j<M;j++){
        cin >> grown;
        tomato[i][j] = grown;
        if(grown == 1){
          q_count++;
          Q.push(make_pair(i, j));
        }
      }
    }

  if(check(M, N)){
    cout << "0"; return 0;
  }

  int date = -1;
  int x, y, next_q_count = 0;
  int dx[] = {-1, 1, 0, 0};
  int dy[] = {0, 0, -1, 1};

  while(!Q.empty()){
    auto now = Q.front();
    x = now.first; y = now.second;
    Q.pop();
    q_count--;
    //cout << "x: " << x << " y: " << y << " count: " << q_count << endl;

    for(int i=0;i<4;i++){
      int new_x = x+dx[i], new_y = y+dy[i];
      if(new_x < 0 || new_x >= N || new_y < 0 || new_y >= M)
        continue;

      if(tomato[new_x][new_y] == 0 && visit[new_x][new_y] == 0){
        tomato[new_x][new_y] = 1;
        visit[new_x][new_y] = 1;
        next_q_count++;
        Q.push(make_pair(new_x, new_y));
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

  if(!check(M, N)){
    cout << "-1"; return 0;
  }

  cout << date;

  return 0;
}