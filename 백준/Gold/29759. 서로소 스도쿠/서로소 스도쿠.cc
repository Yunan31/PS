#include <iostream>
#include <cmath>

using namespace std;

int sudoku[101][101];
bool eratos[1000001] = {false};
int unique[100001];
int N;

int main() {
  eratos[1] = true;
  eratos[2] = true;
  for(int i=2;i<=sqrt(300000);i++){
    for(int j=i+i;j<=300000;j+=i){
      eratos[j] = true;
    }
  }

  cin >> N;
  for(int i=0;i<N*N;i++){
    for(int j=0;j<N*N;j++){
      cin >> sudoku[i][j];
      eratos[sudoku[i][j]] = true;
    }
  }

  int num = 3, cur = 0;
  while(num <= 300000){
    if(eratos[num] == false){
      unique[cur++] = num;
    }
    num++;
  }

  cur--;

  for(int i=0;i<N*N;i++){
    for(int j=0;j<N*N;j++){
      if(sudoku[i][j] == 0) cout << unique[cur--] << " ";
      else cout << sudoku[i][j] << " ";
    }
    cout << '\n';
  }
  
}