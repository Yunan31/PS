#include <iostream>
#include <algorithm>

using namespace std;

int dp[100005] = {0};
int target[100005];
int high = 0;

int solve(int n){
  if(n > high) return 0;

  dp[n]++;

  int tmp = n*2;
  while(tmp <= high){
    solve(tmp);
    tmp+=n;
  }

  return 0;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int N, Q;
  int A[100005];

  cin >> N;
  for(int i=0;i<N;i++){
    cin >> A[i];
  }
  sort(A, A+N);

  cin >> Q;
  for(int i=0;i<Q;i++){
    cin >> target[i];
    high = max(high, target[i]);
  }

  for(int i=0;i<N;i++){
    solve(A[i]);
  }

  for(int i=0;i<Q;i++){
    cout << dp[target[i]] << " ";
  }
}