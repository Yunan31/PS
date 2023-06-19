#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

priority_queue<int> pq;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  int N, x;

  cin >> N;

  for(int i=0;i<N;i++){
    cin >> x;
    if(x == 0){
      if(!pq.empty()){
        cout << pq.top() << "\n";
        pq.pop();
      }
      else cout << "0\n";
    }
    else{
      pq.push(x);
    }
  }
  
  return 0;
}