#include <iostream>

using namespace std;

int main() {
  int n = 12;
  char arr[4] = {'N', 'E', 'S', 'W'};
  for(int i=0;i<10;i++){
    int k;
    cin >> k;
    if(k==1) n++;
    if(k==2) n+=2;
    if(k==3) n--;
  }
  cout << arr[n%4];
}