#include <iostream>

using namespace std;

int main() {
  int arr[8];
  string answer = "mixed";

  for(int i=0;i<8;i++) cin >> arr[i];

  int count = 0;
  for(int i=0;i<8;i++){
    if(arr[i] == i+1) count++;
  }
  if(count == 8) answer = "ascending";

  count = 0;
  for(int i=0;i<8;i++){
    if(arr[i] == 8-i) count++;
  }
  if(count == 8) answer = "descending";

  cout << answer;
}