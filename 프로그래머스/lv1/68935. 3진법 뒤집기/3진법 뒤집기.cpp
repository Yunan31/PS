#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> num_three;
    
    while(n){
        num_three.push_back(n%3);
        n/=3;
    }
    
    for(int i=0;i<num_three.size();i++){
        if(i==0) answer += num_three[num_three.size()-1];
        else{
            answer += num_three[num_three.size()-(i+1)] * pow(3, i);
        }
    }
    
    return answer;
}