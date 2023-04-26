#include <bits/stdc++.h>

using namespace std;

bool compare(vector<int> i, vector<int> j){
    return i[1] < j[1];
}

int solution(vector<vector<int>> targets) {
    stack<vector<int>> missile;
    
    //미사일 끝범위를 오름차순으로 정렬
    sort(targets.begin(), targets.end(), compare);
    
    missile.push(targets[0]);
    for(int i=1;i<targets.size();i++){
        vector<int> top = missile.top();
        //겹치는 부분이 존재하는지 확인 후 스택에 넣어줌
        if(top[1] <= targets[i][0]){
            missile.push(targets[i]);
        }
    }
    
    return missile.size();
}
