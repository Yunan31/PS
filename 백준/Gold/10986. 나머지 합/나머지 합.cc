#include <iostream>

using namespace std;

int pre[1000001];
int count[1001] = {0};

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int N, M, A;
  cin >> N >> M;

  pre[0] = 0;
  for(int i=1;i<=N;i++){
    cin >> A;
    pre[i] = (pre[i-1] + A)%M;
    count[pre[i]]++;
  }

  long long answer = count[0];
  for(int i=0;i<M;i++){
    if(count[i] > 1)
      answer += ((long long)count[i] * (count[i]-1)) / 2;
  }

  cout << answer;
  
  return 0;
}