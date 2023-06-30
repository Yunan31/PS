#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
#define ll long long

using namespace std;

int N, M, K, S, T;
vector<pair<ll, ll>> slide[100001], lift[100001];
ll cost[100001][11];

ll DP(int now, int k){
  if(now == T && k == 0) return 0;
  if(cost[now][k] != -1) return cost[now][k];
  ll score = LLONG_MIN;
  if(k > 0){
    for(auto p : lift[now]){
      score = max(score, DP(p.first, k-1));
    }
  }
  for(auto p : slide[now]){
    score = max(score, DP(p.first, k) + p.second);
  }

  return cost[now][k] = score;
}

int main() {
  memset(cost, -1, sizeof(cost));
  cin >> N >> M >> K >> S >> T;
  
  for(int i=0;i<M;i++){
    ll a, b, t;
    cin >> a >> b >> t;
    slide[a].push_back({b, t});
    lift[b].push_back({a, 0});
  }

  ll answer = DP(S, K);
  if(answer < 0) answer = -1;
  cout << answer;

  return 0;
}