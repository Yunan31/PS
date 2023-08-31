#include <iostream>

using namespace std;

int sticker[6] = {0, 5, 5, 5, 5, 5};
int map[10][10];
int answer = 25;

bool judge(int x, int y, int size){
  if(x+size > 10 || y+size > 10) return false;
  
  int count = 0;
  for(int i=x;i<x+size;i++){
    for(int j=y;j<y+size;j++){
      if(map[i][j] == 0) return false;
    }
  }
  return true;
}

void fill(int x, int y, int size, int type){
  for(int i=x;i<x+size;i++){
    for(int j=y;j<y+size;j++){
      map[i][j] = type;
    }
  }
}

int dfs(int x, int y, int depth){
  if(answer < depth) return 0;
  int count = 0;
  for(int i=0;i<10;i++){
    for(int j=0;j<10;j++){
      if(map[i][j] == 1) count++;
    }
  }
  if(count == 0){
    answer = min(answer, depth);
    return 0;
  }

  if(y >= 10){ x++; y=0;}
  for(int i=x;i<10;i++){
    int j = 0;
    if(i == x) j = y;
    
    for(;j<10;j++){
      if(map[i][j] == 1){
        for(int size = 5; size >= 1; size--){
          if(sticker[size] == 0) continue;
          if(judge(i, j, size)){
            fill(i, j, size, 0);
            sticker[size]--;
            
            dfs(i, j+1, depth+1);
            
            sticker[size]++;
            fill(i, j, size, 1);
          }
        }
        return 0;
      }
    }
  }
}

int main() {
  for(int i=0;i<10;i++){
    for(int j=0;j<10;j++){
      cin >> map[i][j];
    }
  }

  dfs(0, 0, 0);

  if(answer == 25) answer = -1;
  cout << answer;

  return 0;
}