#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    vector<int> presum;
    int temp_sum = 0;
    
    presum.push_back(0);
    for(int i=0;i<sequence.size();i++){
        temp_sum += sequence[i];
        presum.push_back(temp_sum);
    }
    
    int min_length = 99999999;
    int st, ed;
    int left = 0, right = 1;
    while(true){
        if(presum[right] - presum[left] < k){
            right++;
        }else if(presum[right] - presum[left] > k){
            left++;
        }else{
            if(right - left - 1 < min_length){
                min_length = right - left - 1;
                st = left;
                ed = right - 1;
            }
            left++;
        }
        
        if(right > sequence.size()) break;
    }
    
    answer.push_back(st);
    answer.push_back(ed);
    
    return answer;
}