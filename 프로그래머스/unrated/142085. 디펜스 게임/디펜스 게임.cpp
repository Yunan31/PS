#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = enemy.size();
    priority_queue<int> pq;
    long long sum = 0;
    for(int i=0;i<enemy.size();i++){
        pq.push(enemy[i]);
        sum += enemy[i];
        if(sum > n && k){
            sum -= pq.top();
            pq.pop();
            k--;
        }
        if(sum > n){
            answer = i;
            break;
        }
    }
    
    return answer;
}