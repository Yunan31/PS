#include <iostream>
#include <string>
#include <queue>

using namespace std;

int visit[1000005][11] = {0};

int main() {
  int N, K, answer = -1;
  cin >> N >> K;

  if(N < 10){
    cout << "-1"; return 0;
  }

  queue<pair<int, int>> Q;

  Q.push({N, 0});
  visit[N][0] = 1;

  while(!Q.empty()){
    int now = Q.front().first, depth = Q.front().second;
    Q.pop();
    string to_str = to_string(now);

    if(depth == K){
      answer = max(answer, now); continue;
    }

    for(int i=0;i<to_str.length()-1;i++){
      for(int j=i+1;j<to_str.length();j++){
        string now_str = to_str;
        char tmp = now_str[i];
        now_str[i] = now_str[j];
        now_str[j] = tmp;

        int next = stoi(now_str);

        if(visit[next][depth+1]) continue;
        if(to_string(next).length() != now_str.length()) continue;
        Q.push({next, depth+1});
        visit[next][depth+1] = 1;
      }
    }
  }

  cout << answer;
  return 0;
}