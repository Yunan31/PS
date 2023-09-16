#include <iostream>
#include <queue>

using namespace std;

int N;
int in_degree[505] = {0};
int visit[505] = {0};
int answer[505] = {0};
int build_time[505];
queue<int> Q;
vector<int> E[505];

int main() {
  cin >> N;
  for(int i=1;i<=N;i++){
    cin >> build_time[i];
    int input;
    while(true){
      cin >> input;
      if(input == -1) break;
      in_degree[i]++;
      E[input].push_back(i);
    }
  }

  for(int i=1;i<=N;i++){
    if(in_degree[i] == 0){
      visit[i] = 1;
      answer[i] = build_time[i];
      Q.push(i);
    }
  }

  while(!Q.empty()){
    int from = Q.front();
    Q.pop();

    for(int i=0;i<E[from].size();i++){
      int to = E[from][i];
      answer[to] = max(answer[to], answer[from]);
      if(visit[to] == 0 && --in_degree[to] == 0){
        Q.push(to);
        answer[to] += build_time[to];
      }
    }
  }

  for(int i=1;i<=N;i++){
    cout << answer[i] << "\n";
  }
}