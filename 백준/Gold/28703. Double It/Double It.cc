#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int A[200005];
int N;

int main() {
  cin >> N;
  for(int i=0;i<N;i++){
    cin >> A[i];
  }

  sort(A, A+N);

  int answer = A[N-1] - A[0];
  int high = A[N-1];
  int end = A[N-1];

  priority_queue<int> pq;

  for(int i=0;i<N;i++){
    pq.push(-A[i]);
  }

  while(-pq.top() != end){
    int now = -pq.top();
    pq.pop();
    now*=2;

    if(now > high){
      high = now;
    }

    pq.push(-now);
    now = -pq.top();

    if(high - now < answer){
      answer = high - now;
      end = high;
    }

    //cout << now << " " << answer << "\n";
  }

  cout << answer;
}