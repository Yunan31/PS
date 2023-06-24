#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, high;
  int remain2 = 0, total = 0;
  cin >> N;

  for(int i=0;i<N;i++){
    cin >> high;
    total += high;
    remain2 += high/2;
  }
  if(total%3 != 0) {cout << "NO"; return 0;}

  if(total/3 <= remain2) cout << "YES";
  else cout << "NO";
  return 0;
}