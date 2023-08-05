#include <iostream>

using namespace std;

int N;
int chess[11][11];
int right_bottom[22] = {0}, left_bottom[22] = {0};

int bishop(int x, int y, int color){
  if(y >= N){
    x++;
    if(y%2 == 0) y = 1;
    else y = 0;
  }
  if(x == N) return 0;

  int answer = 0;
  if(chess[x][y]){
    //우하향 -> x-y 값이 같음, 좌하향 -> x+y 값이 같음
    if(!right_bottom[x-y + N-1] && !left_bottom[x+y]){
      right_bottom[x-y + N-1] = 1; left_bottom[x+y] = 1;
      answer = max(answer, bishop(x, y+2, color) + 1);
      right_bottom[x-y + N-1] = 0; left_bottom[x+y] = 0;
    }
  }
  answer = max(answer, bishop(x, y+2, color));

  return answer;
}

int main() {
  cin >> N;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cin >> chess[i][j];
    }
  }

  int answer = 0;
  //흑 0 백 1
  answer += bishop(0, 0, 0);
  answer += bishop(0, 1, 1);

  cout << answer;
}