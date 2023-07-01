#include <iostream>

using namespace std;

char tile[505][505];
int count[505][505][26];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int N, M, K;
  cin >> N >> M >> K;

  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      cin >> tile[i][j];
    }
  }

  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      count[i%K][j%K][tile[i][j]-'A']++;
    }
  }

  int result[K][K];
  for(int i=0;i<K;i++){
    for(int j=0;j<K;j++){
      int max = -1, idx = 0;
      for(int k=0;k<26;k++){
        if(max < count[i][j][k]){
          max = count[i][j][k]; idx = k;
        }
      }
      result[i][j] = idx;
    }
  }

  int answer=0;
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      if(tile[i][j]-'A' != result[i%K][j%K]){
        tile[i][j] = 'A'+result[i%K][j%K];
        answer++;
      }
    }
  }

  cout << answer << "\n";
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      cout << tile[i][j];
    }
    cout << "\n";
  }
}