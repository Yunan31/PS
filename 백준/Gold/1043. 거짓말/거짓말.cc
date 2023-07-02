#include <iostream>
#include <vector>
#include <queue>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main() {
  fastio
  int N, M;
  cin >> N >> M;
  bool black_list[55] = {false};
  vector<int> party[55];
  queue<int> Q;
  int visit[55] = {0};
  int answer = 0;

  int know;
  cin >> know;
  for(int i=0;i<know;i++){
    int person;
    cin >> person;
    black_list[person] = true;
    Q.push(person); visit[person] = 1;
  }

  for(int i=0;i<M;i++){
    int num;
    cin >> num;
    for(int k=0;k<num;k++){
      int person; cin >> person;
      party[i].push_back(person);
    }
  }

  while(!Q.empty()){
    int now = Q.front();
    Q.pop();

    for(int i=0;i<M;i++){
      int flag = 0;
      for(int j=0;j<party[i].size();j++){
        if(party[i][j] == now){ flag = 1; break;}
      }
      if(flag){
        for(int j=0;j<party[i].size();j++){
          if(!visit[party[i][j]]){
            Q.push(party[i][j]);
            visit[party[i][j]] = 1;
            black_list[party[i][j]] = true;
          }
        }
      }
    }
  }

  for(int i=0;i<M;i++){
    int count = 0;
    for(int j=0;j<party[i].size();j++){
      if(black_list[party[i][j]]) break;
      else count++;
    }
    if(count == party[i].size()) answer++;
  }

  cout << answer;

  return 0;
}