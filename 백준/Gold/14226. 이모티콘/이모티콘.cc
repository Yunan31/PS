#include <iostream>
#include <queue>

using namespace std;

int main() {
  int S, answer = 99999;
  int mem[1001][1001] = {0};
  queue<pair<int, int>> Q;

  cin >> S;

  fill_n(mem[0], 1001*1001, 99999);

  mem[1][0] = 0;
  Q.push({1, 0});

  while(!Q.empty()){
    int length = Q.front().first, clipboard = Q.front().second;
    Q.pop();

    if(length == S){
      answer = min(answer, mem[length][clipboard]);
      continue;
    }

    //1. 클립보드 저장
    if(length != clipboard){
      if(mem[length][length] > mem[length][clipboard] + 1){
        mem[length][length] = mem[length][clipboard] + 1;
        Q.push({length, length});
      }
    }
    //2. 화면에 붙여넣기
    if(length + clipboard <= S){
      if(mem[length+clipboard][clipboard] > mem[length][clipboard] + 1){
        mem[length+clipboard][clipboard] = mem[length][clipboard] + 1;
        Q.push({length+clipboard, clipboard});
      }
    }
    //3. 하나 삭제
    if(length > 2){
      if(mem[length-1][clipboard] > mem[length][clipboard] + 1){
        mem[length-1][clipboard] = mem[length][clipboard] + 1;
        Q.push({length-1, clipboard});
      }
    }
  }

  cout << answer;
}