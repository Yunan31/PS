#include <iostream>

using namespace std;

int main() {
  int N;
  int A[1001], left[1001], right[1001];

  cin >> N;

  for(int i=1;i<=N;i++){
    cin >> A[i];
  }

  left[1] = 1;
  for(int i=2;i<=N;i++){
    int val = 0;
    for(int j=1;j<i;j++){
      if(A[j] < A[i] && val < left[j]) val = left[j];
    }
    left[i] = val+1;
  }

  right[N] = 1;
  for(int i=N-1;i>=1;i--){
    int val = 0;
    for(int j=N;j>i;j--){
      if(A[j] < A[i] && val < right[j]) val = right[j];
    }
    right[i] = val+1;
  }

  int answer = 0;
  for(int i=1;i<=N;i++){
    answer = max(left[i] + right[i] -1, answer);
  }
  cout << answer;

  return 0;
}