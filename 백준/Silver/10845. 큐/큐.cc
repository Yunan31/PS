#include <iostream>
#include <queue>

using namespace std;

int main() {
  int N;
  string query;
  queue<int> Q;
  
  cin >> N;

  for(int i=0;i<N;i++){
    cin >> query;

    if((query == "back" || query == "front" || query == "pop") && Q.empty()){
      cout << "-1\n";
      continue;
    }

    
    if(query == "push"){
      int num;
      cin >> num;
      Q.push(num);
    }else if(query == "back"){
      cout << Q.back() << "\n";
    }else if(query == "front"){
      cout << Q.front() << "\n";
    }else if(query == "size"){
      cout << Q.size() << "\n";
    }else if(query == "empty"){
      if(Q.empty()) cout << "1\n";
      else cout << "0\n";
    }else if(query == "pop"){
      cout << Q.front() << "\n";
      Q.pop();
    }
  }
}