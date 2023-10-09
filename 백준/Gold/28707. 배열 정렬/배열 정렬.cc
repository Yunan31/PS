#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
#define INF 99999999

using namespace std;

int N, M;
vector<int> A;
vector<tuple<int, int, int>> change;
queue<pair<vector<int>, int>> q;
int visit[100000000] = {0};
int answer = INF;

int get_num(vector<int> arr){
  int num = 0;
  int mul = 1;
  for(int i=arr.size()-1;i>=0;i--){
    num += mul*(arr[i]-1);
    mul *= 10;
  }
  return num;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  fill_n(visit, 100000000, INF);
  
  cin >> N;
  for(int i=0;i<N;i++){
    int num;
    cin >> num;
    A.push_back(num);
  }
  cin >> M;
  for(int i=0;i<M;i++){
    int a, b, w;
    cin >> a >> b >> w;
    change.push_back({a-1, b-1, w});
  }

  visit[get_num(A)] = 0;
  q.push({A, 0});
  while(!q.empty()){
    vector<int> now = q.front().first;
    int cost = q.front().second;
    q.pop();

    if(cost > answer) continue;

    int judge = 0;
    for(int i=0;i<N-1;i++){
      if(now[i] > now[i+1]){
        judge++;
        break;
      }
    }
    
    if(judge){
      for(int i=0;i<M;i++){
        vector<int> next = now;
        int a = get<0>(change[i]), b = get<1>(change[i]), w = get<2>(change[i]);
        int temp = next[a];
        next[a] = next[b];
        next[b] = temp;
        if(cost+w < visit[get_num(next)]){
          // for(int i=0;i<N;i++){
          //   cout << next[i] << " ";
          // }
          // cout << endl;
          // cout << "cost: " << cost+w << endl;
          visit[get_num(next)] = cost+w;
          q.push({next, cost+w});
        }
      }
      continue;
    }
    
    answer = min(answer, cost);
  }

  if(answer == INF){
    answer = -1;
  }
  cout << answer;
}