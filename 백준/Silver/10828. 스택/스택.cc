#include <iostream>

using namespace std;

int main() {
  int N;
  cin >> N;
  int stack[N], size = 0, cur = 0;
  string query;

  for(int i=0;i<N;i++){
    cin >> query;
    if(!query.compare("push")){
      int num;
      cin >> num;
      stack[cur++] = num;
      size++;
    }else if(!query.compare("pop")){
      if(size == 0) cout << "-1\n";
      else {
        cout << stack[cur-1] << "\n";
        size--; cur--;
      }
    }else if(!query.compare("size")){
      cout << size << "\n";
    }else if(!query.compare("empty")){
      if(size == 0) cout << "1\n";
      else cout << "0\n";
    }else if(!query.compare("top")){
      if(size == 0) cout << "-1\n";
      else cout << stack[cur-1] << "\n";
    }
  }
}