#include <iostream>

using namespace std;

int DP[100001] = {0};
int pre[100001] = {0};
int num[100001];

int main() {
  int N, M;
  
  cin >> N >> M;
  for(int i=1;i<=N;i++){
    cin >> num[i];
    pre[i] = pre[i-1] + num[i];
  }

  DP[M] = pre[M];
  for(int i=M+1;i<=N;i++){
    DP[i] = max(DP[i-1]+num[i], pre[i]-pre[i-M]);
  }

  int answer = 0;
  for(int i=M;i<=N;i++){
    answer = max(answer, DP[i]);
  }

  cout << answer;

  return 0;
}