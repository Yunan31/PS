#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int N, M, K;
int field[10][10];
int A[10][10];
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
vector<int> tree[10][10];
int answer = 0;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> N >> M >> K;

  fill_n(field[0], 10*10, 5);

  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cin >> A[i][j];
    }
  }

  for(int i=0;i<M;i++){
    int x, y, z;
    cin >> x >> y >> z;
    tree[x-1][y-1].push_back(z);
    answer++;
  }

  while(K--){
    vector<tuple<int, int, int>> dead;
    vector<pair<int, int>> spread;
    //봄
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
        int size = tree[i][j].size();
        if(size == 0) continue;
        sort(tree[i][j].begin(), tree[i][j].end());
        
        for(int k=0;k<size;k++){
          if(field[i][j] < tree[i][j][k]){
            dead.push_back({i, j, tree[i][j][k]});
            tree[i][j].erase(tree[i][j].begin()+k);
            size--; k--; answer--;
          }
          else{
            field[i][j] -= tree[i][j][k];
            tree[i][j][k]++;
            if(tree[i][j][k]%5 == 0) spread.push_back({i, j});
          }
        }
      }
    }

    //여름
    for(int i=0;i<dead.size();i++){
      int r = get<0>(dead[i]), c = get<1>(dead[i]), age = get<2>(dead[i]);
      field[r][c] += age/2;
    }

    //가을
    for(int i=0;i<spread.size();i++){
      int x = spread[i].first, y = spread[i].second;

      for(int k=0;k<8;k++){
        int nx = x+dx[k], ny = y+dy[k];
        if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
        tree[nx][ny].push_back(1);
        answer++;
      }
    }
    
    //겨울
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
        field[i][j] += A[i][j];
      }
    }
  }

  cout << answer;

  return 0;
}