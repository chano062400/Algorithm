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
#include <set>
using namespace std;

int arr[1001][1001];
int dist[1001][1001];
bool visited[1001][1001];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int n, m;

void bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({ x,y });
    visited[x][y] = 1;
    dist[x][y] = 0;

    while (!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        int curdist = dist[cx][cy];
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            int nextdist = curdist + 1;

            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && !visited[nx][ny] && arr[nx][ny] != 0)
            {
                visited[nx][ny] = 1;
                dist[nx][ny] = nextdist;
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

    memset(dist, 0, sizeof(dist));
    memset(visited, 0, sizeof(visited));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (arr[i][j] == 2)
            {
                bfs(i, j);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (arr[i][j] == 1 && dist[i][j] == 0) cout << -1 << " ";
            else cout << dist[i][j] << " ";
        }
        cout << '\n';
    }

    
};

