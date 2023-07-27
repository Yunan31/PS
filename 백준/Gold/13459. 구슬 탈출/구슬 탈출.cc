#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int N, M;
char map[11][11];
int visit[11][11][11][11] = {0};
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

pair<int, int> move(pair<int, int> ball, int type){
  int nx = ball.first + dx[type], ny = ball.second + dy[type];

  if(nx < 0 || nx >= N || ny < 0 || ny >= M) return ball;
  if(map[nx][ny] == '#') return ball;
  if(map[nx][ny] == 'O') return {nx, ny};

  pair<int, int> next;
  next = move({nx, ny}, type);
  return next;
}

bool is_hall(pair<int, int> pos){
  if(map[pos.first][pos.second] == 'O') return true;
  return false;
}

bool who_first(pair<int, int> red, pair<int, int> blue, int type){
  switch(type){
    case 0:
      if(red.first < blue.first) return true;
      return false;
    case 1:
      if(red.first > blue.first) return true;
      return false;
    case 2:
      if(red.second < blue.second) return true;
      return false;
    case 3:
      if(red.second > blue.second) return true;
      return false;
  }
}

int main() {
  queue<tuple<pair<int, int>, pair<int, int>, int>> Q;
  pair<int, int> red, blue;
  int answer = 0;
  
  cin >> N >> M;

  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      cin >> map[i][j];
      if(map[i][j] == 'B'){
        blue = {i, j};
        map[i][j] = '.';
      }
      else if(map[i][j] == 'R'){
        red = {i, j};
        map[i][j] = '.';
      }
    }
  }

  visit[red.first][red.second][blue.first][blue.second] = 1;
  Q.push({red, blue, 0});

  while(!Q.empty()){
    red = get<0>(Q.front()); blue = get<1>(Q.front());
    int count = get<2>(Q.front());
    Q.pop();

    pair<int, int> tmp_red, tmp_blue;
    
    if(count > 9) continue;
    if(answer) break;

    // cout << "red: " << red.first << " " << red.second << " ";
    // cout << "blue: " << blue.first << " " << blue.second << " " << count << endl;
    
    for(int i=0;i<4;i++){
      if(who_first(red, blue, i)){
        tmp_red = move(red, i);
        if(!is_hall(tmp_red)){
          map[tmp_red.first][tmp_red.second] = '#';
          tmp_blue = move(blue, i);
          map[tmp_red.first][tmp_red.second] = '.';
        }
        else tmp_blue = move(blue, i);
  
        if(is_hall(tmp_blue)) continue;
        if(is_hall(tmp_red) && !is_hall(tmp_blue)){
          answer = 1; break;
        }
        if(!visit[tmp_red.first][tmp_red.second][tmp_blue.first][tmp_blue.second]){
          visit[tmp_red.first][tmp_red.second][tmp_blue.first][tmp_blue.second] = 1;
          Q.push({tmp_red, tmp_blue, count+1});
        }
      }
      else{
        tmp_blue = move(blue, i);
        if(!is_hall(tmp_blue)){
          map[tmp_blue.first][tmp_blue.second] = '#';
          tmp_red = move(red, i);
          map[tmp_blue.first][tmp_blue.second] = '.';
        }
        else tmp_red = move(red, i);

        if(is_hall(tmp_blue)) continue;
        if(is_hall(tmp_red) && !is_hall(tmp_blue)){
          answer = 1; break;
        }
        if(!visit[tmp_red.first][tmp_red.second][tmp_blue.first][tmp_blue.second]){
          visit[tmp_red.first][tmp_red.second][tmp_blue.first][tmp_blue.second] = 1;
          Q.push({tmp_red, tmp_blue, count+1});
        }
      }
    }
  }

  cout << answer;

  return 0;
}