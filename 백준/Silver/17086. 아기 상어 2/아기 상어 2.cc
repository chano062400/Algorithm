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

int n, m, res = 0;
int arr[51][51];
bool visited[51][51];
int dx[8] = { 1,-1,0,0,1,-1,1,-1 };
int dy[8] = { 0,0,1,-1,1,-1,-1,1 };

int bfs(int x, int y)
{
    queue<pair<int,pair<int, int>>> q;
    q.push({ 0,{ x,y }});
    visited[x][y] = 1;

    while (!q.empty())
    {
        int cx = q.front().second.first;
        int cy = q.front().second.second;
        int cb = q.front().first;
        q.pop();

        if (arr[cx][cy] == 1) return cb;
        for (int i = 0; i < 8; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && !visited[nx][ny])
            {
                q.push({ cb + 1,{ nx,ny } });
                visited[nx][ny] = 1;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    vector<pair<int,int>> shark;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 1) shark.push_back({ i,j });
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (arr[i][j] == 0)
            {
                memset(visited, 0, sizeof(visited));
                res = max(res, bfs(i,j));
            }
        }
    }

    cout << res;
};

