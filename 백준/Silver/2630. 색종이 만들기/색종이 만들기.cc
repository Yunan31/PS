#include <iostream>

using namespace std;

int paper[128][128];

int check(int color, int x, int y, int n){
  int sum = 0, count = 0;

  for(int i=x;i<x+n;i++){
    for(int j=y;j<y+n;j++){
      if(paper[i][j] == color) count++;
    }
  }
  if(count == n*n) return 1;
  if(count == 0) return 0;

  for(int i=0;i<2;i++){
    for(int j=0;j<2;j++){
      sum += check(color, x+i*(n/2), y+j*(n/2), n/2);
    }
  }

  return sum;
}

int main() {
  int N, input;
  cin >> N;

  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cin >> input;
      paper[i][j] = input;
    }
  }

  cout << check(0, 0, 0, N) << "\n";
  cout << check(1, 0, 0, N);
}