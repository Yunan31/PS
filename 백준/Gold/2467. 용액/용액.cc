#include <iostream>

using namespace std;

int main() {
  int num[100005];
  int N;

  cin >> N;
  for(int i=0;i<N;i++){
    cin >> num[i];
  }

  int l = 0, r = N-1;
  int ans1, ans2;
  int abs_min = 2000000005;
  while(l < r){
    if(abs(num[l] + num[r]) < abs_min){
      abs_min = abs(num[l]+num[r]);
      ans1 = num[l];
      ans2 = num[r];
    }

    if(num[l]+num[r] < 0){
      l++;
    }
    else{
      r--;
    }
  }

  cout << ans1 << " " << ans2 << endl;
  //cout << abs_min;

  return 0;
}