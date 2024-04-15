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

int n, m, res = 0;
int arr[251][251];
bool visited[251][251];
int dx[] = {1,1,1,0,0,-1,-1,-1};
int dy[] = { -1,0,1,-1,1,-1,0,1 };
 
void bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({ x,y });
    visited[x][y] = 1;
    
    while (!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && !visited[nx][ny] && arr[nx][ny])
            {
                q.push({ nx,ny });
                visited[nx][ny] = 1;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;

    for(int i=1; i<=n; i++)
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
            if (!visited[i][j] && arr[i][j])
            {
                bfs(i, j);
                res++;
            }
        }
    }
    cout << res;
}
