#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
    int answer = 0;
    
    while(storey > 0){
        int state = storey%10;
        
        //5가 나온 경우 한자리수 앞에 있는 숫자에 대해 보고 판단
        if(state == 5){
            storey/= 10;
            state = storey%10;
            if(state >= 5) {
                state++;
                storey++; 
            }
            answer += 5;
        }
        
        //5를 기점으로 가까운 쪽으로 storey 이동
        if(state < 5){
            storey -= state;
            answer += state;
        }
        else{
            storey += 10 - state;
            answer += 10 - state;
        }
        
        storey /= 10;
    }
    
    return answer;
}