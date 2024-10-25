#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
char arr[501][501];
bool visited[2001][2001][4];

int getdir(int x, int y, int dir)
{
    if(arr[x][y] == 'S') return dir;
    if(arr[x][y] == 'L')
    {
        if(dir == 0) return 2;
        if(dir == 1) return 3;
        if(dir == 2) return 1;
        if(dir == 3) return 0;
    }
    else if(arr[x][y] == 'R')
    {
        if(dir == 0) return 3;
        if(dir == 1) return 2;
        if(dir == 2) return 0;
        if(dir == 3) return 1;
    }
}

struct info
{
    int x, y, dir, cnt;
};
    
vector<int> solution(vector<string> grid) {
    vector<int> answer;
    int lx = grid.size(), ly = grid[0].length();
    
    for (int i = 0; i < lx; i++)
        for (int j = 0; j < ly; j++)
            arr[i][j] = grid[i][j];

    for (int i = 0; i < lx; i++)
    {
        for (int j = 0; j < ly; j++)
        {
            for (int dir = 0; dir < 4; dir++)
            {
                if (!visited[i][j][dir])
                {
                    int cnt = 0;
                    int x = i, y = j, d = dir;
                    while (true)
                    {
                        if (visited[x][y][d]) break;
                        visited[x][y][d] = true;
                        cnt++;

                        d = getdir(x, y, d);
                        x = (x + dx[d] + lx) % lx;
                        y = (y + dy[d] + ly) % ly;
                    }
                    if (cnt > 0) answer.push_back(cnt);
                }
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}
