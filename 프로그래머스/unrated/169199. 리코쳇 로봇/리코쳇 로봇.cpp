#include <string>
#include <vector>
#include <queue>

using namespace std;

int count[105][105] = {0};
int visit[105][105] = {0};

void bfs(vector<string> board, int R_x, int R_y){
    queue<pair<int, int>> Q;
    vector<pair<int, int>> delta = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
    int x_s = board.size(), y_s = board[0].size();
    
    visit[R_x][R_y] = 1;
    Q.push({R_x, R_y});
    while(!Q.empty()){
        auto f = Q.front();
        Q.pop();
        
        for(auto d : delta){
            int x = f.first + d.first;
            int y = f.second + d.second;
            
            while(x > -1 && x < x_s && y > -1 && y < y_s && board[x][y] != 'D'){
                x += d.first; y += d.second;
            }
            x -= d.first; y -= d.second;
            
            if(visit[x][y]) continue;
            visit[x][y] = 1;
            Q.push({x, y});
            count[x][y] = count[f.first][f.second] + 1;
        }
    }
}

int solution(vector<string> board) {
    int size_x = board.size(), size_y = board[0].size();
    
    int G_x, G_y, R_x, R_y;
    for(int i=0;i<size_x;i++){
        for(int j=0;j<size_y;j++){
            if(board[i][j] == 'G'){
                G_x = i; G_y = j;
            }
            if(board[i][j] == 'R'){
                R_x = i; R_y = j;
            }
        }
    }
    
    bfs(board, R_x, R_y);
    
    if(count[G_x][G_y]) return count[G_x][G_y];
    else return -1;
}