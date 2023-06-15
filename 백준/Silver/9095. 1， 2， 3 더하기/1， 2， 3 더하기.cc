#include <iostream>

using namespace std;

int sum[12];

int main() {
  int T, n;

  cin >> T;

  sum[1] = 1;
  sum[2] = 2;
  sum[3] = 4;

  for(int i=4;i<=10;i++){
    sum[i] = sum[i-3] + sum[i-2] + sum[i-1];
  }

  for(int i=0;i<T;i++){
    cin >> n;
    cout << sum[n] << "\n";
  }

  return 0;
}