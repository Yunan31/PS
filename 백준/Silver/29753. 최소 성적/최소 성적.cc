#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int N;
double X;
string grade[9] = {"A+", "A0", "B+", "B0", "C+", "C0", "D+", "D0", "F"};
int point[9] = {450, 400, 350, 300, 250, 200, 150, 100, 0};

int main() {
  cin >> N >> X;
  X = X*100;
  X += 0.005;
  int whole = 0;
  int total = 0;

  for(int i=0;i<N-1;i++){
    int c;
    string g;
    cin >> c >> g;
    whole += c;
    for(int k=0;k<9;k++){
      if(g == grade[k]){
        total += c * point[k];
      }
    }
  }

  int target;
  int answer = 10;
  cin >> target;
  whole += target;

  //cout << (int)(X+1)*whole << endl;

  for(int i=0;i<9;i++){
    int p = total + target*point[i];
    //cout << p << endl;
    if(p >= (int)(X+1)*whole){
      answer = i;
    }
  }
  
  if(answer < 10){
    cout << grade[answer];
  }
  else cout << "impossible";
  return 0;
}