#include <iostream>

using namespace std;

int main() {
  int a[3];
  for(int i=0;i<3;i++){
    string str;
    cin >> str;
    if(str == "Fizz" || str == "Buzz" || str == "FizzBuzz"){
    }
    else{
      int answer = stoi(str) + (3-i);
      if(answer%15 == 0){
        cout << "FizzBuzz";
      }
      else if(answer%5 == 0){
        cout << "Buzz";
      }
      else if(answer%3 == 0){
        cout << "Fizz";
      }
      else{
        cout << answer;
      }
      break;
    }
  }
}