#include <vector>

using namespace std;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int dfs(int x, int y, int prevcolor, const vector<vector<int>>& picture, vector<vector<bool>>& visited)
{
    int cnt = 1;
    visited[x][y] = true;
    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= picture.size() || ny < 0 || ny >= picture[0].size()) continue;
        if(visited[nx][ny] || picture[nx][ny] != prevcolor) continue;
        
        cnt += dfs(nx, ny, picture[x][y], picture, visited);
    }
    return cnt;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int num_area = 0;
    int max_area = 0;
    
    vector<int> answer(2);
    
    vector<vector<bool>> visited(m, vector<bool>(n,0));
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(!visited[i][j] && picture[i][j] != 0)
            {
                num_area++;
                max_area = max(max_area, dfs(i, j, picture[i][j], picture, visited));
            }
        }
    }
    
    answer[0] = num_area;
    answer[1] = max_area;
    
    return answer;
}