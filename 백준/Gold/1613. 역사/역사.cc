#include <iostream>
#include <vector>

using namespace std;

int N, K, S;
int history[404][404] = {0};
vector<pair<int, int>> question;

int main() {
  cin >> N >> K;
  for(int i=0;i<K;i++){
    int q1, q2;
    cin >> q1 >> q2;
    history[q1][q2] = 1;
  }

  cin >> S;
  for(int i=0;i<S;i++){
    int a, b;
    cin >> a >> b;
    question.push_back({a, b});
  }

  for(int i=1;i<=N;i++){
    history[i][i] = 1;
  }

  for(int k=1;k<=N;k++){
    for(int i=1;i<=N;i++){
      for(int j=1;j<=N;j++){
        if(i==j) continue;
        if(history[i][k] && history[k][j]) history[i][j] = 1;
      }
    }
  }

  for(int i=0;i<question.size();i++){
    int answer = 0;
    int q1 = question[i].first, q2 = question[i].second;

    if(history[q1][q2]) answer = -1;
    else if(history[q2][q1]) answer = 1;

    cout << answer << "\n";
  }
}