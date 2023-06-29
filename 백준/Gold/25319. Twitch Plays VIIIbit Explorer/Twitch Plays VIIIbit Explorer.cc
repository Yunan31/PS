#include <iostream>
#include <vector>

using namespace std;

char map[55][55];
char target[1005];
int visit[55][55] = {0};
int N, M, S;
string answer;

pair<int, int> find(char c){
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      if(!visit[i][j] && map[i][j] == c) {
        visit[i][j] = 1;
        return {i, j};
      }
    }
  }
  return {-1, -1};
}

int main() {
  cin >> N >> M >> S;
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      cin >> map[i][j];
    }
  }

  for(int i=0;i<S;i++){
    cin >> target[i];
  }

  int C = 0;
  int nx = 0, ny = 0;
  int lx = 0, ly = 0;
  int cur = 0;
  vector<char> temp;
  while(1){
    pair<int, int> now = find(target[cur]);
    int tx = now.first, ty = now.second;
    if(now.first == -1){
      nx = lx; ny = ly;
      tx = N-1; ty = M-1; temp.clear();
    }
    if(nx - tx < 0) for(int i=0;i<-(nx-tx);i++) temp.push_back('D');
    else for(int i=0;i<nx-tx;i++) temp.push_back('U');
    if(ny - ty < 0) for(int i=0;i<-(ny-ty);i++) temp.push_back('R');
    else for(int i=0;i<ny-ty;i++) temp.push_back('L');
    if(now.first == -1){
      for(int i=0;i<temp.size();i++){
        answer.push_back(temp[i]);
      }
      break;
    }
    temp.push_back('P');
    nx = tx; ny = ty;
    cur++;
    if(cur == S) {
      cur = 0; C++;
      lx = nx; ly = ny;
      for(int i=0;i<temp.size();i++) answer.push_back(temp[i]);
      temp.clear();
    }
  }

  cout << C << " " << answer.size() << "\n";
  for(int i=0;i<answer.size();i++) cout << answer[i];
  return 0;
}