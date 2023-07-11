#include <iostream>

using namespace std;

int DP[61][61][61] = {0};
int action[6][3] = {
{9, 3, 1}, {9, 1, 3}, {1, 9, 3}, {3, 9, 1}, {1, 3, 9}, {3, 1, 9}
};

int DFS(int x, int y, int z){
  if(x <= 0 && y <= 0 && z <= 0) return 0;
  if(DP[x][y][z]) return DP[x][y][z];
  int answer = 999999;
  for(int i=0;i<6;i++){
    int nx = x-action[i][0], ny = y-action[i][1], nz = z-action[i][2];
    if(nx < 0) nx = 0;
    if(ny < 0) ny = 0;
    if(nz < 0) nz = 0;
    answer = min(answer, 1 + DFS(nx, ny, nz));
  }
  DP[x][y][z] = answer;
  return answer;
}

int main() {
  int N;
  cin >> N;

  int input[3] = {0};
  for(int i=0;i<N;i++){
    cin >> input[i];
  }

  cout << DFS(input[0], input[1], input[2]);
  return 0;
}