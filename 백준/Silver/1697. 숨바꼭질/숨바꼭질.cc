#include <iostream>
#include <queue>

using namespace std;

int dist[200005];
int visit[200005] = {0};

int main() {
  int N, K;
  queue<int> Q;
  cin >> N >> K;

  fill_n(dist, 200005, 999999);
  
  dist[N] = 0;
  visit[N] = 1;
  Q.push(N);

  while(dist[K] == 999999){
    int now = Q.front();
    Q.pop();

    if(now*2 <= 100000 && !visit[now*2]){
      dist[now*2] = min(dist[now*2], dist[now] + 1);
      visit[now]++;
      Q.push(now*2);
    }
    if(now+1 <= 100000 && !visit[now+1]){
      dist[now+1] = min(dist[now+1], dist[now] + 1);
      visit[now]++;
      Q.push(now+1);
    }
    if(now-1 <= 100000 && !visit[now-1]){
      dist[now-1] = min(dist[now-1], dist[now] + 1);
      visit[now]++;
      Q.push(now-1);
    }
  }

  cout << dist[K];
}