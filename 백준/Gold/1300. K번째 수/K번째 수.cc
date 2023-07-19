#include <iostream>

using namespace std;

int main() {
  int N, K;

  cin >> N >> K;

  int low = -1, high = 1000000000;

  while(low <= high){
    int mid = (low+high)/2;
    int count = 0;
    for(int i=1;i<=N;i++){
      count += min(mid/i, N);
    }
    if(count >= K){
      high = mid-1;
    }
    else{
      low = mid+1; 
    }
  }

  cout << low;
  
  return 0;
}