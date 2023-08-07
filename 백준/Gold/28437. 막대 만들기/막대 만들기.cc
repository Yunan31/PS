#include <iostream>
#include <algorithm>

using namespace std;

int dp[100005] = {0};
int target[100005];
int high = 0;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int N, Q;
  int A[100005];

  cin >> N;
  for(int i=0;i<N;i++){
    cin >> A[i];
    dp[A[i]]++;
  }

  cin >> Q;
  for(int i=0;i<Q;i++){
    cin >> target[i];
    high = max(high, target[i]);
  }

  for(int i=1;i<=high;i++){
    for(int j = i*2;j<=high;j+=i){
      dp[j] += dp[i];
    }
  }

  for(int i=0;i<Q;i++){
    cout << dp[target[i]] << " ";
  }
}