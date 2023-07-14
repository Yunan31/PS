#include <iostream>

using namespace std;

int main() {
  string str1 = " ", str2 = " ";
  int DP[1001][1001] = {0};

  string input;
  cin >> input; str1 += input;
  cin >> input; str2 += input;

  for(int i=1;i<str1.size();i++){
    for(int j=1;j<str2.size();j++){
      if(str1[i] == str2[j]){
        DP[i][j] = DP[i-1][j-1] + 1;
      }
      else{
        DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
      }
    }
  }

  // for(int i=0;i<str1.size();i++){
  //   for(int j=0;j<str2.size();j++) cout << DP[i][j] << " ";
  //   cout << endl;
  // }

  cout << DP[str1.size()-1][str2.size()-1];
}