#include <iostream>

using namespace std;

int comp[105][105] = {0};
int N, M;

int main() {
  cin >> N >> M;
  for(int i=0;i<M;i++){
    int w1, w2;
    cin >> w1 >> w2;
    comp[w1][w2]++;
  }

  for(int i=1;i<=N;i++){
    comp[i][i]++;
  }

  for(int k=1;k<=N;k++){
    for(int i=1;i<=N;i++){
      for(int j=1;j<=N;j++){
        if(i==j) continue;
        if(comp[i][k] && comp[k][j]){
          comp[i][j] = 1;
        }
      }
    }
  }

  for(int i=1;i<=N;i++){
    int answer = N;
    for(int j=1;j<=N;j++){
      if(comp[i][j] || comp[j][i]){
        answer--;
      }
    }
    cout << answer << "\n";
  }
}