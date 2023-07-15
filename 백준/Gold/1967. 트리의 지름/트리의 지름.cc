#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int parent[10005] = {0};
vector<pair<int, int>> tree[10005];
int N;
int answer = 0;

void DFS(int num){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  if(tree[num].empty()) return;

  for(int i=0;i<tree[num].size();i++){
    DFS(tree[num][i].second);
  }
  
  sort(tree[num].begin(), tree[num].end());
  if(tree[num].size() == 1){
    answer = max(answer, -tree[num][0].first);
  }
  else{
    answer = max(answer, -tree[num][0].first-tree[num][1].first);
  }
  
  for(int i=0;i<tree[parent[num]].size();i++){
    if(tree[parent[num]][i].second == num){
      tree[parent[num]][i].first += tree[num][0].first;
      break;
    }
  }
}

int main() {
  cin >> N;

  for(int i=0;i<N-1;i++){
    int a, b, w;
    cin >> a >> b >> w;
    tree[a].push_back({-w, b});
    parent[b] = a;
  }

  // for(int i=1;i<=N;i++){
  //   node tmp = tree[i];
  //   cout << i << " : " << tmp.P << " " << tmp.LC << " -> " << tmp.LD << " , " << tmp.RC << " -> " << tmp.RD << endl;
  // }
  DFS(1);
  cout << answer;
  return 0;
}