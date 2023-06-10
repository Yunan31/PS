#include <iostream>
#include <map>
#include <cmath>

using namespace std;

int cal_digit(int N){
  int digit = 0;
  if(N==0) return 1;
  while(N){
    N/=10;
    digit++;
  }
  return digit;
}

bool judge(map<int, bool> button, int num){
  int count = 0;
  int temp = num;
  for(int i=0;i<cal_digit(num);i++){
    if(!button[temp%10]) break;
    count++;
    temp /= 10;
  }
  if(count == cal_digit(num)) return true;
  else return false;
}

int main() {
  int N, M, broken;
  map<int, bool> button;

  cin >> N >> M;

  for(int i=0;i<10;i++){
    button[i] = true;
  }

  //버튼 비활성화
  for(int i=0;i<M;i++){
    cin >> broken;
    button[broken] = false;
  }

  //시작 채널에서 + - 만 해서 가는 경우
  int count = 10000000;
  int target = 0;

  for(int i=0;i<1000000;i++){
    if(judge(button, i)){
      int comp = cal_digit(i) + abs(N-i);
      count = min(count, comp);
    }
  }

  count = min(count, abs(N-100));

  cout << count;

  return 0;
}