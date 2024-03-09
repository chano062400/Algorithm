#include <string>
#include <vector>
#include <queue>;
#include "memory.h"
using namespace std;

bool visited[101][101];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int bfs(int x, int y, int tx, int ty, vector<string>& map)
{
    queue<pair<int, pair<int,int>>> q;
    q.push({0,{x,y}});
    visited[x][y] =1;
    
    while(!q.empty())
    {
        int dist = q.front().first;
        int cx = q.front().second.first;
        int cy = q.front().second.second;
        q.pop();
        
        if(cx == tx && cy == ty) return dist;
        
        for(int i=0; i<4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            
            if(nx >= 0 && nx < map.size() && ny >= 0 && ny < map[0].size())
            {
                if(!visited[nx][ny] && map[nx][ny] != 'X')
                {
                    visited[nx][ny] =1;
                    q.push({dist+1,{nx,ny}});
                }
            }
        }
    }
    
    return 0;
}

int solution(vector<string> maps) {
    int answer = 0, answerL = 0, answerE = 0, Sx, Sy,Lx, Ly, Ex, Ey;
    for(int i=0; i<maps.size(); i++)
    {
        for(int j=0; j<maps[i].size(); j++)
        {
            if(maps[i][j] == 'S')
            {
                Sx = i;
                Sy = j;
            }
            if(maps[i][j] == 'L')
            {
                Lx = i;
                Ly = j;
            }
            if(maps[i][j] == 'E')
            {
                Ex = i;
                Ey = j;
            }
        }
    }
    
    answerL = bfs(Sx,Sy,Lx,Ly, maps);
    
    memset(visited,0,sizeof(visited));
    
    if(answerL > 0) answerE += bfs(Lx,Ly,Ex,Ey, maps);
    
    if(answerE > 0) answer = answerL + answerE;
    else answer = -1;
    
    return answer;
}