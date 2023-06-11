#include <iostream>
#include <vector>

using namespace std;

int main() {
  long long N, M;
  int low = 0, high = 0, mid;
  vector<int> tree;

  cin >> N >> M;

  for(int i=0;i<N;i++){
    int tmp;
    cin >> tmp;
    tree.push_back(tmp);
    high = max(high, tmp);
  }
  
  long long total = 0;
  long long answer = 0;

  while(low <= high){
    mid = (high+low)/2;
    for(int i=0;i<tree.size();i++){
      if(tree[i] > mid) total += tree[i] - mid;
    }

    //cout << low << " " << high << " " << total << endl;
    
    if(total >= M){
      answer = mid;
      low = mid+1;
    }
    else{
      high = mid-1;
    }
    total = 0;
  }

  cout << answer;

  return 0;
  
}