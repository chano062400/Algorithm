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
#include <unordered_map>
#include <numeric>
#include <memory>
using namespace std;

int n, m, t, swx, swy, res = 987654321;
int arr[101][101];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
bool visited[101][101];

int bfs(int sx, int sy, int tx, int ty, bool bHasSword)
{
    queue<pair<int,pair<int, int>>> q;
    q.push({ 0,{ sx,sy } });
    visited[sx][sy] = 1;

    while (!q.empty())
    {
        int curdist = q.front().first;
        int cx = q.front().second.first;
        int cy = q.front().second.second;
        q.pop();

        if (cx == tx && cy == ty)
        {
            return  curdist;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && !visited[nx][ny])
            {
                if (!bHasSword && (arr[nx][ny] == 0 || arr[nx][ny] == 2))
                {
                    visited[nx][ny] = 1;
                    q.push({ curdist + 1, {nx,ny} });
                }
                else if(bHasSword)
                {
                    visited[nx][ny] = 1;
                    q.push({ curdist + 1, {nx,ny} });
                }
            }
        }
    }
    return 987654321;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> t;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 2)
            {
                swx = i;
                swy = j;
            }
        }
    }

    int NoSword = bfs(1,1,n,m,false);
    memset(visited, 0, sizeof(visited));
    
    int ToSword = bfs(1,1,swx, swy,false);
    memset(visited, 0, sizeof(visited));
    
    int ToGoal = bfs(swx, swy, n, m,true);

    int HasSword = ToSword + ToGoal;

    if (NoSword > t && HasSword > t)
    {
        cout << "Fail";
    }
    else
    {
        res = min(min(NoSword, HasSword), res);
        cout << res;
    }
}
