#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    stack<int> st;
    
    int cur = 0, box = 1;
    while(cur < order.size()){
        if(box <= order[cur]){
            while(box <= order[cur]){
                st.push(box);
                box++;
            }
        }
        if(!st.empty() && st.top() == order[cur]){
            answer++;
            st.pop();
            cur++;
        }
        else break;
    }
    
    return answer;
}