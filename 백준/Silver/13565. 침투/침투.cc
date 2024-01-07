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

int arr[1001][1001];
bool visited[1001][1001], connect = false;
int m, n;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

bool bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({ x,y });
    visited[x][y] = 1;

    while (!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        if (cx == 1) return true;

        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx >= 1 && nx <= m && ny >= 1 && ny <= n && !visited[nx][ny] && arr[nx][ny] == 0)
            {
                q.push({ nx,ny });
                visited[nx][ny] = 1;
            }
        }
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> m >> n;
    for (int i = 1; i <= m; i++)
    {
        string str;
        cin >> str;
        for (int j = 1; j <= n; j++)
        {
            arr[i][j] = str[j - 1] - '0';
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (bfs(m, i))
        {
            cout << "YES" << '\n';
            connect = 1;
            break;
        }
        memset(visited, 0, sizeof(visited));
    }

    if(!connect) cout << "NO" << '\n';
}
