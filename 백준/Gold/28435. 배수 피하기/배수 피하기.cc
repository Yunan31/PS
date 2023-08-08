#include <iostream>
#define MOD 1000000007

using namespace std;

int N, K;
int remain[100005] = {0};

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> N >> K;
  for(int i=0;i<N;i++){
    int num;
    cin >> num;
    remain[num%K]++;
  }

  long long answer = 1;
  for(int i=1;i<(K+1)/2;i++){
    int left = 1, right = 1;
    for(int l = 0;l<remain[i];l++)
      left = left*2%MOD;
    for(int r = 0;r<remain[K-i];r++)
      right = right*2%MOD;
    answer = answer * (left + right - 1)%MOD;
  }

  if(remain[0]){
    answer = answer*(remain[0]+1)%MOD;
  }

  if(K%2==0){
    answer = answer*(remain[K/2]+1)%MOD;
  }

  cout << (answer + MOD - (N+1))%MOD;
}