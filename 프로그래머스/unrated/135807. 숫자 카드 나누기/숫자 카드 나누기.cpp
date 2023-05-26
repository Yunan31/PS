#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    int now = 2;
    
    sort(arrayA.begin(), arrayA.end());
    sort(arrayB.begin(), arrayB.end());
    
    int min_num = max(arrayA[0], arrayB[0]);
    
    while(now <= min_num){
        int flag = 1;
        //1. 철수 다나누기, 영희 못나누기
        if(now > arrayA[0]) flag = 0;
        if(flag){
            for(int i=0;i<arrayA.size();i++){
                if(arrayA[i]%now != 0){
                    flag = 0; break;
                }
            }
        }
        if(flag){
            for(int i=0;i<arrayB.size();i++){
                if(arrayB[i]%now == 0){
                    flag = 0; break;
                }
            }
        }
        if(flag){
            answer = now; now++;
            continue;
        }
        
        flag = 1;
        //2. 철수 못나누기, 영희 다나누기
        if(now > arrayB[0]) flag = 0;
        if(flag){
            for(int i=0;i<arrayB.size();i++){
                if(arrayB[i]%now != 0){
                    flag = 0; break;
                }
            }
        }
        if(flag){
            for(int i=0;i<arrayA.size();i++){
                if(arrayA[i]%now == 0){
                    flag = 0; break;
                }
            }
        }
        
        if(flag) answer = now;
        
        now++;
    }
    
    return answer;
}