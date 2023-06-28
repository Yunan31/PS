#include <iostream>
#include <vector>

using namespace std;

vector<int> tree[300005];
int visit[300005] = {0};
long long D = 0, G = 0;

int D_tree(int now){
  if(visit[now]) return 0;
  visit[now] = 1;
  int total = 0;

  for(int i=0;i<tree[now].size();i++){
    if(tree[now].size() >= 2 && tree[tree[now][i]].size() >= 2 && !visit[tree[now][i]])
      total += (tree[now].size()-1)*(tree[tree[now][i]].size()-1);
    total += D_tree(tree[now][i]);
  }
  
  return total;
}

int main() {
  int N;
  int u, v;
  
  cin >> N;
  
  for(int i=0;i<N-1;i++){
    cin >> u >> v;
    tree[u].push_back(v);
    tree[v].push_back(u);
  }

  for(int i=1;i<=N;i++){
    int node = tree[i].size();
    if(node >= 3){
      G += (node*(node-1)*(node-2))/6;
    }
  }

  D += D_tree(1);

  //cout << "D: " << D << " G: " << G << endl;

  if(D > G*3) cout << "D";
  else if(D < G*3) cout << "G";
  else cout << "DUDUDUNGA";

  return 0;
}