#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int T, x, y;

  scanf("%d", &T);

  for(int i=0;i<T;i++){
    scanf("%d %d", &x, &y);

    long long dis = y-x;
    int count=0;
    double root = sqrt(y-x);
    int n = (int)root;
      
    count = 2*n - 1;

    if(dis-n*n!=0)
      count += (dis-n*n-1)/n+1;
    if(dis==1) count=1;
    printf("%d\n", count);
  }
} 