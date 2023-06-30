#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int main() {
  int T;
  cin >> T;

  while(T--){
    string command, num;
    int size;
    string arr[100005];
    cin >> command;
    cin >> size;
    cin >> num;
    
    istringstream ss(num);
    string buffer;
    int idx = 0;
    while(getline(ss, buffer, ',')){
      if(buffer[0] == '[') buffer.erase(buffer.begin());
      if(buffer[buffer.size()-1] == ']') buffer.erase(buffer.end()-1);
      if(buffer == "") continue;
      arr[idx++] = buffer;
    }

    int cur = 0, rcur = size-1;
    bool type = false;
    string answer = "[";
    int flag = 0, error = 0;
    for(int i=0;i<command.size();i++){
      if(command[i] == 'R') type = !type;
      if(command[i] == 'D'){
        if(cur > rcur){
          error = 1; break;
        }
        if(type == 0) cur++;
        else rcur--;
      }
    }
    if(type == 0){
      for(int i=cur;i<=rcur;i++){
        if(flag) answer += ',';
        else flag = 1;
        answer += arr[i];
      }
    }
    else{
      for(int i=rcur;i>=cur;i--){
        if(flag) answer += ',';
        else flag = 1;
        answer += arr[i];
      }
    }
    answer += "]\n";
    if(error) answer = "error\n";
    cout << answer;
  }

  return 0;
}