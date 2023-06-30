#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#define pll pair<long long, long long>

vector<int> cross[2505];
pair<pll, pll> vec[2505];
long long weight[2505];
int visit[2505] = {0};
int N;

void update(int k){
  for(int i=0;i<N;i++){
    for(int j=0;j<cross[i].size();j++){
      if(cross[i][j] == k) cross[i].erase(cross[i].begin()+j);
    }
  }
}

int ccw(pll a, pll b, pll c){
  long long s = a.first*b.second + b.first*c.second + c.first*a.second;
  s -= b.first*a.second + c.first*b.second + a.first*c.second;

  if(s > 0) return 1;
  else if(s < 0) return -1;
  return 0;
}

int main() {
  cin >> N;

  int a, b, x, y, w;
  for(int i=0;i<N;i++){
    cin >> a >> b >> x >> y >> w;
    vec[i] = {{a, b}, {x, y}};
    weight[i] = w;
  }

  for(int i=0;i<N-1;i++){
    pll p1, p2, p3, p4;
    p1 = vec[i].first; p2 = vec[i].second;
    for(int k=i+1;k<N;k++){
      p3 = vec[k].first; p4 = vec[k].second;
      if(ccw(p1, p2, p3)*ccw(p1, p2, p4) <= 0 && ccw(p3, p4, p1)*ccw(p3, p4, p2) <=0){
        cross[i].push_back(k); cross[k].push_back(i);
      }
    }
  }

  long long answer = 0;

  for(int k=0;k<N;k++){
    long long w = 20000000000;
    int idx;
    for(int i=0;i<N;i++){
      if(visit[i]) continue;
      long long temp = weight[i];
      if(temp < w){
        idx = i; w = temp;
      }
    }
    answer += (cross[idx].size()+1)*w; update(idx);
    visit[idx] = 1;
  }

  cout << answer;
  
  return 0;
}