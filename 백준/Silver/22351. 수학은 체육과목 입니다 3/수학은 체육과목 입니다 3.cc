#include <iostream>
#include <string>

using namespace std;

int main() {
  string num;

  cin >> num;

  int size = num.length();
  int start = -1, end = -1;

  for(int i=1;i<=999;i++){
    int now = i, digit = 0;
    int tmp = now;
    int idx = 0;
    while(idx < size){
      while(tmp){ digit++; tmp/=10; }
      string sub = num.substr(idx, digit);
      if(stoi(sub) == now) idx += digit;
      else break;
      now++; digit=0; tmp = now;
    }
    if(idx == size){
      start = i; end = tmp-1;
      break;
    }
  }

  cout << start << " " << end;

  return 0;
}