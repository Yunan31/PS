#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main() {
  string line;
  cin >> line;

  bool minus = false;
  int answer = 0;
  string num;

  for(int i=0;i<=line.size();i++){
    if(line[i] == '-' || line[i] == '+' || i == line.size()){
      if(minus){
        answer -= stoi(num);
        num = "";
      }
      else{
        answer += stoi(num);
        num = "";
      }
      
      if(line[i] == '-') minus = true;
    }
    else{
      num += line[i];
    }
  }
  
  cout << answer;
  
  return 0;
}