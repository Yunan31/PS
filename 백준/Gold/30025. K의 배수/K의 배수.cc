#include <iostream>
#include <queue>
#define MOD 1000000007

using namespace std;

int N, M, K;
int remain[11][105];
int possible[11];
int count[1005][105] = {0};

int main() {
  cin >> N >> M >> K;
  queue<pair<int, int>> q;
  int answer = 0;
  for(int i=0;i<N;i++){
    cin >> possible[i];
    int num = possible[i];
    if(M == 1 && num == 0) answer--;
    remain[num][1] = num%K;
    count[num%K][1]++;
    for(int k=2;k<=M;k++){
      remain[num][k] = remain[num][k-1]*10%K;
    }
  }

  for(int k=1;k<M;k++){
    for(int i=0;i<K;i++){
      int rem = count[i][k];
      if(rem){
        for(int j=0;j<N;j++){
          if(possible[j] == 0 && k == M-1) continue;
          int next = remain[possible[j]][k+1];
          count[(i+next)%K][k+1] += rem;
          count[(i+next)%K][k+1] = count[(i+next)%K][k+1]%MOD;
        }
      }
    }
  }

  answer += count[0][M];
  
  cout << answer;
}