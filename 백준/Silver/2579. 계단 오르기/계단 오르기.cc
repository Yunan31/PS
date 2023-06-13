#include <iostream>
#include <vector>

using namespace std;

vector<int> stair;
int max_score[10005][3] = {0};

int score(int N, int index, int continues, int sum){
  if(index>=N) return 0;
  if(continues == 3) return 0;

  if(sum+stair[index] >= max_score[index][continues])
    max_score[index][continues] = sum+stair[index];
  else return 0;
  
  score(N, index+1, continues+1, sum+stair[index]);
  score(N, index+2, 1, sum+stair[index]);

  return 0;
}

int main() {
  int N, num;

  cin >> N;

  for(int i=0;i<N;i++){
    cin >> num;
    stair.push_back(num);
  }

  score(N, 0, 1, 0);
  score(N, 1, 1, 0);

  cout << max(max_score[N-1][1], max_score[N-1][2]);

  return 0;
}