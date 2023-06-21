#include <iostream>
#include <algorithm>

using namespace std;
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main() {
  FASTIO
  int T;
  int M, N, x, y;
  cin >> T;

  while(T--){
    cin >> M >> N >> x >> y;
    int gcd = __gcd(M, N), lcm = M*N/gcd;
    int answer = -1;
    for(int i=x;i<=lcm;i+=M){
      int ny = i%N;
      if(ny==0) ny = N;
      if(ny==y){
        answer = i; break;
      }
    }
    cout << answer << "\n";
  }

  return 0;
}