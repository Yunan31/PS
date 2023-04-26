#include <bits/stdc++.h>

using namespace std;

bool compare(vector<int> i, vector<int> j){
    return i[1] < j[1];
}

int solution(vector<vector<int>> targets) {
    stack<vector<int>> missile;
    
    sort(targets.begin(), targets.end(), compare);
    
    missile.push(targets[0]);
    for(int i=1;i<targets.size();i++){
        vector<int> top = missile.top();
        if(top[1] <= targets[i][0]){
            missile.push(targets[i]);
        }
    }
    
    return missile.size();
}