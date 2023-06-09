#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int visit_dfs[1005] = {0}, visit_bfs[1005] = {0};
vector<vector<int>> graph(1005);

void dfs(int V){
  visit_dfs[V] = 1;
  cout << V << " ";

  for(int i=0;i<graph[V].size();i++){
    if(visit_dfs[graph[V][i]] == 0){
      dfs(graph[V][i]);
    }
  }
}

void bfs(int V){
  queue<int> queue;

  queue.push(V);
  visit_bfs[V] = 1;

  while(!queue.empty()){
    int now = queue.front();
    queue.pop();

    cout << now << " ";

    for(int i=0;i<graph[now].size();i++){
      if(visit_bfs[graph[now][i]] == 0){
        queue.push(graph[now][i]);
        visit_bfs[graph[now][i]] = 1;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  int N, M, V;

  cin >> N >> M >> V;

  for(int i=0;i<M;i++){
    int node, edge;
    cin >> node >> edge;
    graph[node].push_back(edge);
    graph[edge].push_back(node);
  }

  for(int i=1;i<=N;i++){
    sort(graph[i].begin(), graph[i].end());
  }

  dfs(V);
  cout << "\n";
  bfs(V);
  
}