#include <iostream>
#include <cmath>

using namespace std;

int s, N, K;
int R1, R2, C1, C2;
//int answer[55][55] = {0};
int root_map[10][10] = {0};

int color(int x, int y, int s){
  if(s == 0) return 0;
  int div = pow(N, s-1);
  int tx = x/div, ty = y/div;
  if(s == 1) return root_map[tx][ty];
  if(root_map[tx][ty]) return 1;
  
  return color(x - tx*div, y - ty*div, s-1);
}

int main() {
  cin >> s >> N >> K >> R1 >> R2 >> C1 >> C2;
  
  int start = N/2 - K/2;
  int end = start + K-1;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(i >= start && i <= end && j >= start && j <= end) root_map[i][j] = 1;
    }
  }

  for(int i=R1;i<=R2;i++){
    for(int j=C1;j<=C2;j++){
      cout << color(i, j, s);
    }
    cout << endl;
  }
  
  // for(int i=0;i<=R2-R1;i++){
  //   for(int j=0;j<=C2-C1;j++) cout << answer[i][j];
  //   cout << endl;
  // }

  return 0;
}