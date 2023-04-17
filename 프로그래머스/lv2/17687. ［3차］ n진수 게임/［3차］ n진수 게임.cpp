#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string make_base(int n, int num){
    string result = "";
    int temp, remain;
    while(num > 0){
        remain = num%n;
        if(remain >= 10){
            result += 'A' + remain%10;
        }
        else result += '0' + remain%10;
        
        num = num/n;
    }
    
    reverse(result.begin(), result.end());
    
    return result;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    string saying_numbers = "0";
    int num = 0;
    
    while(saying_numbers.size() < m * t){
        saying_numbers += make_base(n, num);
        num++;
    }
    
    for(int i=0;i<t;i++){
        answer += saying_numbers[i*m + (p-1)];
    }
    
    return answer;
}