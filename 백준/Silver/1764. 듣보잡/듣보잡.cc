#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  map<string, int> map;
  vector<string> overlap;
  string name;
  int count = 0;
  
  for(int i=0;i<N+M;i++){
    cin >> name;
    map[name]++;
  }

  for(auto temp : map){
    if(temp.second == 2){
      count++;
      overlap.push_back(temp.first);
    }
  }

  cout << count << "\n";
  for(auto str : overlap){
    cout << str << "\n";
  }
}