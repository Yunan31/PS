#include <iostream>
#include <cmath>

using namespace std;

int T, N, L;

int main() {
  cin >> T;
  while(T--){
    cin >> N >> L;
    if(L > 5){
      cout << 0 << "\n";
      continue;
    }
    int DP[70007][10] = {0};

    DP[N][1] = 1;
    
    for(int i=1;i<L;i++){
      for(int j=N;j>=2;j--){
        if(DP[j][i]){
          for(int k=1;k<sqrt(j);k++){
            DP[k][i+1] += DP[j][i];
          }
        }
      }
    }

    // for(int i=1;i<=L;i++){
    //   for(int j=1;j<=264;j++){
    //     cout << DP[j][i] << " ";
    //     if(j%100 == 0) cout << endl;
    //   }
    //   cout << "\n--------------\n";
    // }

    cout << DP[1][L] << "\n";
  }
}