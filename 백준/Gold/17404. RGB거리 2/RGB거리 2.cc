#include <iostream>

using namespace std;

int N;
int RGB[1001][3];
int DP[1001][3];

int sum_RGB(int num){
  for(int i=0;i<3;i++){
    if(i==num) continue;
    DP[1][i] = RGB[0][num] + RGB[1][i];
  }
  //N층 반복
  for(int i=0;i<N-1;i++){
    //N층 안의 기준 RGB
    for(int j=0;j<3;j++){
      //N+1층으로 DP
      for(int k=0;k<3;k++){
        if(j==k) continue;
        if(DP[i][j] + RGB[i+1][k] < DP[i+1][k]){
          DP[i+1][k] = DP[i][j] + RGB[i+1][k];
        }
      }
    }
  }
  int answer = 99999999;
  for(int i=0;i<3;i++){
    if(i==num) continue;
    answer = min(answer, DP[N-1][i]);
  }
  return answer;
}

int main() {

  cin >> N;
  for(int i=0;i<N;i++){
    cin >> RGB[i][0] >> RGB[i][1] >> RGB[i][2];
  }

  int answer = 99999999;
  for(int i=0;i<3;i++){
    fill_n(DP[0], 1001*3, 9999999);
    answer = min(answer, sum_RGB(i));
  }
  cout << answer;

  return 0;
}