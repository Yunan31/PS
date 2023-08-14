#include <iostream>

using namespace std;

int r[10][10] = {0}, c[10][10] = {0}, box[10][10] = {0};
int map[9][9];

void dfs(int count){
  if(count == 81){
    for(int i=0;i<9;i++){
      for(int j=0;j<9;j++){
        cout << map[i][j];
      }
      cout << "\n";
    }
    exit(0);
  }
  int x = count/9, y = count%9;

  if(map[x][y]){
    dfs(count+1);
  }
  else{
    for(int i=1;i<=9;i++){
      if(!r[i][x] && !c[i][y] && !box[i][(x/3)*3+(y/3)]){
        r[i][x] = 1; c[i][y] = 1; box[i][(x/3)*3+(y/3)] = 1;
        map[x][y] = i;
        dfs(count+1);
        map[x][y] = 0;
        r[i][x] = 0; c[i][y] = 0; box[i][(x/3)*3+(y/3)] = 0;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  for(int i=0;i<9;i++){
    string str;
    cin >> str;
    for(int j=0;j<9;j++){
      map[i][j] = str[j] - '0';
      if(map[i][j]){
        r[map[i][j]][i] = 1; c[map[i][j]][j] = 1; box[map[i][j]][(i/3)*3+(j/3)] = 1;
      }
    }
  }

  dfs(0);
}