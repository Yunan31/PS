#include <string>
#include <vector>
#include <queue>

using namespace std;

int visit[105] = { 0 };

int dfs(vector<int> cards, int num){
    if(visit[num] == 0){
        visit[num] = 1;
        //상자의 개수를 재귀로 return
        //cards[num] - 1 -> 상자의 번호는 num+1 이므로
        return dfs(cards, cards[num]-1) + 1;
    }
    else return 0;
}

int solution(vector<int> cards) {
    int answer = 0;
    priority_queue<int> pq;
    
    //순차적으로 그룹을 분할
    for(int i=0;i<cards.size();i++){
        pq.push(dfs(cards, i));
    }
    
    //priority_queue에서 제일 위의 두개를 뽑아 곱해줌
    if(pq.size() != 1){
        answer += pq.top();
        pq.pop();
        answer *= pq.top();
    }
    
    return answer;
}