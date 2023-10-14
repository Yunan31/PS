#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int N, M;
vector<tuple<int, int, int>> stream;
vector<string> names;
int real[105] = {0};

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> N >> M;

  for(int i=0;i<N;i++){
    string name, start, end;
    int day, st, ed, idx = names.size();

    cin >> name >> day >> start >> end;
    day = (day-1)/7;
    st = stoi(start.substr(0, 2))*60 + stoi(start.substr(3, 2));
    ed = stoi(end.substr(0, 2))*60 + stoi(end.substr(3, 2));

    for(int j=0;j<names.size();j++){
      if(names[j].compare(name) == 0){
        idx = j;
        break;
      }
    }

    if(idx == names.size()) names.push_back(name);

    stream.push_back({day, idx, ed-st});
  }

  sort(stream.begin(), stream.end());

  int now = 0;
  for(int i=0;i<M/7;i++){
    int stream_time[101] = {0};
    int stream_day[101] = {0};
    
    while(get<0>(stream[now]) == i && now < N){
      stream_time[get<1>(stream[now])] += get<2>(stream[now]);
      stream_day[get<1>(stream[now])]++;
      now++;
    }

    for(int k=0;k<names.size();k++){
      if(stream_time[k] >= 60*60 && stream_day[k] >= 5){
        real[k]++;
      }
    }
  }

  vector<string> answer;
  for(int i=0;i<names.size();i++){
    if(real[i] == M/7){
      answer.push_back(names[i]);
    }
  }

  if(answer.size() == 0) cout << -1;
  else{
    sort(answer.begin(), answer.end());
    for(int i=0;i<answer.size();i++){
      cout << answer[i] << "\n";
    }
  }
}