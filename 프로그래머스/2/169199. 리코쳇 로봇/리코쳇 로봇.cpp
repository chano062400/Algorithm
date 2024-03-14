#include <string>
#include <vector>
#include <queue>
using namespace std;

bool visited[101][101];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int bfs(int x, int y, vector<string>& board)
{
    queue<pair<int,pair<int,int>>> q;
    q.push({0,{x,y}});
    visited[x][y] = true;

    while(!q.empty())
    {
        int curcnt = q.front().first;
        int cx = q.front().second.first;
        int cy = q.front().second.second;
        q.pop();
        
        if(board[cx][cy] == 'G') return curcnt;
        
        for(int i=0; i<4; i++)
        {
            int nx = cx, ny = cy;

            while(1)
            {
                nx = nx + dx[i];
                ny = ny + dy[i];
                
                if(nx < 0 || nx >= board.size() || ny < 0 || ny >= board[0].length() || board[nx][ny] == 'D') 
                    break;
            }
            
            nx = nx - dx[i];
            ny = ny - dy[i];
            
            if(visited[nx][ny]) continue;
            
            visited[nx][ny] = true;
            q.push({curcnt+1, {nx,ny}});
            
        }
    }
    
    return -1;
}

int solution(vector<string> board) {
    int answer = 0;
    for(int i=0; i<board.size(); i++)
    {
        for(int j=0; j<board[i].length(); j++)
        {
            if(board[i][j] == 'R')
            {
                answer = bfs(i,j,board);
            }
        }
    }
    return answer;
}