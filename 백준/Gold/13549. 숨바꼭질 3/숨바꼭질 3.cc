#include <iostream>
#include <queue>

using namespace std;

int visit[200005];

int main() {
  int N, K;
  queue<int> Q;
  cin >> N >> K;
  fill_n(visit, 200005, -1);
  Q.push(N);
  visit[N] = 0;
  while(!Q.empty()){
    int now = Q.front();
    Q.pop();

    if(now == K){
      cout << visit[now];
      return 0;
    }

    if(now*2 <= 100000 && visit[now*2] == -1){
      visit[now*2] = visit[now];
      Q.push(now*2);
    }
    //알고리즘 우선순위가 중요함
    if(now-1 >= 0 && visit[now-1] == -1){
      visit[now-1] = visit[now]+1;
      Q.push(now-1);
    }
    if(now+1 <= 100000 && visit[now+1] == -1){
      visit[now+1] = visit[now]+1;
      Q.push(now+1);
    }
  }

  return 0;
}