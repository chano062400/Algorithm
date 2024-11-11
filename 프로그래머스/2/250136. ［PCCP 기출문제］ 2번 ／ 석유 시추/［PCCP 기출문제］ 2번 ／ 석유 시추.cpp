#include <bits/stdc++.h>

using namespace std;

int dx[] = {1, -1 ,0 ,0};
int dy[] = {0, 0, 1, -1};

int bfs(int x, int y, vector<int>& v, const vector<vector<int>>& land, vector<vector<bool>>& visited)
{
    vector<pair<int,int>> pos;
    vector<bool> check(land[0].size(), 0);
    queue<pair<int,int>> q;
    pos.push_back({x,y});
    q.push({x,y});
    visited[x][y] = true;
    
    int sum = 1;
    while(!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(nx < 0 || nx >= land.size() || ny < 0 || ny >= land[0].size()) continue;
            if(visited[nx][ny] || land[nx][ny] == 0) continue;
            visited[nx][ny] = true;
            ++sum;
            q.push({nx,ny});
            pos.push_back({nx,ny});
        }
    }
    
    for(auto xy : pos) 
    {
        if(!check[xy.second]) 
        {
            check[xy.second] = true;
            v[xy.second] += sum;
        }
    }
    
    return sum;
}

int solution(vector<vector<int>> land) {
    int answer = 0, r = land.size(), c = land[0].size();
    vector<int> v(c);
    vector<vector<bool>> visited(r, vector<bool>(c,0));
    for(int i = 0; i < c; i++)
    {
        for(int j = 0; j < r; j++)
        {
            if(!visited[j][i] && land[j][i] == 1)
            {
                bfs(j, i, v, land, visited);
            }
        }
    }

    for(auto col : v)
    {
        answer = max(answer, col);
    }
    return answer;
}