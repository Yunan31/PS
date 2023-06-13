#include <iostream>

using namespace std;

int coin[11];

int main() {
  int N, K;
  int sum = 0, count = 0;

  cin >> N >> K;

  for(int i=0;i<N;i++) cin >> coin[i];

  for(int i=N-1;i>=0;i--){
    while(sum < K){
      if(sum+coin[i] > K) break;
      sum += coin[i];
      count++;
    }
  }

  cout << count;

  return 0;
}