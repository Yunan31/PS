#include <iostream>
#include <cmath>

using namespace std;

int Z(int N, int r, int c){
  if(N==1){
    return r*2 + c;
  }
  int size = pow(2, N);
  int answer;

  answer = r/(size/2) * pow(size/2, 2)*2 + c/(size/2) * pow(size/2, 2);

  r = r%(size/2); c = c%(size/2);

  return answer + Z(N-1, r, c);
}

int main() {
  int N, r, c;
  
  cin >> N >> r >> c;

  cout << Z(N, r, c);

  return 0;
}