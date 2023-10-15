#include <iostream>
#include <tuple>
#include <algorithm>

using namespace std;

int N;
tuple<long long, long long, int> arr[1005];

int main() {
  cin >> N;
  for(int i=0;i<N;i++){
    int x, y;
    cin >> x >> y;
    arr[i] = {-y, x, i+1};
  }

  sort(arr, arr+N);

  for(int i=0;i<N-1;i++){
    cout << get<2>(arr[i]) << " " << get<2>(arr[i+1]) << "\n";
  }
}