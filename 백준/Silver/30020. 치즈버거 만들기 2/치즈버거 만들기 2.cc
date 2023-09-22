#include <iostream>

using namespace std;

int main() {
  int N, M;
  cin >> N >> M;

  int meat = N, cheese = M;
  int count = 0;

  while(cheese != meat){
    if(meat >= 2 && cheese >= 1){
      meat -= 2; cheese -= 1;
      count++;
    }
    else break;
  }
  if(cheese != meat || count == 0){
    cout << "NO";
    return 0;
  }
  cout << "YES\n" << count << "\n";
  for(int i=0;i<count-1;i++){
    cout << "aba\n";
  }
  cout << "aba";
  for(int i=0;i<cheese;i++){
    cout << "ba";
  }
}