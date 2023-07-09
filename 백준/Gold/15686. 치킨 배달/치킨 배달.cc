#include <iostream>
#include <queue>

using namespace std;

int N, M;
int map[55][55];

//각 좌표에서 가장 가까운 치킨 거리 계산
int chicken_road(int x, int y){
  int dist = 99999;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(map[i][j] == 2){
        dist = min(dist, abs(x - i) + abs(y - j));
      }
    }
  }
  return dist;
}

//백트래킹으로 치킨집 하나씩 문을 닫아봄 - 브루트포스
//치킨집 닫을게 없으면 치킨 거리를 반환
int close_shop(int x, int y, int count){
  int answer = 99999;
  if(count == 0){
    int sum = 0;
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
        if(map[i][j] == 1) sum += chicken_road(i, j);
      }
    }
    return sum;
  }

  //조합을 뽑기 위하여 탐색 범위를 x, y 좌표 다음부터 시작
  for(int i=x;i<N;i++){
    int j=0; if(i == x) j = y;
    for(;j<N;j++){
      if(map[i][j] == 2){
        map[i][j] = 0;
        answer = min(answer, close_shop(i, j, count-1));
        map[i][j] = 2;
      }
    }
  }
  return answer;
}


int main() {
  cin >> N >> M;

  int shop = 0, answer = 0;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cin >> map[i][j];
      if(map[i][j] == 2) shop++;
    }
  }
  
  cout << close_shop(0, 0, shop - M);
  
  return 0;
}