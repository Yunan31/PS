#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> topping) {
    int left[1000005], right[1000005];
    int answer = 0;
    vector<int> kind_left, kind_right;
    
    //왼쪽 순서대로 종류 배열에 담기
    for(int i=0;i<topping.size();i++){
        if(find(kind_left.begin(), kind_left.end(), topping[i]) == kind_left.end()){
            kind_left.push_back(topping[i]);
        }
        left[i] = kind_left.size();
    }
    
    //오른쪽 순서대로 종류 배열에 담기
    for(int i=topping.size()-1;i>=0;i--){
        if(find(kind_right.begin(), kind_right.end(), topping[i]) == kind_right.end()){
            kind_right.push_back(topping[i]);
        }
        right[i] = kind_right.size();
    }
    
    //left와 right 확인해가며 answer++
    for(int i=0;i<topping.size()-1;i++){
        if(left[i] == right[i+1]) answer++;
    }
    
    return answer;
}