#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
  vector<int> around[200005];
  int rumor[200005];
  int visit[200005] = {0};
  double condition[200005];
  int N, M;
  queue<pair<int, int>> Q;
  
  fill_n(rumor, 200005, -1);
  cin >> N;

  int person;
  for(int i=1;i<=N;i++){
    cin >> person;
    while(person != 0){
      around[i].push_back(person);
      cin >> person;
    }
    condition[i] = (double)around[i].size()/2;
  }

  cin >> M;
  for(int i=1;i<=M;i++){
    cin >> person;
    Q.push({person, 1});
    rumor[person] = 0;
    visit[person] = 1;
  }

  while(!Q.empty()){
    int now = Q.front().first;
    int minute = Q.front().second;
    Q.pop();

    for(int i=0;i<around[now].size();i++){
      condition[around[now][i]]--;
      //cout << around[now][i] << ": " << condition[around[now][i]] << " min: " << minute << endl;
      if(condition[around[now][i]] <= 0 && !visit[around[now][i]]){
        Q.push({around[now][i], minute+1 });
        rumor[around[now][i]] = minute;
        visit[around[now][i]] = 1;
      }
    }
  }

  for(int i=1;i<=N;i++){
    cout << rumor[i] << " ";
  }

  return 0;
  
}