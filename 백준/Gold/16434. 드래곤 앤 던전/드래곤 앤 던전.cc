#include <iostream>

using namespace std;

int main() {
  long long N, atk;
  long long max_HP, minus_HP = 0;
  long long room_type, mon_atk, mon_HP;
  long long portion, increase;
  long long death_HP = 0;
  
  cin >> N >> atk;

  for(int i=0;i<N;i++){
    cin >> room_type;
    if(room_type == 1){
      cin >> mon_atk >> mon_HP;
      minus_HP += mon_atk*((mon_HP-1)/atk);
    }
    else{
      death_HP = max(death_HP, minus_HP);
      cin >> increase >> portion;
      atk += increase;
      minus_HP -= portion;
      if(minus_HP < 0) minus_HP = 0;
    }
  }

  cout << max(death_HP, minus_HP) + 1;

  return 0;
}