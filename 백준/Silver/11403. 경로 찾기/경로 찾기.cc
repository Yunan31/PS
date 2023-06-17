#include <iostream>

using namespace std;

int main() {
  int N, node;
  int graph[105][105];
  cin >> N;

  for(int i=1;i<=N;i++){
    for(int j=1;j<=N;j++){
      cin >> node;
      graph[i][j] = node;
    }
  }

  for(int k=1;k<=N;k++){
    for(int i=1;i<=N;i++){
      for(int j=1;j<=N;j++){
        if(graph[i][k] && graph[k][j]) graph[i][j] = 1;
      }
    }
  }

  for(int i=1;i<=N;i++){
    for(int j=1;j<=N;j++){
      cout << graph[i][j] << " ";
    }
    cout << "\n";
  }
}