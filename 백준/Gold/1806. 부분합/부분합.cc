#include <iostream>

using namespace std;

int main() {
  int N, S;
  int num[100005] = {0};

  cin >> N >> S;
  
  for(int i=1;i<=N;i++){
    cin >> num[i];
  }

  int sum = 0;
  int answer = 999999;
  int st = 1;
  for(int i=1;i<=N;i++){
    sum += num[i];
    while(sum >= S && st <= N){
      answer = min(answer, i-st+1);
      sum -= num[st];
      st++;
    }
  }

  if(answer == 999999) answer = 0;
  cout << answer;

  return 0;
}