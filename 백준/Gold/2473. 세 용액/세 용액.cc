#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  long long liquid[5005];
  int N;

  cin >> N;
  for(int i=0;i<N;i++){
    cin >> liquid[i];
  }

  sort(liquid, liquid+N);

  long long abs_min = 3000000005;
  int ans1, ans2, ans3;
  for(int i=0;i<N-2;i++){
    int l = i+1, r = N-1;
    while(l < r){
      long long temp = liquid[i] + liquid[l] + liquid[r];
      if(abs(temp) < abs_min){
        ans1 = liquid[i];
        ans2 = liquid[l];
        ans3 = liquid[r];
        abs_min = abs(temp);
      }

      if(temp < 0) l++;
      else r--;
    }
  }

  cout << ans1 << " " << ans2 << " " << ans3;
}