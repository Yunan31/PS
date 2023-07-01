#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int N, T;
  vector<int> arr;
  int input[200002];
  int time;
  cin >> N >> T;
  for(int i=0;i<N;i++){
    cin >> time;
    input[i] = time;
  }
  sort(input, input+N);

  int low = 1, high = 200000;
  int mid;
  while(low <= high){
    mid = (low+high)/2;
    priority_queue<int> pq;
    if(mid > N){ high = mid-1; continue; }
    int count = 0;
    for(int i=0;i<N;i++){
      int now = input[i];
      if(count < mid){
        pq.push(-max(now, T)); count++;
      }
      else{
        int top = -pq.top();
        if(top < now){
          pq.pop();
          pq.push(-max(top+T, now));
          count++;
        }
        else break;
      }
    }
    if(count == N) high = mid-1;
    else low = mid+1;
  }
  cout << low;
  return 0;
}