#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, A, B, p[100005], q[100005];
vector<pair<int, int>> diff;

int main() {
  cin >> N >> A >> B;
  for(int i=0;i<N;i++){
    cin >> p[i] >> q[i];
    diff.push_back({-abs(p[i] - q[i]), i});
  }

  sort(diff.begin(), diff.end());

  long long answer = 0;
  int A_count = 0, B_count = 0;
  for(int i=0;i<N;i++){
    int pi = p[diff[i].second], qi = q[diff[i].second];
    if(A_count == A){
      answer += qi;
      B_count++;
      continue;
    }
    if(B_count == B){
      answer += pi;
      A_count++;
      continue;
    }
    
    if(diff[i].first == 0){
      if(A-A_count > B-B_count){
        answer += pi;
        A_count++;
      }
      else{
        answer += qi;
        B_count++;
      }
    }
    else{
      if(pi < qi){
        answer += pi;
        A_count++;
      }
      else{
        answer += qi;
        B_count++;
      }
    }
  }

  cout << answer;
}