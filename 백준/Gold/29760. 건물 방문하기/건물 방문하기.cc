#include <iostream>
#include <vector>
#include <algorithm>
#define INF 99999999

using namespace std;

int N, H, W;
int max_h = 1;
vector<int> floor[1005];
int DP[1005][105];

int main() {
  cin >> N >> H >> W;
  for(int i=0;i<N;i++){
    int h, w;
    cin >> h >> w;
    floor[h].push_back(w);
    max_h = max(max_h, h);
  }

  fill_n(DP[0], 1005*105, INF);

  for(int i=1;i<=H;i++){
    sort(floor[i].begin(), floor[i].end());
  }

  int answer = INF;
  DP[1][1] = 1;
  for(int h=1;h<=max_h;h++){
    if(floor[h].size() == 0){
      for(int w=1;w<=W;w++){
        if(DP[h][w] == INF) continue;
        DP[h+1][w] = DP[h][w] + 100;
      }
      continue;
    }
    
    int l = floor[h][0], r = floor[h][floor[h].size()-1];
    
    if(h == 1){
      DP[h+1][r] = DP[h][1] + (r-1) + 100;
    }
    for(int w=1;w<=W;w++){
      if(DP[h][w] == INF) continue;
      
      if(w <= l){
        DP[h+1][r] = min(DP[h+1][r], DP[h][w] + (r-w) + 100);
      }
      else if(w >= r){
        DP[h+1][l] = min(DP[h+1][l], DP[h][w] + (w-l) + 100);
      }
      else{
        DP[h+1][l] = min(DP[h+1][l], DP[h][w] + (r-l) + (r-w) + 100);
        DP[h+1][r] = min(DP[h+1][r], DP[h][w] + (r-l) + (w-l) + 100);
      }
    }

  }

  // for(int i=1;i<=H;i++){
  //   for(int j=1;j<=W;j++){
  //     cout << DP[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  for(int i=1;i<=W;i++){
    if(DP[max_h+1][i] == INF) continue;
    answer = min(answer, DP[max_h+1][i]);
  }

  cout << answer-101;
}