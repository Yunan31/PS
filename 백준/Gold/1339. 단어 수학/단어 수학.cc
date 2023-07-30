#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int main() {
  string num[10];
  int N, answer = 0;
  int size = 0, idx = 0;
  char value[10] = {0};

  cin >> N;
  for(int i=0;i<N;i++){
    cin >> num[i];
    if(size < num[i].length()){
      size = num[i].length();
    }
  }

  for(int i=0;i<N;i++){
    string tmp = "";
    for(int k=0;k<size-num[i].length();k++){
      tmp += ' ';
    }
    num[i] = tmp + num[i];
  }

  int mul = 1, count[26] = {0};
  for(int i=size-1;i>=0;i--){
    for(int j=0;j<N;j++){
      if(num[j][i] == ' ') continue;
      count[num[j][i]-'A'] += mul;
    }
    mul*=10;
  }

  priority_queue<pair<int, char>> pq;
  for(int i=0;i<26;i++){
    if(count[i]) pq.push({count[i], 'A'+i});
  }

  while(!pq.empty()){
    char now = pq.top().second;
    pq.pop();
    value[idx++] = now;
  }

  for(int i=0;i<N;i++){
    for(int j=0;j<size;j++){
      if(num[i][j] == ' ') continue;

      for(int k=0;k<idx;k++){
        if(num[i][j] == value[k]){
          num[i][j] = '9'-k;
        }
      }
    }

    answer += stoi(num[i]);
  }

  cout << answer;
}