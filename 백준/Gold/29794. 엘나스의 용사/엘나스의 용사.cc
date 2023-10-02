#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, K;
int hero[630000], hunting[630000] = {0};
long long floor[202] = {0};
vector<pair<int, int>> monster;

int main() {
  cin >> N >> M >> K;

  for(int i=0;i<N;i++){
    cin >> hero[i];
  }

  for(int i=1;i<=M;i++){
    int level;
    cin >> level;
    monster.push_back({level, i});
  }

  sort(monster.begin(), monster.end());

  for(int k=0;k<K;k++){
    for(int i=0;i<N;i++){
      if(hero[i]+k >= 200) continue;
      while(hero[i]+k >= monster[hunting[i]].first && hunting[i] < M){
        hunting[i]++;
      }
      floor[monster[hunting[i]-1].second]++;
    }
  }

  // for(int i=1;i<=M;i++){
  //   cout << i << " " << floor[i] << endl;
  // }

  long long answer = 0;
  int x = 1, y = 2;
  for(int from=1;from<M;from++){
    for(int to=from+1;to<=M;to++){
      long long save = 0;
      for(int i=2;i<=M;i++){
        if(floor[i] == 0) continue;
        if((from-1) + abs(i-to) < i-1){
          save += ((i-1) - ((from-1) + abs(i-to))) * floor[i];
        }
      }
      if(save > answer){
        x = from; y = to;
        answer = save;
      }
      //cout << from << " " << to << " " << save << endl;
    }
  }

  // for(int stone=2;stone<=M;stone++){
  //   long long save = 0;
  //   for(int i=2;i<=M;i++){
  //     if(floor[i] == 0) continue;
  //     if(abs(i-stone) < i-1){
  //       save += ((i-1) - abs(i-stone)) * floor[i];
  //     }
  //   }

  //   if(save > answer){
  //     x = 1; y = stone;
  //     answer = save;
  //   }
  // }
  cout << x << " " << y << "\n";
  cout << answer;
}