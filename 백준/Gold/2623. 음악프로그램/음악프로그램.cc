#include <iostream>
#include <queue>

using namespace std;

int main() {
  vector<int> E[1005];
  int in_degree[1005];
  int N, M;

  cin >> N >> M;
  for(int i=0;i<M;i++){
    int size, from, to;
    cin >> size >> to;

    for(int k=0;k<size-1;k++){
      from = to;
      cin >> to;
      in_degree[to]++;
      E[from].push_back(to);
    }
  }

  queue<int> Q;
  vector<int> answer;
  int visit[1005] = {0};
  
  for(int i=1;i<=N;i++){
    if(in_degree[i] == 0){
      visit[i];
      Q.push(i);
    }
  }

  while(!Q.empty()){
    int now = Q.front();
    Q.pop();

    answer.push_back(now);

    for(int i=0;i<E[now].size();i++){
      int next = E[now][i];
      if(visit[next] == 0 && --in_degree[next] == 0){
        visit[next]++;
        Q.push(next);
      }
    }
  }

  for(int i=1;i<=N;i++){
    if(in_degree[i]){
      cout << 0;
      return 0;
    }
  }
  
  for(int i=0;i<answer.size();i++){
    cout << answer[i] << "\n";
  }

  return 0;
}