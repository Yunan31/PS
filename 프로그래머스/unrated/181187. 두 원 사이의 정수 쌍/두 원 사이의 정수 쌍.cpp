#include <bits/stdc++.h>

using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    long long x4 = 0;
    
    for(long long i=1;i<r2;i++){
        //최대 y 개수에 따라 계산
        x4 += floor(sqrt(pow(r2, 2) - pow(i, 2)));
        //안쪽 원에 들어가는 범위를 제거
        if(i<r1){
            double inner = sqrt(pow(r1, 2) - pow(i, 2));
            //경계값이 들어가는지 확인
            if(inner - (long long)inner == 0) x4++;
            x4 -= floor(inner);
        }
    }
    answer += x4 * 4;
    
    //x, y축 위에 존재하는 개수 더해줌
    answer += (r2-r1+1) * 4;
    
    return answer;
}
