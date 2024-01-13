#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stack>
#include <regex>
#include <map>
#include <cstdlib>
#include <list>
#include <sstream>
#include <bitset>
using namespace std;

int n, m, arr[101][71], cnt = 0;
bool visited[101][71], istop;
int dx[8] = { 1,-1,0,0,1,-1,1,-1 };
int dy[8] = { 0,0,1,-1,1,-1,-1,1 };

void bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({ x,y });
    visited[x][y] = 1;

    while (!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        int ch = arr[cx][cy];
        q.pop();

        for (int i = 0; i < 8; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            int nh = arr[nx][ny];

            if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
            if (ch < nh) istop = false;
            if (visited[nx][ny]) continue;
            if (ch == nh)
            {
                visited[nx][ny] = 1;
                q.push({ nx,ny });
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
        }
    }
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (!visited[i][j])
            {
                istop = true;
                bfs(i, j);
                if(istop) cnt++;
            }
        }
    }

    cout << cnt;
};

