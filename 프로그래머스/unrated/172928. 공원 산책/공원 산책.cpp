#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    int x, y;
    int x_size = park.size();
    int y_size = park[0].size();
    
    for(int i=0;i<x_size;i++){
        for(int j=0;j<y_size;j++){
            if(park[i][j] == 'S'){
                x = i;
                y = j;
            }
        }
    }
    
    for(int i=0;i<routes.size();i++){
        int moves = routes[i][2] - 48;
        char dir = routes[i][0];
        int count = 0;
        if(dir == 'E' && y+moves < y_size){
            for(int k=1;k<=moves;k++){
                if(park[x][y+k] == 'X') break;
                else count++;
            }
            if(count == moves) y = y+moves;
        }
        else if(dir == 'W' && y-moves >= 0){
            for(int k=1;k<=moves;k++){
                if(park[x][y-k] == 'X') break;
                else count++;
            }
            if(count == moves) y = y-moves;
        }
        else if(dir == 'N' && x-moves >= 0){
            for(int k=1;k<=moves;k++){
                if(park[x-k][y] == 'X') break;
                else count++;
            }
            if(count == moves) x = x-moves;
        }
        else if(dir == 'S' && x+moves < x_size){
            for(int k=1;k<=moves;k++){
                if(park[x+k][y] == 'X') break;
                else count++;
            }
            if(count == moves) x = x+moves;
        }
    }
    
    answer.push_back(x);
    answer.push_back(y);
    
    return answer;
}