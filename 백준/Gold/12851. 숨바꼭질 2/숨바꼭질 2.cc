#include <iostream>
#include <queue>

using namespace std;

int dist[200005];
int dist_num[200005];

int main() {
  int N, K;
  queue<int> Q;
  cin >> N >> K;

  fill_n(dist, 200005, 999999);
  fill_n(dist_num, 200005, 1);
  
  dist[N] = 0;
  Q.push(N);

  while(!Q.empty()){
    int now = Q.front();
    Q.pop();

    if(now*2 <= 100000 && dist[now*2] >= dist[now] + 1){
      if(dist[now*2] == dist[now] + 1) dist_num[now*2]++;
      dist[now*2] = dist[now] + 1;
      Q.push(now*2);
    }
    if(now+1 <= 100000 && dist[now+1] >= dist[now] + 1){
      if(dist[now+1] == dist[now] + 1) dist_num[now+1]++;
      dist[now+1] = dist[now] + 1;
      Q.push(now+1);
    }
    if(now-1 <= 100000 && dist[now-1] >= dist[now] + 1){
      if(dist[now-1] == dist[now] + 1) dist_num[now-1]++;
      dist[now-1] = dist[now] + 1;
      Q.push(now-1);
    }
  }

  cout << dist[K] << "\n" << dist_num[K];
}