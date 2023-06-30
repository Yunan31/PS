#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define pll pair<long long, long long>

pair<pll, pll> vec[2505];
pair<long long, int> weight[2505];
int visit[2505] = {0};
int N;

int ccw(pll a, pll b, pll c){
  long long s = a.first*b.second + b.first*c.second + c.first*a.second;
  s -= b.first*a.second + c.first*b.second + a.first*c.second;

  if(s > 0) return 1;
  else if(s < 0) return -1;
  return 0;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> N;

  int a, b, x, y, w;
  for(int i=0;i<N;i++){
    cin >> a >> b >> x >> y >> w;
    vec[i] = {{a, b}, {x, y}};
    weight[i] = {w, i};
  }
  sort(weight, weight+N);
  
  long long answer = 0;

  for(int i=0;i<N;i++){
    long long w = weight[i].first;
    pll p1 = vec[weight[i].second].first, p2 = vec[weight[i].second].second;
    int m = 0;

    visit[weight[i].second] = 1;
    for(int k=0;k<N;k++){
      if(visit[k]) continue;
      pll p3 = vec[k].first, p4 = vec[k].second;
      if(ccw(p1, p2, p3)*ccw(p1, p2, p4) <= 0 && ccw(p3, p4, p2)*ccw(p3, p4, p1) <= 0){
        m++;
      }
    }

    answer += (m+1)*w;
  }

  cout << answer;
  
  return 0;
}