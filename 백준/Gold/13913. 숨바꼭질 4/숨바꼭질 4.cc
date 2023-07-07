#include <iostream>
#include <queue>

using namespace std;

int visit[100005];
int path[100005];

int main() {
  int N, K;
  queue<int> Q;
  cin >> N >> K;
  fill_n(visit, 100005, -1);
  fill_n(path, 100005, -1);
  Q.push(N);
  visit[N] = 0;
  while(!Q.empty()){
    int now = Q.front();
    Q.pop();

    if(now == K){
      cout << visit[now] << "\n";
      int cur = now;
      vector<int> road;
      road.push_back(cur);
      while(path[cur] != -1){ road.push_back(path[cur]); cur = path[cur]; }
      for(int i=road.size()-1;i>=0;i--) cout << road[i] << " ";
      return 0;
    }

    if(now*2 <= 100000 && visit[now*2] == -1){
      visit[now*2] = visit[now]+1;
      Q.push(now*2);
      path[now*2] = now;
    }
    //알고리즘 우선순위가 중요함
    if(now-1 >= 0 && visit[now-1] == -1){
      visit[now-1] = visit[now]+1;
      Q.push(now-1);
      path[now-1] = now;
    }
    if(now+1 <= 100000 && visit[now+1] == -1){
      visit[now+1] = visit[now]+1;
      Q.push(now+1);
      path[now+1] = now;
    }
  }

  return 0;
}