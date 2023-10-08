#include <iostream>
#include <vector>

using namespace std;

int T, N;

int main() {
  cin >> T;
  while(T--){
    cin >> N;
    int turn[7] = {0};
    
    turn[1] = 1;

    for(int i=1;i<=N;i++){
      char op1, op2;
      int v1, v2;

      cin >> op1 >> v1 >> op2 >> v2;
      int todo[7] = {0};
      for(int j=0;j<7;j++){
        if(turn[j] == i) todo[j]++;
      }
      for(int j=0;j<7;j++){
        if(todo[j] != 0){

          if(op1 == '+'){
            turn[(j+v1)%7] = i+1;
          }
          else{
            turn[(j*v1)%7] = i+1;
          }

          if(op2 == '+'){
            turn[(j+v2)%7] = i+1;
          }
          else{
            turn[(j*v2)%7] = i+1;
          }
        }
      }
    }

    if(turn[0] == N+1){
      cout << "LUCKY\n";
    }
    else{
      cout << "UNLUCKY\n";
    }
  }
}