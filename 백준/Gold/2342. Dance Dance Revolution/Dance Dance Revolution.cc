#include <iostream>
#define INF 999999

using namespace std;

int DP[100005][5][5];
int input[100005];

int main() {
  fill_n(DP[0][0], 100005*5*5, INF);

  int in, N = 0;
  while(true){
    cin >> in;
    if(in == 0) break;
    input[N++] = in;
  }

  DP[0][0][0] = 0;
  for(int i=0;i<N;i++){
    int now = input[i];
    for(int x=0;x<5;x++){
      for(int y=0;y<5;y++){
        if(DP[i][x][y] != INF){
          //0이 존재하는 경우
          if(x == 0){
            DP[i+1][now][y] = min(DP[i+1][now][y], DP[i][x][y] + 2);
          }
          if(y == 0){
            DP[i+1][x][now] = min(DP[i+1][x][now], DP[i][x][y] + 2);
            
          }

          if(abs(x-now) == 0){
            DP[i+1][now][y] = min(DP[i+1][now][y], DP[i][x][y] + 1);
          }
          else if(abs(x-now) == 1 || abs(x-now) == 3){
            DP[i+1][now][y] = min(DP[i+1][now][y], DP[i][x][y] + 3);
          }
          else if(abs(x-now) == 2){
            DP[i+1][now][y] = min(DP[i+1][now][y], DP[i][x][y] + 4);
          }

          if(abs(y-now) == 0){
            DP[i+1][x][now] = min(DP[i+1][x][now], DP[i][x][y] + 1);
          }
          else if(abs(y-now) == 1 || abs(y-now) == 3){
            DP[i+1][x][now] = min(DP[i+1][x][now], DP[i][x][y] + 3);
          }
          else if(abs(y-now) == 2){
            DP[i+1][x][now] = min(DP[i+1][x][now], DP[i][x][y] + 4);
          }
        }
      }
    }
  }

  int answer = INF;
  for(int i=0;i<5;i++){
    for(int j=0;j<5;j++){
      answer = min(answer, DP[N][i][j]);
    }
  }

  cout << answer;
}