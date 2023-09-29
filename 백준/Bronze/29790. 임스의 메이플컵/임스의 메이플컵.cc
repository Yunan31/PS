#include <iostream>

using namespace std;

int main() {
  int N, U, L;
  cin >> N >> U >> L;

  bool f1 = false, f2 = false, f3 = false;

  if(N >= 1000) f1 = true;
  if(U >= 8000) f2 = true;
  if(L >= 260) f3 = true;

  if(f1 && (f2 || f3)) cout << "Very Good";
  else if(f1) cout << "Good";
  else cout << "Bad";
}