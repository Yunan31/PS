#include <iostream>

using namespace std;

int N;
int light[100005];
int temp[100005];

int change(int color){
  if(color < 3) return color+1;
  else return 1;
}

int judge(int target, int offset){
  if(N-offset == 3){
    if(temp[offset] == temp[offset+1] && temp[offset] == temp[offset+2]){
      if(target-temp[offset] >= 0){
        return target-temp[offset];
      }
      else if(target-temp[offset] == -1) return 2;
      else if(target-temp[offset] == -2) return 1;
    }
    else return -1;
  }

  int cnt = 0;
  while(temp[offset] != target){
    temp[offset] = change(temp[offset]);
    temp[offset+1] = change(temp[offset+1]);
    temp[offset+2] = change(temp[offset+2]);
    cnt++;
  }

  int sub = judge(target, offset+1);
  if(sub != -1) return cnt+sub;
  else return -1;
}

int main() {
  cin >> N;
  for(int i=0;i<N;i++){
    char c;
    cin >> c;
    if(c == 'R') light[i] = 1;
    if(c == 'G') light[i] = 2;
    if(c == 'B') light[i] = 3;
  }

  int answer = 99999999;
  for(int i=1;i<=3;i++){
    for(int k=0;k<N;k++){
      temp[k] = light[k];
    }
    int ans = judge(i, 0);
    if(ans != -1) answer = min(answer, ans);
  }
  if(answer == 99999999) answer = -1;
  cout << answer;
}