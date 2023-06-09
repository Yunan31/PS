#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

int visit_dfs[1005] = {0}, visit_bfs[1005] = {0};
vector<vector<int>> graph(1005);

//그냥 재귀로하는게 낫다;
void dfs(int V){
  stack<int> stack;

  stack.push(V);
  cout << V << " ";
  visit_dfs[V] = 1;

  while(!stack.empty()){
    int now = stack.top();
    stack.pop();

    for(int i=0;i<graph[now].size();i++){
      if(visit_dfs[graph[now][i]] == 0){
        cout << graph[now][i] << " ";
        visit_dfs[graph[now][i]] = 1;
        stack.push(now);
        stack.push(graph[now][i]);
        break;
      }
    }
  }

  cout << "\n";
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
  bfs(V);
  
}