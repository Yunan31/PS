#include <iostream>
#include <vector>

using namespace std;

vector<int> num_A, num_B;

int cal_num(int n, int participant, int who){
    if(n==1) return 0;
    
    //다음 라운드에서 어느 포트에 들어가는지 계산
    int next = (participant+1)/2;
    if(who){
        num_A.push_back(next);
    }
    else{
        num_B.push_back(next);
    }
    
    //다음 라운드 재귀
    cal_num(n/2, next, who);
    
    return 0;
}

int solution(int n, int a, int b)
{
    int answer = 0;
    
    cal_num(n, a, 1);
    cal_num(n, b, 0);
    
    for(int i=0;i<num_A.size();i++){
        //포트가 같으면 정답 출력
        if(num_A[i] == num_B[i]){
            answer = i+1;
            break;
        }
    }

    return answer;
}