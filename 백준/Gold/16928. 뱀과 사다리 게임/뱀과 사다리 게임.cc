#include <iostream>

using namespace std;

int snake[101] = {0};
int ladder[101] = {0};
int map[101];

void roll_dice(){
  for(int i=1;i<=100;i++){
    for(int dice=1;dice<=6;dice++){
      if(i+dice > 100) break;
      int next = i + dice;
      if(ladder[next]) next = ladder[next];
      if(snake[next]) next = snake[next];

      map[next] = min(map[next], map[i] + 1);
    }
  }
}

int main() {
  int N, M;
  int start, end;

  cin >> N >> M;

  for(int i=0;i<N;i++){
    cin >> start >> end;
    ladder[start] = end;
  }

  for(int i=0;i<M;i++){
    cin >> start >> end;
    snake[start] = end;
  }

  fill_n(map, 101, 999999);

  map[1] = 0;
  roll_dice();
  roll_dice();

  cout << map[100];

  return 0;
}