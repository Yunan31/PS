#include <bits/stdc++.h>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    int cnt[10000005] = {0};
    vector<pair<int, int>> sorted;
    
    for(int n:tangerine){
        cnt[n]++;
    }
    
    for(int i=0;i<10000005;i++){
        if(cnt[i] > 0){
            sorted.push_back({-cnt[i], i});
        }
    }
    
    sort(sorted.begin(), sorted.end());
    
    int pick = 0;
    for(int i=0;i<sorted.size();i++){
        pick+= -sorted[i].first;
        answer++;
        if(pick >= k) break;
    }
    
    return answer;
}