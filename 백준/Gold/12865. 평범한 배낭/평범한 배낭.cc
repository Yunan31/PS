#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> object;
int DP[101][100005] = {0};
int N, K;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> N >> K;
  object.push_back({0, 0});
  for(int i=0;i<N;i++){
    int w, v;
    cin >> w >> v;
    object.push_back({w, v});
  }

  for(int i=1;i<=N;i++){
    for(int j=1;j<=K;j++){
      pair<int, int> now = object[i];
      if(j-now.first >= 0) DP[i][j] = max(DP[i-1][j], DP[i-1][j-now.first]+now.second);
      else DP[i][j] = DP[i-1][j];
    }
  }

  cout << DP[N][K];

  return 0;
}