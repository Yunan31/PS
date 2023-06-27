#include <iostream>

using namespace std;

int main() {
  double a, d, k;
  int count = 1;
  double ex = 0;
  double now_p = 1;

  cin >> a >> d >> k;

  while(d < 100){
    ex += (a * count) * now_p * (d/100);
    now_p *= (1-d/100);
    d = d * (1 + k/100);
    //cout << "p: " << now_p << " count: " << count << " d: " << d << " ex: " << ex << endl;
    count++;
  }
  ex += (a * count) * now_p;

  cout.precision(10);
  cout << ex;

  return 0;
}