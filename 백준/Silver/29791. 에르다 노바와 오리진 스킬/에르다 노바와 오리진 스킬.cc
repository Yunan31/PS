#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> A, B;
int acur = 0, bcur = 0;
int erda = 0, origin = 0;

int main() {
  cin >> N >> M;

  for(int i=0;i<N;i++){
    int a;
    cin >> a;
    A.push_back(a);
  }

  sort(A.begin(), A.end());

  for(int i=0;i<A.size();i++){
    if(acur <= A[i]){
      erda++;
      acur = A[i]+100;
    }
  }

  for(int i=0;i<M;i++){
    int b;
    cin >> b;
    B.push_back(b);
  }

  sort(B.begin(), B.end());

  for(int i=0;i<B.size();i++){
    if(bcur <= B[i]){
      origin++;
      bcur = B[i]+360;
    }
  }

  cout << erda << " " << origin;
}