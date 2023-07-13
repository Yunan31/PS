#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sequence[101];
vector<pair<int, int>> multitab;
int N, K;

int search(int idx, int num){
  for(idx+=1;idx<K;idx++){
    if(sequence[idx] == num){
      return idx;
    }
  }
  return 999;
}

void print(){
  for(int i=0;i<multitab.size();i++) cout << multitab[i].first << ":" << multitab[i].second << " ";
  cout << endl;
}

int main() {
  int answer = 0;
  cin >> N >> K;

  for(int i=0;i<K;i++){
    cin >> sequence[i];
  }

  for(int i=0;i<K;i++){
    int already = 0;
    for(int j=0;j<multitab.size();j++){
      if(multitab[j].second == sequence[i]){
        multitab[j].first = -search(i, sequence[i]);
        already++;
      }
    }

    if(already) continue;
    
    if(multitab.size() < N){
      multitab.push_back({-search(i, sequence[i]), sequence[i]});
      continue;
    }

    sort(multitab.begin(), multitab.end());

    multitab.erase(multitab.begin());
    multitab.push_back({-search(i, sequence[i]), sequence[i]});
    answer++;
  }

  
  cout << answer;
}