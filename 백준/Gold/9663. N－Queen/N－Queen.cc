#include <iostream>

using namespace std;

int N;
int chess[16][16] = {0};

bool judge(int x, int y){
  //세로
  for(int i=0;i<x;i++){
    if(chess[i][y] == 1) return false;
  }

  //우상향
  for(int i=1;i<=x;i++){
    int nx = x-i, ny = y+i;
    if(ny >= N) break;
    if(chess[nx][ny] == 1) return false;
  }
  //좌상향
  for(int i=1;i<=x;i++){
    int nx = x-i, ny = y-i;
    if(ny < 0) break;
    if(chess[nx][ny] == 1) return false;
  }
  
  return true;
}

int N_Queen(int x, int y){
  if(!judge(x, y)) return 0;
  if(x == N-1) return 1;

  int total = 0;
  for(int i=0;i<N;i++){
    chess[x+1][i] = 1;
    total += N_Queen(x+1, i);
    chess[x+1][i] = 0;
  }

  return total;
}

int main() {
  cin >> N;

  int answer = 0;
  for(int i=0;i<N;i++){
    chess[0][i] = 1;
    answer += N_Queen(0, i);
    chess[0][i] = 0;
  }

  cout << answer;

  return 0;
}