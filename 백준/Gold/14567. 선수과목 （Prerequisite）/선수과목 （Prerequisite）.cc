#include <iostream>
#include <queue>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int N, M;
  vector<int> E[1005];
  int in_degree[1005] = {0};
  int visit[1005] = {0};
  int season = 1;
  int answer[1005] = {0};

  cin >> N >> M;

  for(int i=0;i<M;i++){
    int A, B;
    cin >> A >> B;
    in_degree[B]++;
    E[A].push_back(B);
  }

  queue<int> Q;
  int count = 0;

  for(int i=1;i<=N;i++){
    if(in_degree[i] == 0){
      Q.push(i);
      answer[i] = season;
      visit[i]++;
      count++;
    }
  }

  season++;

  int temp = 0;
  while(!Q.empty()){
    int from = Q.front();
    Q.pop();

    for(int i=0;i<E[from].size();i++){
      int to = E[from][i];
      if(visit[to] == 0 && --in_degree[to] == 0){
        visit[to]++;
        Q.push(to);
        temp++;
        answer[to] = season;
      }
    }

    count--;
    if(count == 0){
      season++;
      count = temp;
      temp = 0;
    }
  }

  for(int i=1;i<=N;i++){
    cout << answer[i] << " ";
  }
}