#include <iostream>
#include <cmath>

using namespace std;

int answer[33];
long long nCr[33][33];
int N, L;
long long I;
int cur = 0;

void combination(){
  for(int i=0;i<32;i++){
    nCr[i][0] = 1;
  }
  nCr[1][1] = 1;

  for(int i=2;i<32;i++){
    for(int j=1;j<=i;j++){
      nCr[i][j] = nCr[i-1][j] + nCr[i-1][j-1];
    }
  }
}

void solve(int n, int l, long long idx){
  if(idx == 1){
    for(int i=0;i<n-1;i++) answer[cur++] = 0;
    answer[cur] = 0; return;
  }
  if(idx == 2){
    for(int i=0;i<n-1;i++) answer[cur++] = 0;
    answer[cur] = 1; return;
  }
  
  long long DP[32] = {0};
  DP[1] = 2;
  for(int i=2;i<=n;i++){
    if(i <= l) DP[i] = pow(2, i);
    else DP[i] = DP[i-1]*2 - nCr[i-1][l];
  }

  // for(int i=1;i<=n;i++) cout << DP[i] << " ";
  // cout << endl;

  int next_bit;
  for(int i=1;i<=n;i++){
    if(idx <= DP[i]){
      next_bit = i;
      break;
    }
  }


  for(int i=0;i<n-next_bit;i++){
    answer[cur++] = 0;
  }
  answer[cur++] = 1;
  solve(next_bit-1, l-1, idx-DP[next_bit-1]);
}

int main() {
  cin >> N >> L >> I;

  combination();

  // for(int i=1;i<32;i++){
  //   for(int j=0;j<=i;j++){
  //     cout << nCr[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  
  solve(N, L, I);
  for(int i=0;i<=cur;i++){
      cout << answer[i];
  }
  return 0;
}