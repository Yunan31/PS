#include <iostream>
#include <string>

using namespace std;

int main() {
  string str[105], hubo[105];
  int N, M;
  int idx;
  char st = ' ', ed = ' ';

  cin >> N;
  for(int i=1;i<=N;i++){
    cin >> str[i];
    if(str[i] == "?"){
      idx = i;
    }
  }
  if(idx > 1){
    st = str[idx-1].back();
  }
  if(idx < N){
    ed = str[idx+1].front();
  }

  cin >> M;
  for(int i=0;i<M;i++){
    cin >> hubo[i];
  }

  for(int i=0;i<M;i++){
    int count = 0;

    if(st != ' '){
      if(hubo[i].front() == st) count++;
    } else count++;
    if(ed != ' '){
      if(hubo[i].back() == ed) count++;
    } else count++;
    if(count==2){
      for(int k=1;k<=N;k++){
        if(hubo[i] == str[k]) { count++; break; }
      }
    }
    if(count==2) cout << hubo[i];
  }

  

  return 0;
}