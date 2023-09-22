#include <iostream>
#include <vector>

using namespace std;

int used[5005] = {0};

bool judge(int num){
  if(num == 1) return true;
  for(int i=2;i<num/2+1;i++){
    if(num%i==0) return true;
  }
  return false;
}

int main() {
  int N;
  cin >> N;

  vector<int> seq;
  int total = 0;
  for(int i=0;i<N;i++){
    for(int k=1;k<=N;k++){
      if(used[k]) continue;
      if(judge(total+k) == true){
        seq.push_back(k);
        total += k;
        used[k] = 1;
        break;
      }
    }
  }

  for(int i=1;i<=N;i++){
    if(used[i] == 0){
      cout << "NO"; return 0;
    }
  }

  cout << "YES\n";
  for(int i=0;i<seq.size();i++){
    cout << seq[i] << " ";
  }
}