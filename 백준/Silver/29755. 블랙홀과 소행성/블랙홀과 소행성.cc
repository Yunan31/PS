#include <iostream>
#include <vector>
#include <algorithm>
#define INF 999999999

using namespace std;

int N, M;
vector<int> blackhole;
vector<pair<int, int>> planet;

bool possible(int P){
  vector<pair<int, int>> p = planet;
  int cur_b = 0, cur_p = 0;
  
  while(cur_p < M && cur_b < N){
    if(abs(blackhole[cur_b] - planet[cur_p].first) * planet[cur_p].second <= P){
      cur_p++;
    }
    else{
      cur_b++;
    }
  }

  if(cur_b == N) return false;
  if(cur_p == M) return true;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> N >> M;
  for(int i=0;i<N;i++){
    int b;
    cin >> b;
    blackhole.push_back(b);
  }

  for(int i=0;i<M;i++){
    int a, w;
    cin >> a >> w;
    planet.push_back({a, w});
  }

  sort(blackhole.begin(), blackhole.end());
  sort(planet.begin(), planet.end());

  int lo = 0, hi = INF;
  while(lo <= hi){
    int mid = (lo+hi)/2;

    if(possible(mid)){
      hi = mid-1;
    }
    else{
      lo = mid+1;
    }
  }

  cout << lo;
}