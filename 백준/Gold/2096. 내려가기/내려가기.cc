#include <iostream>
#include <vector>

using namespace std;

int map[100001][3];
int DP_max[2][3] = {0};
int DP_min[2][3];

int main() {
  int N;
  int ans_max = 0, ans_min = 999999;
  vector<vector<int>> next = {
  {0, 1}, {0, 1, 2}, {1, 2}
  };

  cin >> N;
  for(int i=0;i<N;i++){
    for(int j=0;j<3;j++){
      cin >> map[i][j];
    }
  }

  fill_n(DP_min[0], 6, 999999);
  for(int i=0;i<3;i++) { DP_max[0][i] = map[0][i]; DP_min[0][i] = map[0][i]; }

  for(int i=0;i<N-1;i++){
    for(int j=0;j<3;j++){
      for(int k=0;k<next[j].size();k++){
        DP_max[1][next[j][k]] = max(DP_max[1][next[j][k]], DP_max[0][j] + map[i+1][next[j][k]]);
        DP_min[1][next[j][k]] = min(DP_min[1][next[j][k]], DP_min[0][j] + map[i+1][next[j][k]]);
      }
    }

    for(int i=0;i<3;i++){
      DP_max[0][i] = DP_max[1][i];
      DP_min[0][i] = DP_min[1][i];
    }
    for(int i=0;i<3;i++){
      DP_max[1][i] = 0;
      DP_min[1][i] = 999999;
    }
  }

  for(int i=0;i<3;i++){
    ans_max = max(ans_max, DP_max[0][i]);
    ans_min = min(ans_min, DP_min[0][i]);
  }

  cout << ans_max << " " << ans_min;
  return 0;
}