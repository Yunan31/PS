#include <iostream>

using namespace std;

int N, K;
int s[1001], h[1001];
int DP[1001][101] = {0};

int main() {
  cin >> N >> K;
  for(int i=1;i<=N;i++){
    cin >> s[i];
  }

  for(int i=1;i<=N;i++){
    cin >> h[i];
  }

  for(int i=1;i<=N;i++){
    for(int j=0;j<=100;j++){
      if(j - h[i] >= 0){
        DP[i][j] = max(DP[i-1][j], DP[i-1][j-h[i]] + s[i]);
      }
      else DP[i][j] = DP[i-1][j];
    }

    for(int j=0;j<=100;j++){
      int hp = min(100, j+K);
      DP[i][j] = max(DP[i][hp], DP[i-1][hp]);
    }
  }

  // for(int i=1;i<=N;i++){
  //   for(int j=0;j<=100;j++){
  //     if(j == 50) cout << endl;
  //     cout << DP[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  int answer = 0;
  for(int i=0;i<=100;i++){
    answer = max(answer, DP[N][i]);
  }

  cout << answer;
  
}