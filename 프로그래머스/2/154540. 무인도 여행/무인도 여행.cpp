#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool visited[101][101] = {0,};
int row, col, sum =0;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

void bfs(int x, int y, vector<string>& maps)
{
    queue<pair<int,int>> q;
    q.push({x,y});
    visited[x][y] = 1;
    sum += maps[x][y] - '0';
    
    while(!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            
            if(nx >= 0 && nx < col && ny >= 0 && ny < row && !visited[nx][ny] && maps[nx][ny] != 'X')
            {
                visited[nx][ny] = 1;
                q.push({nx,ny});
                sum += maps[nx][ny] - '0';
            }
        }
    }
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    row = maps[0].size(), col = maps.size();
    for(int i=0; i<maps.size(); i++)
    {
        for(int j=0; j<maps[0].size(); j++)
        {
            if(maps[i][j] != 'X' && !visited[i][j])
            {
                sum = 0;
                bfs(i,j,maps);
                answer.push_back(sum);
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    if(answer.empty()) answer.push_back(-1);
    
    return answer;
}