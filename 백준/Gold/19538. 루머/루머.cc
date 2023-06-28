#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
  vector<int> around[200005];
  int rumor[200005];
  int N, M;
  int min_count = 0, minute = 0, next_min = 0;
  queue<int> Q;
  
  fill_n(rumor, 200005, -1);
  cin >> N;

  int person;
  for(int i=1;i<=N;i++){
    cin >> person;
    while(person != 0){
      around[i].push_back(person);
      cin >> person;
    }
  }

  cin >> M;
  for(int i=1;i<=M;i++){
    cin >> person;
    Q.push(person);
    rumor[person] = 0;
    min_count++;
  }

  while(!Q.empty()){
    int now = Q.front();
    Q.pop();
    min_count--;

    //자기 주변인 루머믿는사람 수 계산
    if(rumor[now] == -1){
      int count = 0;
      for(int i=0;i<around[now].size();i++){
        if(rumor[around[now][i]] != -1 && rumor[around[now][i]] != minute) count++;
      }
      if((double)count/around[now].size() >= 0.5) rumor[now] = minute;
    }

    if(rumor[now] != -1){
      for(int i=0;i<around[now].size();i++){
        if(rumor[around[now][i]] == -1){
          Q.push(around[now][i]);
          next_min++;
        }
      }
    }

    if(min_count == 0){
      min_count = next_min;
      next_min = 0;
      minute++;

      // for(int i=1;i<=N;i++){
      //   cout << rumor[i] << " ";
      // }
      // cout << endl;
    }
  }

  for(int i=1;i<=N;i++){
    cout << rumor[i] << " ";
  }

  return 0;
  
}