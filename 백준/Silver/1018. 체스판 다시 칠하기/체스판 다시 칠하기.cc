#include <iostream>
#include <vector>

using namespace std;

int solve_chess(char chess[][100], int x, int y, char norm){
  int count = 64;
  bool flag = true;
  
  for(int i=x;i<x+8;i++){
    for(int j=y;j<y+8;j++){
      if(flag){
        if(chess[i][j] == norm) {
          count--;
        }
      }
      else{
        if(chess[i][j] != norm) {
          count--;
        }
      }
      if(j != y+7) flag = !flag;
    }
  }
  return count;
}

int main() {
  int N, M;
  char chess[100][100];
  int answer = 64;

  cin >> N >> M;

  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      char c;
      cin >> c;
      chess[i][j] = c;
    }
  }

  for(int i=0;i<N-7;i++){
    for(int j=0;j<M-7;j++){
      int temp = min(solve_chess(chess, i, j, 'W'), solve_chess(chess, i, j, 'B'));
      answer = min(answer, temp);
    }
  }

  cout << answer;

  return 0;
}