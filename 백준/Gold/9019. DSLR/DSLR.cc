#include <iostream>
#include <queue>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int L(int num){
  int d[5] = {0};
  for(int i=4;i>=1;i--){
    d[i] = num%10;
    num/=10;
  }
  return 1000*d[2] + 100*d[3] + 10*d[4] + d[1];
}

int R(int num){
  int d[5] = {0};
  for(int i=4;i>=1;i--){
    d[i] = num%10;
    num/=10;
  }
  return 1000*d[4] + 100*d[1] + 10*d[2] + d[3];
}

int main() {
  fastio
  int T;
  cin >> T;

  while(T--){
    int num, target;
    cin >> num >> target;
    string pre[10005];
    int visit[10005] = {0};
    fill_n(pre, 10005, "");
    
    queue<int> Q;
    Q.push(num);
    visit[num] = 1;
    while(!Q.empty()){
      int now = Q.front();
      Q.pop();
      string str = pre[now];

      int next[4] = {(now*2)%10000, now-1, L(now), R(now)};
      char ch[4] = {'D', 'S', 'L', 'R'};
      for(int i=0;i<4;i++){
        if(next[i] < 0) next[i] = 9999;
        if(!visit[next[i]]){
          visit[next[i]] = 1;
          pre[next[i]] = str+ch[i];
          Q.push(next[i]);
        }
      }
      if(pre[target] != "") break;
    }
    cout << pre[target] << "\n";
  }
}