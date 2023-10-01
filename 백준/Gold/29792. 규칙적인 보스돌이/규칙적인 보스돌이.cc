#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, K;
long long D[50];
vector<pair<long long, long long>> boss;
long long answer = 0;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> N >> M >> K;

  for(int i=0;i<N;i++){
    cin >> D[i];
    D[i] = -D[i];
  }

  sort(D, D+N);

  for(int i=0;i<K;i++){
    long long hp, gold;
    cin >> hp >> gold;
    boss.push_back({hp, gold});
  }

  for(int k=0;k<M;k++){
    long long atk = -D[k];
    long long dp[15][905] = {0};
    
    for(int i=0;i<K;i++){
      long long hp = boss[i].first, gold = boss[i].second;
      long long time;

      if(hp%atk == 0) time = hp/atk;
      else time = hp/atk+1;

      for(int t=0;t<=900;t++){
        if(t >= time){
          dp[i+1][t] = max(dp[i][t], dp[i][t-time]+gold);
        }
        else{
          dp[i+1][t] = dp[i][t];
        }
      }
    }

    answer += dp[K][900];
  }

  cout << answer;
}