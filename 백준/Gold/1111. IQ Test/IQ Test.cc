#include <iostream>
#define INF 999999

using namespace std;

int main() {
  int N;
  int num[55];
  fill_n(num, 55, INF);

  cin >> N;
  for(int i=0;i<N;i++){
    cin >> num[i];
  }

  int answer = INF;
  int flag = 0, possible = 0;

  for(int i=-200;i<=200;i++){
    for(int j=-20000;j<=20000;j++){
      int count = 0;
      for(int k=0;k<N-1;k++){
        if(num[k]*i+j == num[k+1]) count++;
      }
      if(count == N-1){
        if(i==1 && j==0) flag++;
        if(answer != INF) possible++;
        answer = num[N-1]*i+j;
      }
    }
  }

  if(flag && N > 1){ cout << num[0]; return 0; }
  if(possible > 1){ cout << 'A'; return 0; }
  if(answer == INF){ cout << 'B'; return 0; }
  cout << answer;

  return 0;
}