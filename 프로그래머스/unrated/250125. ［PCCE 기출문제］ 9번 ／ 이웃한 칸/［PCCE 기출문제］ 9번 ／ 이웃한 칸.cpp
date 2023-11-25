#include <string>
#include <vector>
#include <queue>
#include <memory.h>
#include <algorithm>
using namespace std;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int Same[10][10];
bool visited[10][10];


void bfs(vector<vector<string>> board, int x, int y)
{
    int r = board.size();
    int c = board[0].size();
    
    visited[x][y] = 1;
    queue<pair<int,int>> q;
    q.push({x,y});
    
    while(!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        string cur = board[cx][cy];
        q.pop();
        
        for(int i=0; i<4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            
            if(nx >= 0 && nx < r && ny >= 0 && ny < c && !visited[nx][ny])
            {
                if(board[nx][ny] == board[cx][cy])
                {
                    Same[cx][cy] += 1;
                    visited[nx][ny] =1;
                    q.push({nx,ny});
                }
            }
        }
    }
}

using namespace std;
int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0, r = board.size(), c = board[0].size();
    
    memset(Same ,0, sizeof(Same));
    memset(visited,0,sizeof(visited));
   
    bfs(board, h, w);
    
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            answer = max(answer, Same[i][j]);
        }
    }
    
    return answer;
}