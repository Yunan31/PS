#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int N, K;
  vector<pair<int, int>> juwel;
  int backpack[300002];
  priority_queue<int> keep;
  long long answer = 0;

  cin >> N >> K;

  for(int i=0;i<N;i++){
    int m, v;
    cin >> m >> v;
    juwel.push_back({m, v});
  }
  for(int i=0;i<K;i++){
    cin >> backpack[i];
  }

  sort(juwel.begin(), juwel.end());
  sort(backpack, backpack+K);

  int idx = 0;
  for(int i=0;i<K;i++){
    while(idx < N && juwel[idx].first <= backpack[i]){
      keep.push(juwel[idx].second);
      idx++;
    }

    if(!keep.empty()){
      answer += keep.top();
      keep.pop();
    }
  }

  cout << answer;
}